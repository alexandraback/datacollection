#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int main()
{
	int Case,sum,sp,Min,num;
	freopen("B-small-attempt0.in","r",stdin);
	freopen("B-small-attempt0.out","w",stdout);
	scanf("%d",&Case);
	for(int i=1;i<=Case;i++){
		scanf("%d%d%d",&sum,&sp,&Min);
		int ans=0;
		while(sum--){
			scanf("%d",&num);
			if(num%3==0){
				if(num/3>=Min){
					ans++;continue;
				}
				else{
					if(sp>0&&num/3+1>=Min&&num/3-1>=0){
						sp--;
						ans++;
						continue;
					}
				}
			}
			else if(num%3==1){
				if(num/3+1>=Min){
					ans++;continue;
				}
			}
			else if(num%3==2){
				if(num/3+1>=Min){
					ans++;continue;
				}
				else if(num/3+2>=Min){
					if(sp>0){
						sp--;
						ans++;
						continue;
					}
				}
			}
		}
		printf("Case #%d: ",i);
		printf("%d\n",ans);
	}
	return 0;
}



		
