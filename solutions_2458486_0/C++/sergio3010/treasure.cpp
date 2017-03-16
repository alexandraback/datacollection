#include <bits/stdc++.h>

using namespace std;



#define fr(i,a,b) for(int i=a;i<b;++i)
typedef long long ll;






int t,k,n;
int comeco[210];
int nch[210];
int ch[210][210];
int tipo[210];
int vai[1<<20];
int nxt[1<<20];


bool go(int mask){
	if(vai[mask] != -1) return vai[mask];
	if(mask == (1<<n)-1) return vai[mask] = 1;
	vai[mask] = 0;
	nxt[mask] = -1;
	int qtdnow[210];
	memset(qtdnow, 0, sizeof qtdnow);
	fr(i,0,k) qtdnow[comeco[i]]++;
	fr(i,0,n){
		if((1<<i)&mask){
			qtdnow[tipo[i]]--;
			fr(j,0,nch[i]) qtdnow[ch[i][j]]++;
		}
	}
	fr(i,0,n){
		if(!((1<<i)&mask)){
			if(qtdnow[tipo[i]] > 0){
				if(go(mask|(1<<i))){
					nxt[mask] = mask | (1<<i);
					vai[mask] = 1;
					break;
				}
			}
		}
	}
	//printf("%d %d\n",mask,vai[mask]);
	return vai[mask];
}




int main(){
	scanf("%d",&t);
	fr(cas,1,t+1){
		scanf("%d %d",&k,&n);
		memset(vai, -1, sizeof vai);
		fr(i,0,k){ 
			scanf("%d",&comeco[i]);
		}
		fr(i,0,n){ 
			scanf("%d %d",&tipo[i],&nch[i]);
			fr(j,0,nch[i]){
				scanf("%d",&ch[i][j]);
			}
		}
		go(0);
		printf("Case #%d:",cas);
		if(vai[0] == 1){
			int now = 0;
			while(now != (1<<n)-1){
				printf(" %d",__builtin_ctz(nxt[now]-now)+1);
				now = nxt[now];
			}
			printf("\n");
		}
		else{
			printf(" IMPOSSIBLE\n");
		}
		
	}
	return 0;
}

























































