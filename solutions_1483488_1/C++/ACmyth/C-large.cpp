#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
int getlen(int num){
	if(num<10) return 1;
	if(num<100) return 2;
	if(num<1000) return 3;
	if(num<10000) return 4;
	if(num<100000) return 5;
	if(num<1000000) return 6;
	if(num<10000000) return 7;
	if(num<100000000) return 8;
}

int re[100010];
int main()
{
	freopen("C-large.in","r",stdin);
	freopen("C-large.out","w",stdout);
	int i;
	int n,a,b;
	scanf("%d",&n);
	for(int ca=1;ca<=n;ca ++){
		scanf("%d%d",&a,&b);
		int s=0;
		for(i=a;i<=b;i++){


				int l=getlen(i);
				int rer=0;
				//printf("%d:\n",i);
				for(int j=1;j<l;j++){
					int po=pow(10,j);
					int temp=i%po;
					if(temp*10/po>0){
						int k=i/po;
						k+=temp*pow(10,l-j);
						if(k<=b&&k>=a){
							if(k>i){
								for(int r=0;r<rer;r++){
									if(re[r]==k) break;
								}
								if(r==rer)
								{
									s++;
									re[rer++]=k;
								}
							}
						}
					}
				}
			
		}
		printf("Case #%d: %d\n",ca,s);
		
	}
	
	
	return 0;
} 
