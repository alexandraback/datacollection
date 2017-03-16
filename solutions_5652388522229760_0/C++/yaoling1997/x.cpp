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
const ll maxn= 15;
ll b[maxn];
ll T,i,j,x,cnt,n;
void init(){
	memset(b,0,sizeof(b));
	cnt= 0;
}
void update(ll x){
	if (x<10){
		cnt+= 1-b[x];
		b[x]= 1;
		return;
	}
	while (x){
		ll r= x%10;
		x/= 10;
		cnt+= 1-b[r];
		b[r]= 1;
	}	
}
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	cin>> T;
	for (int t= 1;t<=T;t++){
		printf("Case #%d: ",t);
		cin>>n;
		init();
		for (i= 1;i<=5e4;i++){
			x= n*i;
			update(x);
			if (cnt==10) break;
		}
		if (cnt==10) cout<<i*n;
		else printf("INSOMNIA");
		printf("\n");
	}return 0;
}
