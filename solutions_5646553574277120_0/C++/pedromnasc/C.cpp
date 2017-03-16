#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int T,C,D,V;
int v[105];

int main(){
	scanf("%d",&T);
	for(int caso=1;caso<=T;caso++){
		scanf("%d %d %d",&C,&D,&V);
		for(int i=0;i<D;i++) scanf("%d",&v[i]);		
		sort(v,v+D);		
		v[D]=100000000;
		int id=0;
		int resp=0;
		int atual=1;		
		while(atual<=V){
			if(atual>v[id]){
				atual+=v[id];
				id++;
				continue;
			}			
			if(atual == v[id]){
				atual+=v[id];			
				id++;			
			}else{
				atual+=atual;
				resp++;
			}
		}		
		printf("Case #%d: %d\n",caso,resp);	
	}	

}
