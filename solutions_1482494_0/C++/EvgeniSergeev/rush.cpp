#include <cstdio>
#include <iostream>
#include <algorithm>
#include <functional>
#include <map>
#include <vector>
#include <set>
#include <queue>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <sstream>
using namespace std;

#define MP make_pair
#define SS size()
#define PB push_back
#define ff(a, b) for (int a = 0; a < int(b); ++a)
#define f1(a, b) for (int a = 1; a < int(b); ++a)
#define ii(n)    ff(i, n)
#define FF first
#define CC second
#define BB begin()
#define EE end()
#define all(x)  (x).BB, (x).EE
#define ite(v)   typeof((v).BB)
#define fe(i, v) for(ite(v) i = (v).BB; i != (v).EE; ++i)

#define err(...)    { fprintf(stderr, __VA_ARGS__); fflush(stderr); }

typedef long long LL;
typedef pair<int, int> pii;

#define MOD (LL)


int main() {
    int T;
    cin >> T;

    for (int tcase = 1; tcase <= T; ++tcase) {
        int N;
        cin >> N;
        vector<bool> doneOne(N, false);
        vector<bool> doneTwo(N, false);
        priority_queue<pair<int, int> > two;
        vector<int> one(N, 0);
        vector<int> two2(N, 0);
        ii (N) {
            int A, B;
            cin >> A >> B;
            two.push(MP(-B, i));
            one[i] = A;
            two2[i] = B;
        }

        int levels = 0;
        int stars = 0;
        while (stars < 2*N) {
            pii easiest2 = two.top();
            if (abs(easiest2.FF) <= stars) {
                two.pop();
                levels++;
                if (doneOne[easiest2.CC])
                    stars += 1;
                else
                    stars += 2;
                doneTwo[easiest2.CC] = true;
                doneOne[easiest2.CC] = true;
                continue;
            } else {
                int best = -1;
                ii (N)
                if (!doneOne[i]) {
                    if (one[i] <= stars) {
                        if (-1 == best || two2[best] < two2[i])
                            best = i;
                    }
                }
                if (-1 == best)
                    break;
                doneOne[best] = true;
                levels++;
                stars++;
            }
        }

        printf("Case #%d: ", tcase);
        if (stars == 2*N) {
            printf("%d\n", levels);
        } else {
            printf("Too Bad\n");
        }
    }

    return 0;
}






