#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

#define FOR(i,a,b) for(int i = (a); i <= (b);i++)
#define FR(i,a) for(int i = 0; i < (a); i++)
#define DOWN(i,a,b) for(int i = (a); i >= (b); i--)

using namespace std;
int A,B,K;
int main() 
{
    freopen("Bsmall.in","r",stdin);
    freopen("B.out","w",stdout);
    int ntest;
    cin >> ntest;
    FOR(test,1,ntest) {
        cout << "Case #" << test << ": ";
        cin >> A >> B >> K;
        int res = 0;
        FR(i,A) FR(j,B) {
            int t = i & j;
            if (t < K) res++;
        }
        cout << res << endl;
    }
    return 0;
}
