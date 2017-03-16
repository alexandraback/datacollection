#include <cstdlib>
#include <climits>
#include <cstdio>
#include <cstring>
#include <cmath>

// STL
#include <sstream>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map> // contains multimap
#include <set> // contains multiset
#include <queue> // contains priority_queue
#include <deque>
#include <list>
#include <stack>

using namespace std;

typedef unsigned long long ul;
typedef long long ll;

#define SIZE 20

int N, X, Y;

double solve(int r, int i, int j, bool** pred) {
    bool** pos = new bool*[40];
    for (int l=0; l<40;++l){
        pos[l] = new bool[20];
        for (int k=0; k<20;++k){
            if (pred == NULL) pos[l][k]=false;
            else pos[l][k]=pred[l][k];
        }
    }

    for (int k=0; k<r; ++k) {
        while (j>0 && (!pos[i-1][j-1] || !pos[i+1][j-1])) {
            if (pos[i-1][j-1]) ++i;
            else if (pos[i+1][j-1]) --i;
            else if (pos[i][j-2]) {
                //cout << k << pos[20][0] << "   " << i << "   " << j << endl;
                return .5*solve(r-k,i-1,j-1,pos) + .5*solve(r-k,i+1,j-1,pos);
            }
            --j;
        }
        //cout << i << "   " << j << endl;
        if (i-20 == X && j == Y) return 1.;
        pos[i][j] = true;
        i=20; j=19;
    }
    return 0;
}


int main() {
    int numcase;

    freopen("B-small-attempt0.in", "r", stdin);
    freopen("B-small.out", "w", stdout);
    //freopen("B-large.in", "r", stdin);
    //freopen("B-large.out", "w", stdout);

    cin >> numcase;
    for (int i = 0; i < numcase; ++i) {
        cin >> N >> X >> Y;
        printf ("Case #%d: %4.6f\n", i+1,solve(N,20,19,NULL));
    }

    return 0;
}
