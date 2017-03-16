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

bool Judge(int n,string s){
    int len=s.length();
    char ss[10];
    sprintf(ss,"%d",n);
    string ts(ss); while(ts.length()<len) ts.insert(0,"0");
    if(ts.length()>len) return false;
    rep(i,0,len-1) if(s[i]!='?' && s[i]!=ts[i]) return false;
    return true;
}

int main(){//IN;OUT;
    int T; cin>>T;
    rep(kase,1,T){
        string a,b; cin>>a>>b; //cout<<a<<" "<<b<<endl;
        int len=a.length();
        printf("Case #%d: ",kase);
            int Min=INF,l,r;
            for(int x=0;x<=999;x++) if(Judge(x,a))
                for(int y=0;y<=999;y++) if(Judge(y,b))
                    if(abs(x-y)<Min) { Min=abs(x-y); l=x; r=y; }
            char s[10],ss[10];
            sprintf(s,"%03d",l); sprintf(ss,"%03d",r);
            printf("%s %s\n",&s[3-len],&ss[3-len]);
    }
}
