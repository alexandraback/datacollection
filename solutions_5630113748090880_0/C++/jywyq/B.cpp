/*
 * Author:Õı”Ì«Ô(jywyq) 
 * Date:20160416
 */
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<string>
#include<cstring>
using namespace std;
#define LL long long
int num[3000];
int main(){
	freopen("B-small-attempt0.in","r",stdin);
	freopen("dataout.txt","w",stdout);
	int t,n,cas=0,tmp;
	scanf("%d",&t);
	while(t--){
		memset(num,0,sizeof num);
		scanf("%d",&n);
		for(int i=0;i<2*n-1;i++){
			for(int j=0;j<n;j++){
				scanf("%d",&tmp);
				num[tmp]++;
			}
		}
		printf("Case #%d:",++cas);
		for(int i=1;i<2600;i++){
			if(num[i]&1)printf(" %d",i);
		}
		puts("");
		
		
	}
	
}
