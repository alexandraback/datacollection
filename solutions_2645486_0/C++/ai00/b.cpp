#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#define MP(x,y)	make_pair((x), (y))
#define PB		push_back()
#define SIZE(x)	((int)x.size())
#define ALL(x)	(x).begin(), (x).end()
#define FS		first
#define SC		second
#define SQR(x)	((x)*(x))
using namespace std;
long long e, r;
int n, m;
int a[10000];
vector<int> v[10001];
int main(){
	int t, tt;
	for (scanf("%d ", &tt), t = 0; t < tt; ++t){
		cin>>e>>r;
		r = min(e, r);
		scanf("%d ", &n);
		//cout<<n<<endl;
		for (int i = 0; i < n; ++i)
			scanf("%d ", &a[i]);
		sort(a, a + n);
		//cout<<"hehe"<<endl;
		long long ans = e * a[n - 1];
		--n;
		int m = e / r + (bool)(e % r);
		//cout<<m<<endl;
		int k = n / m + (bool)(n % m);
		//cout<<k<<endl;
		for (int i = 0; i < k; ++i)
			v[i].clear();
		for (int i = n - 1, j = 0; i >= 0; --i, j = (j + 1) % k){
			if ((n % m)&&(j == k - 1)&&(v[j].size() == n % m)) j = 0;
			//cout<<j<<endl;
			v[j].push_back(a[i]);
		}
		//cout<<"hehe"<<endl;
		//cout<<ans<<endl;
		for (int i = 0; i < k; ++i){
			//cout<<i<<": ";
			//for (int j = 0; j < v[i].size(); ++j)
			//	cout<<v[i][j]<<' ';
			//cout<<endl;
			if (v[i].size() * r > e){
				ans += (v[i].size() * r - e) * v[i][1];
				//cout<<ans<<endl;
			}
			//cout<<min(((signed int)v[i].size()) * r, e)<<' '<<v[i][0]<<endl;;
			ans += min(((signed int)v[i].size()) * r, e) * v[i][0];
			//cout<<ans<<endl;
		}
		cout<<"Case #"<<t + 1<<": "<<ans<<endl;
		//break;
	}
}
