#include<bits/stdc++.h>
using namespace std;

#define scl(x) scanf("%lld",&x)
#define sc(x)  scanf("%d",&x)
#define ll long long
#define lop(i,n) for(int i=0;i<n;++i)
typedef pair<int,int> ii;
typedef pair<ll,ll> pll;


vector<int> out;
vector<vector<int> > shahed;
int main(){
#ifndef ONLINE_JUDGE
	freopen("i.txt","r",stdin);
	freopen("o.txt","w",stdout);
#endif
	vector<int> vec(9);
	for(int i=1;out.size()<50;i+=2){
		int num=i+(1<<15),ok=1;
		for(int b=2;b<=10&&ok;++b){
			ll tmp=0,m=1;
			ok=0;
			for(int j=0;j<16;++j,m*=b){
				if(num&(1<<j)){
					tmp+=m;
				}
			}
			for(ll j=2;j*j<=tmp;++j){
				if(tmp%j==0){
					ok=1;
					vec[b-2]=j;
					break;
				}
			}
		}
		if(ok)out.push_back(num),shahed.push_back(vec);
	}
	printf("Case #1:\n");
	lop(i,50){
		cout<<bitset<16> (out[i]);
		lop(j,9)printf(" %lld",shahed[i][j]);
		puts("");
	}

}
