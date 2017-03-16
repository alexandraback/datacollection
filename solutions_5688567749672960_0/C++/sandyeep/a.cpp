#include <bits/stdc++.h>
using namespace std;
#define int long long

#define pr16

#ifdef pr16
  #define pr(x)                	cerr << #x << ": " << x << endl;
  #define pr2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
  #define pr3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
  #define pr4(a, b, c, d)       cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
  #define pr5(a, b, c, d, e)    cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << endl;
  #define pr6(a, b, c, d, e, f) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl;
	#define prc(a) for(auto it: a) cerr<<(it)<<" "; cerr<<endl
	#define pra(a,n) for(int i=0; i<(n); i++) cerr<<((a)[i])<<" "; cerr<<endl
	#define prdd(a,r,c) for(int i=0;i<(r);i++) { for(int j = 0;j<(c);j++) cerr<<a[i][j]<<" "; cerr<<endl; } cerr<<endl;

#else
  #define pr(x)
  #define pr2(x, y)
  #define pr3(x, y, z)
  #define pr4(a, b, c, d)
  #define pr5(a, b, c, d, e)
  #define pr6(a, b, c, d, e, f)
	#define tr(c,it)
	#define prc(a)
	#define pra(a,n)
	#define prdd(a, r, c)
#endif


int dist[1000100];

int rever(int num)	{
	int ret = 0;
	while(num)	{
		ret += num % 10;
		num /= 10;
		ret *= 10;
	}
	return ret / 10;
}

void jain()	{
	for(int i=0; i<1000100; i++)	{
		dist[i] = 1e7;
	}
	queue<pair<int, int> > Q;
	Q.push({1, 0});
	while(not Q.empty())	{
		auto pp = Q.front();
		Q.pop();
		int num = pp.first, len = pp.second;
		int n1 = num + 1, n2 = rever(num);
		// pr2()
		dist[num] = len;
		if(n1 <= 1e6)	{
			if(dist[n1] > 1e6)	{
				Q.push({n1, len + 1});
			}
		}
		if(n2 <= 1e6 and n1 != n2)	{
			if(dist[n2] > 1e6)	{
				Q.push({n2, len + 1});
			}
		}
	}
}

void pain()	{
	int n; cin >> n;
	cout << dist[n] << "\n";
}

#undef int
int main()	{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string input = "ain.txt";
	string output = "aout.txt";
	freopen(input.c_str(), "r", stdin);
	freopen(output.c_str(), "w", stdout);
	int tt; cin >> tt;
	jain();
	for(int iii=1; iii<=tt; iii++)	{
		cout << "Case #" << iii << ": ";
		pain();
	}
}

