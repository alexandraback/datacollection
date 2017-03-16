#include<cstdio>
#include<cctype>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<iostream>
#include<complex>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<deque>
#include<stack>
#include<algorithm>
#include<utility>
#include<list>
#include<bitset>
using namespace std;


#define LL long long
#define LLu unsigned long long
#define LL_ __int64
#define rep(i,j,k) for(int i=(j);i<=(k);i++)
#define repp(i,j,k) for(int i=(j);i>=(k);i--)
#define Add(u,v,w) {E[++tot]=(Edge){u,v,w,Last[u]}; Last[u]=tot;}
#define mst(i,j) memset(i,j,sizeof(i))
#define scf(i) scanf("%d",&(i))
#define scff(i,j) scanf("%d%d",&(i),&(j))
#define scfs(i) scanf("%s",(i))
#define pdd pair<double,double>
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define bs binary_search
#define pq priority_queue
#define vec vector
#define bt bitset
#define bgn begin
#define ist insert
#define fst first
#define scd second
#define it iterator

#define pi acos(-1.0)
#define INF 0x7fffffff
#define eps 1e-5
#define IN freopen("In.txt","r",stdin)
#define OUT freopen("Out.txt","w",stdout)
#define CMP system("comp In.txt Out.txt")
#define MOD 1000000007
#define maxn 100010
#define maxm 300010


string N[]={"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
int M[]={6,0,8,2,4,3,5,7,1,9};
string k="XZGWUHFVOI";
int cnt[30];
int ans[20];

void solve(int n){
    ans[M[n]]=cnt[k[n]-'A'];
    int len=N[M[n]].length();
    rep(i,0,len-1) cnt[N[M[n]][i]-'A']-=ans[M[n]];
}

int main(){//IN;OUT;
    int T; cin>>T; int kase=1;
    while(T--){
        string s; cin>>s;
        int len=s.length();
        mst(cnt,0); rep(i,0,len-1) cnt[s[i]-'A']++;
        mst(ans,0);
        printf("Case #%d: ",kase++);
        for(int i=0;i<10;i++) solve(i);
        rep(i,0,9) rep(j,0,ans[i]-1) printf("%d",i);
        puts("");
    }
    return 0;
}
