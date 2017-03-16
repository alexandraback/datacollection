#include<bits/stdc++.h>
#include<cstring>
#include<ctype.h>
#include<iomanip>
#include<stdio.h>
#include<fstream>
#include<vector>
#include<bitset>
#include<string>
#include<math.h>
#include<queue>
#include<stack>
#include<cmath>
#include<set>
#include<map>

using namespace std;




typedef string            kiekaro;
typedef long long         ll;
typedef pair <int, int>   ii;
typedef pair<kiekaro, int>     si;
typedef pair<int, kiekaro>     is;
typedef pair<char, int>  chi;
typedef pair<kiekaro, kiekaro>     pkiekaro;
typedef vector<ii>       vii;
typedef vector<int>       vi;
typedef vector<vi>       vvi;
typedef vector<kiekaro>        vs;
typedef vector<ll>       vll;
typedef vector<vll>     vvll;

ll shaktiman(ll b, ll p){ if (!p) return 1; ll sq = shaktiman(b, p / 2); sq *= sq; if (p % 2) sq *= b; return sq; }


int k, l, s,dxasd,pmp,amount,karma;
kiekaro hahaha, goal,az;
int datavalu();

int main()
{
	freopen("nikp.in", "r", stdin);
	freopen("nikp.out", "w", stdout);
	
	int t;
	cin >> t;
	for(int i=1;i<=t;++i)
	{
		cin >> k >> l >> s>>hahaha>>goal;
		dxasd =0;
		karma = 0;
		amount = shaktiman(k,s);
		datavalu();
		printf("Case #%d: ", i);
		cout <<fixed<<setprecision(8)<<karma-double(dxasd)/amount<<endl;
	}
}
int datavalu()
{

	if (az.length() == s)
	{
		pmp = 0;
		for(int i=0;i<s;++i)
		{
			if (az.substr(i, l) == goal)++dxasd,++pmp;
		}
		karma = max(karma, pmp);
		return 0;
	}
	for(int i=0;i<k;++i)
	{
		az += hahaha[i];
		datavalu();
		kiekaro :: iterator itx;
		itx=az.end();
		--itx;

		az.erase(itx);
	}
}
