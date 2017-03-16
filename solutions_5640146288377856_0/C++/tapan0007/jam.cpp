
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

inline void solve(void){
    int t;
    cin >> t;
    int t1 = 1;
    while(t--){
        int r ,c ,w ;
        cin >> r >> c >> w;
        c = r*c;
        int lim;
        
        if(c%w==0) lim = c/w-1;
        else lim = c/w;
        cout <<"Case #"<<t1<<": "<<lim+w<<endl;
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
