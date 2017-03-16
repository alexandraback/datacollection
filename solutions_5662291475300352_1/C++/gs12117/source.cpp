#include<stdio.h>
#include<algorithm>
int tcn,tc;
int n,m;
int d[100100];
int v[100100];
int g[100100];
long long int cyc[100100];
long long int tm[100100];
struct node{
	int plus;
	long long int atime;
	bool operator<(const node&r)const{
		return atime<r.atime;
	}
};
node na[5001000];
int nodn;
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int i,j,ans;
	double s;
	scanf("%d",&tcn);
	for(tc=1;tc<=tcn;tc++){
		n=0;
		scanf("%d",&m);
		for(i=0;i<m;i++){
			scanf("%d%d%d",&d[i],&g[i],&v[i]);
			for(j=0;j<g[i];j++){
				cyc[n]=(long long int)(v[i]+j)*360;
				tm[n]=(long long int)(v[i]+j)*(360-d[i]);
				n++;
			}
		}
		ans=0;
		s=0;
		for(i=0;i<n;i++){
			s+=1.0/cyc[i];
		}
		s=n/s;
		nodn=0;
		for(i=0;i<n;i++){
			for(j=0;j<s/cyc[i]+3;j++){
				if(j==0)na[nodn].plus=-1;
				else na[nodn].plus=1;
				na[nodn].atime=tm[i]+cyc[i]*j;
				nodn++;
			}
		}
		std::sort(na,na+nodn);
		j=0;
		for(i=0;i<nodn;i++){
			j+=na[i].plus;
			if(i==nodn-1||na[i].atime!=na[i+1].atime){
				if(j<ans)ans=j;
			}
		}
		printf("Case #%d: %d\n",tc,ans+n);
	}
}