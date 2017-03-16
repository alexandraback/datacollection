#include <bits/stdc++.h>


using namespace std;


#define fr(i,a,b) for(int i=a;i<b;++i)
typedef long long ll;
int t,n;
char st[1000100];
int dp[1000100], at[1000100];
bool ehvog(int i){
	return st[i] == 'a' || st[i] == 'e' || st[i] == 'i' || st[i] == 'o' || st[i] == 'u';
}
int main(){
	scanf("%d",&t);
	fr(cas,1,t+1){
		scanf("%s %d",st,&n);
		int tam = strlen(st);
		dp[0] = at[0] = ehvog(0)?0:1;
		int ini = 0, fim = 0;
		ll resp = 0LL;
		fr(i,0,tam){
			if(fim-i+1 < n && i){
				at[fim]--;
			}
			while(fim < tam && at[fim] != n){
				fim++;
				if(ehvog(fim)) at[fim] = 0;
				else at[fim] = at[fim-1]+1;
			}
			resp += tam-fim;
		}
		printf("Case #%d: %lld\n",cas,resp);
	}
	return 0;
}
