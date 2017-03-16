#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN=2000;
struct ipt_t{
	int a,b;
	bool operator <(const ipt_t& o)const{
		return b>o.b;
	}
};
ipt_t ipt[MAXN];
bool useda[MAXN],usedb[MAXN];

int main(){
	int T;
	cin>>T;
	for(int tt=1;tt<=T;tt++){
		int N;
		cin>>N;
		for(int i=0;i<N;i++){
			cin>>ipt[i].a>>ipt[i].b;
		}
		fill(useda,useda+N,false);
		fill(usedb,usedb+N,false);
		sort(ipt,ipt+N);
		int cur=0;
		int res=0;
		while(cur<2*N){
			for(int i=0;i<N;i++)
				if(!usedb[i] && ipt[i].b<=cur){
					if(useda[i])
						cur+=1;
					else
						cur+=2;
					usedb[i]=true;
					useda[i]=true;
					res++;
					goto fin_w;
				}
			for(int i=0;i<N;i++)
				if(!useda[i] && ipt[i].a<=cur){
					useda[i]=true;
					cur+=1;
					res++;
					goto fin_w;
				}
			break;
fin_w:		1;
		}
		printf("Case #%d: ",tt);
		if(cur!=2*N)
			printf("Too Bad\n");
		else
			printf("%d\n",res);
	}
}
