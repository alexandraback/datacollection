#include<bits/stdc++.h>
int main(){
	int t;
	scanf("%d",&t);
	for(int T=1;T<=t;T++){
		int b,m;
		scanf("%d %d",&b,&m);
		if(m>1<<(b-2))
		{
			printf("Case #%d: IMPOSSIBLE\n",T);
			continue;
		}
		m--;
		int ans[50][50];
		memset(ans,0,sizeof(ans));
		for(int i=0;i<b;i++)
		for(int j=i+1;j<b;j++)
		ans[i][j]=1;
		bool bit[100];
		for(int i=0;i<100;i++)
		bit[i]=false;
		int l=0;
		while(m){
			if(m%2==1)bit[l++]=true;
			else bit[l++]=false;
			m/=2;
		}
		for(int i=0;i<b-2;i++){
			if(!bit[i]){
				ans[0][b-i-2]=0;
			}
		}
		printf("Case #%d: POSSIBLE\n",T);
		for(int i=0;i<b;i++,printf("\n"))
		for(int j=0;j<b;j++)
		printf("%d",ans[i][j]);
	}	
}
