#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;

int g[200];
int main(){
	int t,n,s,p;
	scanf("%d",&t);
	for(int tt=1;tt<=t;tt++){
		int ans=0;
		scanf("%d%d%d",&n,&s,&p);
		for(int i=0;i<n;i++)
			scanf("%d",&g[i]);
		sort(g,g+n);
		for(int i=n-1;i>=0;i--){
			int k=g[i]/3+(g[i]%3>1);
			if(k>=p)
				ans++;
			else{
				if(g[i]%3!=1 && k==p-1 && s>0 && g[i]>1){
					ans++;
					s--;
				}
				else if(g[i]%3==1 && k==p-1){
					ans++;
				}
			}
		}
		printf("Case #%d: %d\n", tt, ans);
	}
	return 0;
}
