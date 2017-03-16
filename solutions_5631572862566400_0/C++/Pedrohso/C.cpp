#include <stdio.h>
#include <algorithm>
#include <vector>
#include <set>
#define mk make_pair
#define ps push_back
#define lw lower_bound
using namespace std;

int n,t;
int p[1123],qual[1123],pp[1123],h[1123],m[1123];
int ciclo,sumb;
int tipo[1123];

void tip(int at,int q){
	qual[at]=q;
	if(tipo[p[at]]!=0){
		if(qual[p[at]]!=q){
			tipo[at]=1;
		}
		else{
			tipo[at]=2;
			int att=p[at],cont=1;
			while(att!=at){
				cont++;
				tipo[att]=2;
				att=p[att];
			}
			ciclo=max(ciclo,cont);
		}
	}
	else{
		tipo[at]=1;
		tip(p[at],q);
	}
}	

void ppai(int at){
	if(tipo[at]>1){
		pp[at]=at;
		h[at]=1;
	}
	else{
		ppai(p[at]);
		pp[at]=pp[p[at]];
		h[at]=h[p[at]]+1;
	}
}

int main(){
	scanf("%d",&t);
	for(int tt=1;tt<=t;tt++){
		ciclo=sumb=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d",&p[i]);
		for(int i=1;i<=n;i++){
			qual[i]=tipo[i]=pp[i]=h[i]=m[i]=0;
			if(p[p[i]]==i){
				tipo[i]=3;
			}
		}
		for(int i=1;i<=n;i++){
			if(tipo[i]==0) tip(i,i);
		}
		for(int i=1;i<=n;i++){
			if(pp[i]==0) ppai(i);
		}
		for(int i=1;i<=n;i++){
			//printf("i %d  pp[i] %d\n",i,pp[i]);
			if(tipo[pp[i]]==3) m[pp[i]]=max( m[pp[i]], h[i] );
		}
		for(int i=1;i<=n;i++){
			//printf("%d %d %d\n",i,m[i],tipo[i]);
			sumb+=m[i];
		}
		
		printf("Case #%d: ",tt);
		printf("%d\n",max(sumb,ciclo));
	}
	return 0;
}
		
