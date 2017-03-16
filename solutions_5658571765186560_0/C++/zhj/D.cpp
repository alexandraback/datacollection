#include<bits/stdc++.h>
#define int64 long long
#define sqr(x) (x)*(x)
#define mk make_pair
#define pb push_back
#define fi first
#define se second
#define rep(i,x,y) for(int i=x;i<=y;++i)
#define VI vector<int>
#define VI64 vector<int64>
#define VS vector<string>
#define PII pair<int,int>
#define PDD pair<double,double>
#define VPII vector< PII >
#define SZ(x) ((int)(x).size())
#define WIN "GABRIEL\n"
#define LOSE "RICHARD\n"
using namespace std;
const double pi=acos(-1);
int x,n,m,T,tim;
int main(){
	freopen("D.in","r",stdin);
	freopen("D.out","w",stdout);
	for(scanf("%d",&T);T--;){
		tim++;
		printf("Case #%d: ",tim);
		scanf("%d%d%d",&x,&n,&m);
		if(n<m)swap(n,m);
		if(n<x || m <(x+1)/2 || (n*m%x)){
			printf(LOSE);
			continue;
		}
		if(x<=3)printf(WIN);
		else if(x==4){
			if(m==2)printf(LOSE);
			else printf(WIN);
		}else if(x==5)printf(WIN);
		else if(x==6){
			if(m==3)printf(LOSE);
			else printf(WIN);
		}else printf(LOSE);
	}
}
