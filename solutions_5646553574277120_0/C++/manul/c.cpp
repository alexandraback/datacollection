#include<iostream>
#include<fstream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
#include<string>
#include<cstdio>
#include<map>

#define forn(i, n)	for(int i = 0; i < n; i++)
#define ll long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define vi vector<int>a
#define vii vector<pair<int,int>>
#define vvi vector<vector<int>>
#define all(x) (x).begin(), (x).end()

using namespace std;

const int md = 1000000007;
const int maxn = 101010;
const int maxn4 = 4 * maxn;
const ll inf = 2020202020202020202LL;

int main()
{
	ifstream cin("input.txt");
	ofstream cout("output.txt");
int t;
cin>>t;
forn(it, t)
{
	int val[55];
	int c, d, v;
	cin>>c>>d>>v;
	forn(i, d)
		cin>>val[i];
	vector <int > rch(v + 1);
	rch[0] = 1;
	forn(i, d)
		for (int j = v; j >= val[i]; j--)
		if (rch[j - val[i]])
			rch[j] = 1;
	int ans = 0;
	for(int i = 0; i <= v;i++)
		if (!rch[i])
		{
			ans++;
			for(int j = v; j>= i; j--)
				if (rch[j- i])
					rch[j] = 1;
		}
	cout<<"Case #"<<it + 1<<": "<<ans<<endl;

}
	return 0;
}
