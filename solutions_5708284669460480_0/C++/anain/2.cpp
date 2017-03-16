#include <algorithm>
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <cstring>
#include <ctype.h>
#include <stdio.h>
#include <fstream>
#include <vector>
#include <string>
#include <math.h>
#include <cmath>
#include <iomanip>
 
using namespace std;
 
#define R_(S)         freopen(S, "r", stdin)
#define W_(S)        freopen(S, "w", stdout)
#define R_W R_("B-small-attempt0.in"),W_("output.txt")
 
typedef long long  ll;
 
ll myPow(ll b, ll p){ 
	if (!p) return 1; 
	ll sq = myPow(b, p / 2); 
	sq *= sq; 
	if (p % 2) sq *= b; 
	return sq; 
}
 
int T, K, L, S;
string keys, target,str;

int cnt,temp,tot,maxi;

void solve()
{
	if (str.length() == S)
	{
		temp = 0;
		for(int i=0;i<S;++i){
			if (str.substr(i, L) == target)++cnt,++temp;
		}

		maxi = max(maxi, temp);
		return;
	}

	for(int i=0;i<K;++i)
	{
		str += keys[i];
		solve();
		str.pop_back();
	}
}
int main()
{
	R_W;
	cin >> T;
	for(int i=0;i<T;++i){
		cin>>K>>L>>S>>keys>>target;
		cnt =0;
		maxi = 0;
		tot = myPow(K,S);
		solve();
		printf("Case #%d: ", i + 1);
		cout <<fixed<<setprecision(12)<<maxi-double(cnt)/tot<<endl;
	}
}