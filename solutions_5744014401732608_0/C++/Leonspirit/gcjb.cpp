#include <bits/stdc++.h>

#define ll long long
using namespace std;

ll pow2[55];
ll a,b;
int ss[55][55];

int main(){
	
	freopen("B-small-attempt0.in","r",stdin);
	freopen("out.txt","w",stdout);
	
	pow2[0]=1;
	for(int x=1;x<=52;x++)pow2[x]=pow2[x-1] * 2LL;
	
	int teskes;
	scanf("%d",&teskes);
	
	for(int tc=1;tc<=teskes;tc++){
		scanf("%lld%lld",&a,&b);
		
		printf("Case #%d: ",tc);
		if(b>pow2[a-2]){
			printf("IMPOSSIBLE\n");
			continue;
		}	
		
		memset(ss,0,sizeof ss);
		printf("POSSIBLE\n");
		
		for(int x=0;x<a-1;x++)ss[x][x+1]=1;
		
		for(int x=a-2;x>=0;x--){
			int now=a-x;
			now-=2;
			if(pow2[now]<=b){
				for(int y=x+1;y<a;y++)ss[x][y]=1;
			}
			else{
				ll sisa = b;
				sisa -= pow2[now-1];
				
				for(int y=x+2;y<a;y++){
					int nows = a-y;
					nows-=2;
					if(nows==-1)nows=0;
					
					if(sisa>=pow2[nows]){
						sisa-=pow2[nows];
						ss[x][y]=1;
					}
				}
				break;
			}
		}
		for(int x=0;x<a;x++){
			for(int y=0;y<a;y++){
				printf("%d",ss[x][y]);
			}
			printf("\n");
		}		
	}
	return 0;
}
