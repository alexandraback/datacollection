#include<stdio.h>
#include<string>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<iostream>
#include <cassert>
#include<map>
#include<queue>
#include<stack>
#include<time.h>
#include<math.h>
#include<set>
#include<complex>
using namespace std;
#define INF 0x3f3f3f3f
#define DINF 1e30
#define EPS 1e-9
#define PII acos(-1)
#define LL long long
#define Pii pair<int,int>
#define For(i,n) for(int i=0;i<n;i++)
#define ileer(n) scanf("%d",&n)
#define i2leer(n,m) scanf("%d %d",&n,&m)
#define fleer(n) scanf("%lf",&n)
#define f2leer(n,m) scanf("%Lf %Lf",&n,&m)
#define MK make_pair
#define PB push_back
#define llenar(arr,val) memset(arr,val,sizeof(arr))
#define VLL vector< LL >
#define matrix vector<VI >
#define F first
#define S second
#define MAXN 3000
int n;
vector<int> grafo[MAXN];
//componentes fuertes
vector<int> rgrafo[2001];
bool visitado[2001];

int cam[MAXN];
int vengo[MAXN];
bool termino[MAXN];


void dfs2(int u,int con,int p){
	if(con>cam[u]){
		cam[u]=con;
		vengo[u]=p;
	}
	visitado[u]=true;
	for(int i=0;i<grafo[u].size();i++){
		int v=grafo[u][i];
		
		if(!visitado[v]){
			dfs2(v,con+1,u);
		}else if(termino[v]){
			if(cam[u]+1>cam[v]){
				cam[v]=cam[u]+1;
				vengo[v]=u;
			}
			
		}
		
	}
	termino[u]=true;
}

bool ayuda[MAXN];

vector<int> topo;
int componente[2001];    //me indica en que componente esta cada nodo
int compsize[2001];      //me indica el tamaño de la componente
//hast aqui

//algoritmo de componentes desde aqui
void dfs(int u){
	visitado[u]=true;
	for(int i=0;i<grafo[u].size();i++){
		int v=grafo[u][i];
		if(!visitado[v])
			dfs(v);
	}
	topo.push_back(u);
}

void rdfs(int u,int can){
	visitado[u]=true;
	componente[u]=can;
	compsize[can]++;
	for(int i=0;i<rgrafo[u].size();i++){
		int v=rgrafo[u][i];
		if(!visitado[v])
			rdfs(v,can);
	}
}

int scc(){
	topo.clear();
	llenar(visitado,false);
	for(int i=0;i<n;i++){
		if(!visitado[i]){
			dfs(i);
		}
	}
	int can=0;
	llenar(visitado,false);
	for(int i=0;i<n;i++){
		componente[i]=-1;
	}
	for(int i=topo.size()-1;i>=0;i--){
		if(!visitado[topo[i]]){
			rdfs(topo[i],can);
			can++;
		}
	}
	return can;
}


int main(){
	int t;
	ileer(t);
	For(c,t){
		ileer(n);
		
		for(int i=0;i<n;i++){
			int a;
			ileer(a);
			grafo[i].PB(a-1);
			rgrafo[a-1].PB(i);
		}
		
		
		llenar(compsize,0);
		
		
		int tam=scc();

		
		
		for(int i=0;i<n;i++){ cam[i]=1;
			vengo[i]=-1;
		
		}
		llenar(visitado,false);
		for(int i=0;i<n;i++){
			For(j,n){termino[j]=false;}
			dfs2(i,cam[i],-1);
		}
		/*
		for(int i=0;i<n;i++){
			cout<<i+1<<" "<<cam[i]<<" "<<vengo[i]+1<<endl;
		}
		*/
		int maxi=0;
		for(int i=0;i<n;i++){
			int actual=0;
			
			llenar(ayuda,false);
			for(int j=0;j<grafo[i].size();j++){
				ayuda[grafo[i][j]]=true;
			}
			
			
			for(int j=0;j<rgrafo[i].size();j++){
				int v=rgrafo[i][j];
				if(v!=vengo[i] && !ayuda[v] && componente[i]!=componente[v]&& cam[i]+1>=cam[v]){
					//cout<<i+1<<" "<<v+1<<" "<<cam[i]<<" "<<cam[v]<<endl;
					actual=max(cam[i]+cam[v],actual);
				}else{
					actual=max(actual,cam[i]);
				}
				
			}
		
			maxi=max(maxi,actual);
		}
		
		
		
		printf("Case #%d: %d\n",c+1,maxi);
		for(int i=0;i<n;i++){
			grafo[i].clear();
			rgrafo[i].clear();
		}
	}
}