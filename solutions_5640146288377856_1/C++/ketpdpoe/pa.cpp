#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
int main(){
	int T,I;
	scanf("%d",&T);
	for(I=0;I<T;I++){
		int r,c,w;
		scanf("%d %d %d",&r,&c,&w);
		printf("Case #%d: ",I+1);
		if(r==1){
			if(c%w==0){
				printf("%d\n",c/w-1+w);
			}
			else{
				printf("%d\n",c/w-1+w+1);
			}
		}
		else{
			if(w==1){
				printf("%d\n",r*c);
			}
			else{
				int t=c,ans=0,i;
				for(i=0;i<r;i++){
					if(t==c-w)t=c;
					if(t%w==0)ans+=(t/w);
					else ans+=(t/w+1);
				}
				ans+=w;
				printf("%d\n",ans);
			}
		}
	}
	return 0;
}