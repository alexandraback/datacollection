#include<bits/stdc++.h>
using namespace std;
#define FZ(i,n) for(int i=0;i<(n);i++)
#define FB(i,n) for(int i=(n)-1;i>=0;i--)
#define FV(i,st,ed) for(int i=(st);i<(ed);i++)
#define SZ(x) ((int)x.size())
#define ALL(x) (x).begin(),(x).end()

#define RI(x) scanf("%d",&(x))
#define RII(x,y) scanf("%d %d",&(x),&(y))
#define RS(x) scanf("%s",x)
#define RI64(x) scanf("%I64d",&(x))
#define RII64(x,y) scanf("%I64d%I64d",&(x),&(y))

#define FIR first
#define SEC second
#define pritnf printf
#define N 100514
typedef long long int lnt;
typedef double dou;
typedef pair<int,int> P;

auto f(int n){
    lnt t = 0;
    int s = 0;
    FZ(i,1<<20){
        t+= n;
        for(auto x=t;x;x/=10){
            s|= 1<<(x%10);
        }
        if(s==1023){
            return t;
        }
    }
    return -1ll;
}
int n;
void sol(int uuu){
    RI(n);
    auto res = f(n);
    printf("Case #%d: ",uuu);
    if(res==-1)puts("INSOMNIA");
    else printf("%lld\n",res);
}
int main(){
	freopen("A-large.in","r",stdin);
	freopen("ALout.txt","w",stdout);
	int t;
	if(RI(t)!=EOF){
		for(int ti=1;ti<=t;ti++)sol(ti);
	}
	return 0;
}

