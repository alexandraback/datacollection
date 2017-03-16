

#include<stdio.h>
#include<iostream>
#include<vector>
#include<string.h>
#include<algorithm>
#include<deque>
#include<map>
#include<set>
#include<stdlib.h>
#include<math.h>
#include<queue>
#include<stack>
#include<functional>
using namespace std;
#define LL long long
#define si(x) scanf("%d",&x)
#define sc(x) scanf("%c",&x)
#define sl(x) scanf("%I64d",&x)
#define prl(x) printf("%I64d",x)
#define pri(x) printf("%d\n",x)
#define prs(x) printf("%s\n",x)
typedef pair<int, int> ii;
typedef pair<LL, LL> iil;
typedef pair<LL, iil> iiil;
typedef pair<ii, int> iii;
typedef pair<ii, ii> iiii;
#define vl vector<ll>
#define vi vector<int>
#define vii vector<ii>
#define vvl vector< vl >
#define vvi vector< vi >
#define vvii vector< vii >
#define pb push_back
#define mem(x,y) memset(x,y,sizeof(x))
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define mod 1000000007
#define pb push_back

const int  maxn  = 400000;
const int INF  = 10000008;
//const LL INF = 0x0123456789ABCDEFLL;
bool p[50];
bool check(int v , int a[]){
    vector<int> c;
    for(int i=1;i<=v;i++){
        if(a[i] > 0){
            c.pb(i);
        }
    }
    rep(i,0,45)p[i] = false;
    //   if(c.size() > 5) return  false;
    int mask = pow(2 , c.size());
    for(int i=0;i<mask;i++){
        int s  = 0;
        for(int j=0;j<c.size();j++){
            if(i & (1<<j)){
                s+=c[j];
            }
        }
        p[s] = 1;
    }
    for(int i=1;i<=v;i++) if(!p[i]){
        return  false;
    }
    return  true;
}
inline void solve(void){
    int t;
    cin >> t;
    int t1 = 1;
    while(t--){
        int c , d , v;
        cin >> c >> d >> v;
        int den[40];
        int cc[40]={0};
        for(int i=0;i < d;i++){
            cin >> den[i];
            cc[den[i]]++;
        }
        int ans = 5;
        for(int i=1;i<=v;i++){
            for(int j=1;j<=v;j++){
                for(int k=1;k<=v;k++){
                    for(int m=1;m<=v;m++){
                        int cnt[50]={0};
                        cnt[i]++;cnt[j]++;
                        cnt[k]++;cnt[m]++;
                        rep(mm,0,d)cnt[den[mm]]++;
                        if(check(v, cnt)){
                            int c = 0;
                            for(int jj=1;jj<=v;jj++){
                                if(cnt[jj] > 0 && cc[jj] == 0){
                                    c++;
                                }
                            }
                            ans  = min(ans  , c);
                        }
                    }
                }
            }
            
        }
        cout<<"Case #"<<t1 <<": "<< ans <<endl;
        t1++;
    }
}
/*void init() {
 ios::sync_with_stdio(false);
 cin.tie(nullptr);
 }*/
int main(int argc, const char * argv[]){
    //   init();
    solve();
    return 0;
}
