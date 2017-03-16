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
#define maxn 10000
int n;
bool dd[maxn];
long double a[maxn], b[maxn];
bool a_avail[maxn], b_avail[maxn];
vector<double> A,B;
int main() 
{
    freopen("D4.in","r",stdin);
    freopen("D.out","w",stdout);
    int ntest;
    cin >> ntest;
    FOR(test,1,ntest) {
        cout << "Case #" << test << ": ";
        cin >> n;
        FOR(i,1,n) cin >> a[i];
        FOR(i,1,n) cin >> b[i];
        sort(a+1,a+n+1);
        sort(b+1,b+n+1);
        int res2 = 0;
        memset(dd,true,sizeof(dd));
        FOR(i,1,n) {
            bool win = true;
            FOR(j,1,n)
            if (dd[j] && b[j] >= a[i]) {
                dd[j] = false;
                win = false;
                break;
            }
            if (win) res2++;
        }
        memset(a_avail,true,sizeof(a_avail));
        memset(b_avail,true,sizeof(b_avail));
        int res = 0;
        while (true) {
            bool can_stop = true;
            A.clear(); B.clear();
            FOR(i,1,n) if (a_avail[i]) A.push_back(a[i]);
            FOR(i,1,n) if (b_avail[i]) B.push_back(b[i]);
            FR(i,A.size()) if (A[i] < B[i]) can_stop = false;
            if (can_stop) {
                res += A.size();
                break;
            }
            int id = -1;
            DOWN(i,n,1) 
            if (b_avail[i]) {
                id = i;
                break;
            }
            if (id == -1) break;
            bool win = true;
            int id_a = -1;
            FOR(i,1,n)
            if (a_avail[i] && a[i] < b[id]) {
                a_avail[i] = false;
                b_avail[id] = false;
                win = false;
                break;
            }
            if (win) res++;
        }
        cout << res << " " << res2 << endl;
    }
    return 0;
}
