#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/priority_queue.hpp>
#define f first
#define s second
using namespace std;
//using namespace __gnu_pbds;
typedef pair<int,int> par;
typedef pair<par,int> pr;
int ask(int k,int x){
	if(k==0)return 0;
	if(x==0)return k;
	int l=__lg(x),m=(1<<(l+1));
	return ask(m,x^(1<<l))*(k/m)+ask(k/m,x^(1<<l));
	}
int main(){
	int t,T=0;
	scanf("%d",&t);
	while(t--){T++;
		int a,b,k;
		scanf("%d%d%d",&a,&b,&k);
		long long int ans=0;
		for(int i=0;i<a;i++)
			for(int j=0;j<b;j++)
				if((i&j)<k)
					ans++;
		printf("Case #%d: %lld\n",T,ans);

		}
	return 0;
	}
