#include <algorithm>
#include <vector>
#include <queue>
#include <cstdio>
#include <string>
#include <cassert>
#include <iostream>
using namespace std;

int outdent(int w, int h) {
    int total = 0;
    for (int x=0; x<h; x++) {
        w-=2;
        total += w;
    }
    return total;
}

int main() {
    int T = 0;
    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        printf("Case #%d: ", t);

        //cout << endl;

        int N, M, K;
        scanf(" %d %d %d", &N, &M, &K);
        if (N<M) swap(N,M);


        // try different strategies

        // trivial: place K stones
        int best = K;

        // special case small number
        if (K<4) {
            printf("%d\n", best);
            continue;
        }

        // special case narrow field
        if (N<=2 || M<=2) {
            printf("%d\n", best);
            continue;
        }

        // try placing a linear row (height 1)
        for (int i=3; i<=N; i++) {
            for (int k=0; k<=4; k++) {
                if (3*i-4+k==K) {
                    int here = 2*i-2+k;
                    //cout << "row says " << here << endl;
                    best = min(best, here);
                }
            }
        }

        // try placing a square
        for (int i=3; i<=M; i++) {
            for (int k=0; k<=4; k++) {
                if (i*i-4+k==K) {
                    int here = 4*(i-2)+k;
                    //cout << "square says " << here << endl;
                    best = min(best, here);
                }
            }
        }

        // try placing a rectangle of various width/height
        for (int w=3; w<N; w++) {
            for (int h=max(3,K/w-5); h<=min(K/w+5,M); h++) {
                int a = w*h-4;
                int ex = a-K;
                if (ex<0) continue;
                if (ex==0) {
                    int here = 2*(w-2) + 2*(h-2);
                    //cout << "rectangle says " << here << endl;
                    best = min(best, here);
                } else if (ex < w-2 || ex < h-2) {
                    int here = 2*(w-2) + 2*(h-2) -1;
                    //cout << "cut rectanlge says " << here << endl;
                    best = min(best, here);
                }
            }
        }

        /*
        // try placing a platted rhomboid
        for (int w=3; w<=N; w++) {
            for (int above=1; above<=(w-1)/2; above++) {
                int below = min(M-1-above, (w-1)/2);
                if (below<1) continue;

                int capacity = w;
                capacity -= above*(above+1);
                capacity -= below*(below+1);
                if (capacity>=K) {
                    int here = 2*w-2;
                    cout << "platted rhomboid says " << here << endl;
                    best = min(best, here);
                }
            }
        }
        */

        for (int w=3; w<=N; w++) {
            for (int h=3; h<=M; h++) {
                int capacity = w*h; // the inside part
                int above = (M-h)/2;
                int below = M-h-above;
                int left = (N-w)/2;
                int right = N-w-left;

                //cout << above << " " << below << " " << left << " " << right;

                capacity += outdent(w, above);
                capacity += outdent(w, below);
                capacity += outdent(h, left);
                capacity += outdent(h, right);

                //cout << "rhomb " << w << "x" << h << " cap=" << capacity<< endl;

                for (int k=0; k<=4; k++) {
                    if (capacity+k >= K) {
                        best = min(best, 2*w+2*h-4+k);
                    }
                }
            }
        }

        // try placing a full width rectangle
        if (K>=N*M-4) {
            for (int k=0; k<=4; k++) {
                if (N*M-4+k == K) {
                    int here = 2*(N-2)+2*(M-2)+k;
                    //cout << "full board says " << here;
                    best = min(best, here);
                }
            }
        }

        // special case corners required

        printf("%d\n", best);
    }
}

// vim: set ff=unix ai tw=80 ts=4 sts=4 sw=4 et:
