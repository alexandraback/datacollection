#include<stdio.h>
#include<algorithm>
using namespace std;
int con[4][4]={
{0,1,2,3},
{1,0,3,2},
{2,3,0,1},
{3,2,1,0}
};
int nega[4][4]={
{0,0,0,0},
{0,1,0,1},
{0,1,1,0},
{0,0,1,1}
};
char str[11000];
int main(){
	int T;
	scanf("%d",&T);
	for(int t=1;t<=T;t++){
		int a;
		long long b;scanf("%d%lld",&a,&b);
		scanf("%s",str);
		int sig=0;
		int val=0;
		for(int i=0;i<a;i++){
			sig^=(nega[val][str[i]-'h']);
			val=(con[val][str[i]-'h']);
		}
		printf("Case #%d: ",t);
		int tsig=0;
		int tval=0;
		for(int i=0;i<b%4;i++){
			tsig^=sig;
			tsig^=(nega[tval][val]);
			tval=(con[tval][val]);
		}
		//printf("%d %d\n",tsig,tval);
		if(tval==0&&tsig==1){
			bool ok=false;
			int fi=-1;
			for(int i=0;i<4;i++){
				int nsig=0;
				int nval=0;
				for(int j=0;j<i;j++){
					nsig^=(nega[nval][val]);
					nval=(con[nval][val]);
				}
				for(int j=0;j<a;j++){
					nsig^=(nega[nval][str[j]-'h']);
					nval=(con[nval][str[j]-'h']);
					if(nsig==0&&nval==1){
						fi=a*i+j+1;break;
					}
				}
				if(~fi)break;
			}
			int la=-1;
			for(int i=0;i<4;i++){
				int nsig=0;
				int nval=0;
				for(int j=0;j<i;j++){
					nsig^=(nega[nval][val]);
					nval=(con[nval][val]);
				}
				for(int j=a-1;j>=0;j--){
					nsig^=(nega[str[j]-'h'][nsig]);
					nval=(con[str[j]-'h'][nval]);
					if(nsig==0&&nval==3){
						la=a*i+a-j;break;
					}
				}
				if(~la)break;
			}
			if(!~fi||!~la||(long long)fi+la>b*a)printf("NO\n");
			else printf("YES\n");
		}else printf("NO\n");
	}
}