#include<bits/stdc++.h>
using namespace std;

#define scl(x) scanf("%lld",&x)
#define sc(x)  scanf("%d",&x)
#define ll long long
#define lop(i,n) for(int i=0;i<n;++i)
typedef pair<int,int> ii;
typedef pair<ll,ll> pll;


vector<ll> out;
vector<vector<int> > shahed;
int main(){
#ifndef ONLINE_JUDGE
	freopen("i.txt","r",stdin);
	freopen("o.txt","w",stdout);
#endif
	vector<int> vec(9);
	for(int i=1;out.size()<500;i+=2){
		ll num=i+(1LL<<31),ok=1;
		for(int b=2;b<=10&&ok;++b){
			ok=0;
			for(int j=2;j<=13;++j){
				int mod=0;
				for(int m=1,c=0;c<32;++c,m=(m*b)%j){
					if(num&(1LL<<c)){
						mod=(m+mod)%j;
					}
				}
				if(!mod){
					ok=1;
					vec[b-2]=j;
					break;
				}
			}
		}
		if(ok)out.push_back(num),shahed.push_back(vec);
	}
	printf("Case #1:\n");
	lop(i,500){
		cout<<bitset<32> (out[i]);
		lop(j,9)printf(" %d",shahed[i][j]);
		puts("");
	}

}
