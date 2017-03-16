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
int apar[MAXN];
int main(){
	int t;
	ileer(t);
	For(c,t){
		llenar(apar,0);
		int n;
		ileer(n);
		int maxi=0;
		for(int i=0;i<2*n-1;i++){
			for(int j=0;j<n;j++){
				int a;
				ileer(a);
				maxi=max(a,maxi);
				apar[a]++;
			}
		}
		vector<int> lista;
		for(int i=1;i<=maxi;i++){
			if(apar[i]%2!=0) lista.push_back(i);
		}
		sort(lista.begin(),lista.end());
		
		printf("Case #%d: ",c+1);
		for(int i=0;i<lista.size();i++){
			printf("%d",lista[i]);
			if(i==lista.size()-1) printf("\n");
			else printf(" ");
		}
		
		
		
		
	}
}