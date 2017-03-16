#include<iostream>
#include<cstdio>

using namespace std;

int T,pos;
long long n,tmp,tmp2;
bool flag[12];

int main(){
	freopen("counting.in","r",stdin);
	freopen("counting.out","w",stdout);
	
	scanf("%d",&T);
	
	for(int i=1;i<=T;i++){
		scanf("%lld",&n);
		if (n==0) printf("Case #%d: INSOMNIA\n",i);
		else{
			for(int j=0;j<=9;j++) flag[j]=false;
			pos=0; tmp=0;
			while(pos<=9){
				tmp+=n; tmp2=tmp;
				while(tmp2>0){
					flag[tmp2%10]=true; tmp2/=10;
				}
				while(flag[pos]) pos++;
			}
			printf("Case #%d: %d\n",i,tmp);
		}
	}
	return 0;
}
