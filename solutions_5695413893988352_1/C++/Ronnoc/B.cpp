#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
#define MP make_pair
#define PB push_back
#define AA first
#define BB second
#define OP begin()
#define ED end()
#define SZ size()
#define cmin(x,y) x=min(x,y)
#define cmax(x,y) x=max(x,y)
const LL MOD = 1000000007;
const double PI = acos(-1.);
const double eps = 1e-9;
char C[22],J[22];
LL ac,aj;
bool hasans;
void update(LL p,LL q){
	//cout<<"? "<<p<<" "<<q<<"\n";
	if(!hasans){
		ac=p,aj=q;
		hasans=1;
		return;
	}
	LL pre=fabs(ac-aj);
	LL now=fabs(p-q);
	if(now<pre){
		ac=p;aj=q;
	}
	if(now==pre&&ac>p){
		ac=p,aj=q;
	}
	if(now==pre&&ac==p&&aj>q)aj=q;
}
int main(){
	int i,j,k,_T;
	scanf("%d",&_T);
	for(int CA=1;CA<=_T;CA++){
		scanf("%s%s",C,J);
		int n=strlen(C);
		LL ic=0,ij=0;
		hasans=0;
		for(i=0;i<n;i++){
			int mc[3],mj[3];
			memset(mc,-1,sizeof mc);
			memset(mj,-1,sizeof mj);
			for(j=0;j<=9;j++)if(C[i]=='?'||C[i]=='0'+j)
				for(k=0;k<=9;k++)if(J[i]=='?'||J[i]=='0'+k){
					if(j>k){
						if(mc[0]==-1)mc[0]=j,mj[0]=k;
						else {
							if(mc[0]-mj[0]>j-k)mc[0]=j,mj[0]=k;
							else if(mc[0]-mj[0]==j-k){
								if(mc[0]>j)mc[0]=j,mj[0]=k;
							}
						}
					}
					if(j==k){
						if(mc[1]==-1||mc[1]>j)mc[1]=j,mj[1]=k;
					}
					if(j<k){
						if(mc[2]==-1)mc[2]=j,mj[2]=k;
						else {
							if(mj[2]-mc[2]>k-j)mc[2]=j,mj[2]=k;
							else if(mc[2]-mj[2]==j-k){
								if(mc[2]>j)mc[2]=j,mj[2]=k;
							}
						}
					}
				}
			if(~mc[0]){
				LL tc=ic*10+mc[0],tj=ij*10+mj[0];
				for(j=i+1;j<n;j++)tc=tc*10+(C[j]=='?'?0:C[j]-'0');
				for(j=i+1;j<n;j++)tj=tj*10+(J[j]=='?'?9:J[j]-'0');
				update(tc,tj);
			}
			if(~mc[2]){
				LL tc=ic*10+mc[2],tj=ij*10+mj[2];
				for(j=i+1;j<n;j++)tc=tc*10+(C[j]=='?'?9:C[j]-'0');
				for(j=i+1;j<n;j++)tj=tj*10+(J[j]=='?'?0:J[j]-'0');
				update(tc,tj);
			}
			if(mc[1]==-1)break;
			ic=ic*10+mc[1];
			ij=ij*10+mj[1];
			if(i+1==n){
				update(ic,ij);
			}
			//cout<<i<<" "<<ic<<" "<<ij<<"\n";
		}
		for(i=n-1;i>=0;i--){
			C[i]='0'+ac%10;ac/=10;
			J[i]='0'+aj%10;aj/=10;
		}
		printf("Case #%d: %s %s\n",CA,C,J);
	}
	return 0;
}