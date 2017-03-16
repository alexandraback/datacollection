#include <iostream>
#include <cstdio>
#include <stack>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
#include <map>
//#include <unordered_map>
//#define lson x<<1
//#define rson x<<1|1
//#define mid ((lt[x].l+lt[x].r)/2)
//#define ID(x, y) ((x)*m+(y))
//#define CHECK(x, y) ((x)>=0 && (x)<n && (y)>=0 && (y)<m)
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int INF=0x3f3f3f3f;
void Open()
{
    #ifndef ONLINE_JUDGE
        freopen("C-small-attempt1.in","r",stdin);
        freopen("C-small-attempt1.out","w",stdout);
    #endif // ONLINE_JUDGE
}

string l[22];//
string r[22];//
map<string, int> ml, mr;//
int L[22];//
int R[22];//
int dp[1 << 17];//
bool vl[17];//
bool vr[17];//
int main()
{
//    Open();
//    cout<<__builtin_ctz(8)<<endl;
    int T;
    scanf("%d", &T);
    int cas = 1;
    while(T--)
    {
        memset(dp, 0, sizeof(dp));
        int tl = 0, tr = 0;
        int n;
        scanf("%d", &n);
        ml.clear();
        mr.clear();
        for(int i = 0; i < n; i++) {
            cin >> l[i] >> r[i];
            if(ml.find(l[i]) == ml.end()) ml[l[i]] = tl++;
            if(mr.find(r[i]) == mr.end()) mr[r[i]] = tr++;
            L[i] = ml[l[i]];
            R[i] = mr[r[i]];
        }
        int limit = 1 << n;
        int ans = 0;
        for(int s = 1; s < limit ; s++)
        {
            int tmp = s;
            while(tmp)
            {
                int curs = s - (tmp & -tmp);
                memset(vl, 0, sizeof(vl));
                memset(vr, 0, sizeof(vr));
                for(int i = 0; i < n; i++)
                {
                    if(curs & (1 << i)){
                        vl[L[i]] = 1;
                        vr[R[i]] = 1;
                    }
                }
                int idx = __builtin_ctz(tmp);
                bool isfa = vl[L[idx]] && vr[R[idx]];
                dp[s] = max(dp[s], dp[curs] + isfa);
                ans = max(ans, dp[s]);
                tmp = tmp - (tmp & -tmp);
            }
        }

//        cerr<<cas<<endl;
        printf("Case #%d: ", cas++);
        printf("%d\n", ans);
//        printf("%d %d %d\n", dif, mic, mij);
//        printf("%s %s\n", C, J);
    }
    return 0;
}
