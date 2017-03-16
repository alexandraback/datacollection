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
#define MAXN 1010

char cad[MAXN];
int main(){
	int n;
	ileer(n);
	for(int c=0;c<n;c++){
		scanf("%s",cad);
		string g=cad;
		deque<char> lista;
		
		lista.push_back(g[0]);
		
		for(int i=1;i<g.size();i++){

				if(g[i]>=lista.front()){
					lista.push_front(g[i]);
				}else{
					lista.push_back(g[i]);
				}
			
			
		}
		printf("Case #%d: ",c+1);
		while(!lista.empty()){
			printf("%c",lista.front());
			lista.pop_front();
		}
		printf("\n");
		
		
		
	}
}