#include<bits/stdc++.h>
using namespace std;
int main(){
	int T,n;
	scanf("%d",&T);
	for(int cs=1;cs<=T;cs++){
		scanf("%d",&n);
		if(n==0) printf("Case #%d: INSOMNIA\n",cs);
		else{
			int t=0,s=0;
			while(s!=1023){
				++t;
				long long tmp=n*t;
				while(tmp){
					s|=1<<tmp%10;
					tmp/=10;
				}
			}
			printf("Case #%d: %lld\n",cs,1LL*t*n);
		}
	}
	return 0;
}