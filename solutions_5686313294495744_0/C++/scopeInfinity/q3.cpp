#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <map>

using namespace std;

typedef long long ll;

ll MOD = 1e9+7;

ll Gcd(ll a,ll b){
	ll r;
	while(1) {
		r=b%a;if(r==0) return a;
		b=a;a=r;
	}
}

ll Pow(ll a ,int b ,int Mo){
    ll ans = 1;
    for (; b; b >>= 1, a = a * a % Mo)
        if (b&1) ans = ans * a % Mo;
    return ans;
}

long solve() {
	map<string,int> l,r;
	int N;
	cin>>N;
	int A = 0;
	std::vector<string> va(N),vb(N);
	std::vector<int> vDes(N,0);
	for (int i = 0; i < N; ++i)
	{
		string a,b;
		cin>>a>>b;
		l[a]++;
		r[b]++;
		va[i]=a;
		vb[i]=b;
	}
	while(true) {
		int flag = 0;
	for (int i = 0; i < N; ++i)
	if(vDes[i]==0)
	{
		int M = min(l[va[i]],r[vb[i]]);
		if(M>1) {
			l[va[i]]-=1;
			r[vb[i]]-=1;
	    	A+=1;
	    	flag = 1;
	    	vDes[i] = 1;
		}
	}
	for (int i = 0; i < N; ++i)
	{
		int a=l[va[i]],b=r[vb[i]];
		if(a!=1 || b!=1)
			;//cerr<<">"<<a<<' '<<b<<endl;
	}
	if(!flag)
		break;
	}
	cout<<(A);
	
}

int main(int argc, char const *argv[])
{
	std::ios::sync_with_stdio(false);
	
	
	int T;
	cin>>T;
	for (int i = 0; i < T; ++i)
	{
			cout<<"Case #"<<i+1<<": ";
			solve();
			cout<<endl;
	}
	

	return 0;
}

