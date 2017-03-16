#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
#include<cmath>
#define ll long long
#define ld long double
using namespace std;
const ll maxn= 2e3;
ll a[maxn],b[maxn],ans[maxn];
ll T,n,i,j,K,C,S,cnt,la;
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	cin>> T;
	for (int t= 1;t<=T;t++){
		printf("Case #%d: ",t);
		cin>> K>> C>> S;
		cnt= 0;
		for (i= 1;i<=K;i++)
			a[i]= b[i]= i;
		for (i= 2;i<=C;i++)
			for (j= 1;j<=K;j++){
				if (b[j]<K) b[j]++;
				a[j]= (a[j]-1)*K+b[j];
			}
		la= 0;
		ll x= 1;
		while (x<=K){
			ans[++la]= a[x];
			x+= C;
		}
		if (la>S) printf("IMPOSSIBLE\n");
		else {
			//printf("Yes %I64d ",la);
			for (i= 1;i<=la;i++){
				cout<< ans[i];
				printf("%c",i<la?' ':'\n');
			}
		}
	}return 0;
}
