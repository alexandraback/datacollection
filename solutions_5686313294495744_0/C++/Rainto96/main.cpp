/*
*Rainto96
*Beijing University of Posts and Telecommunications School of Software Engineering
*http://blog.csdn.net/u011775691
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstring>
#include <string>
#include <cmath>
#include <set>
#include <map>
#include <vector>
#include <climits>
using namespace std;
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define VINT vector<int>
#define PII pair<int,int>
#define MP(x,y) make_pair((x),(y))
#define ll long long
#define ull unsigned long long
#define MEM0(x)  memset(x,0,sizeof(x))
#define MEM(x,val) memset((x),val,sizeof(x))
#define scan(x) scanf("%d",&(x))
#define scan2(x,y) scanf("%d%d",&(x),&(y))
#define scan3(x,y,z) scanf("%d%d%d",&(x),&(y),&(z))
#define scan4(x,y,z,k) scanf("%d%d%d%d",&(x),&(y),&(z),&(k))
#define Max(a,b) a=max(a,b)
#define Min(a,b) a=min(a,b)
#define fuck(x) cout<<#x<<" - "<<x<<endl

string l[22];//
string r[22];//

int dp[1 << 17];//
bool vlt[17];//
bool vrt[17];//

int get(map<string,int>& mp, string x, int& ID){
    if(mp.find(x) == mp.end()) {
        mp[x] = ID++;
        return ID-1;
    }else
        return mp[x];
}

int main()
{
    //freopen("C-small-attempt0.in","r",stdin);
    //freopen("C-small-attempt0.out","w",stdout);
    int T;
    scanf("%d", &T);
    for(int cas = 1;cas<=T;cas++)
    {
        map<string, int> ml, mr;//
        int L[22];//
        int R[22];//
        memset(dp, 0, sizeof(dp));
        int tl = 0, tr = 0;
        int n;
        scanf("%d", &n);
        for(int i = 0; i < n; i++) {
            cin >> l[i] >> r[i];
            L[i] = get(ml,l[i],tl);
            R[i] = get(mr,r[i],tr);
        }
        int ans = 0;
        for(int s = 1; s < (1 << n) ; s++)
        {
            for(int j=0;j<n;j++)
            {
                int curs;
                if(s&(1<<j)){
                    curs = s^(1<<j);
                    for(int i = 0; i < n; i++)
                    {
                        if(curs & (1 << i)){
                            vlt[L[i]] = 1;
                            vrt[R[i]] = 1;
                        }
                    }

                    bool isfa = vlt[L[j]] && vrt[R[j]];
                    dp[s] = max(dp[s], dp[curs] + isfa);
                    ans = max(ans, dp[s]);

                    for(int i = 0; i < n; i++)
                    {
                        if(curs & (1 << i)){
                            vlt[L[i]] = 0;
                            vrt[R[i]] = 0;
                        }
                    }
                }
            }
        }
        printf("Case #%d: ", cas);
        printf("%d\n", ans);
    }
    return 0;
}
