#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <sstream>
#define MP make_pair
#define PB push_back

using namespace std;

const int MAXN = 10000010;
typedef long long LL;
typedef unsigned long long ULL;
typedef vector <int> VI;
typedef vector <string> VS;
typedef vector <LL> VL;

VL ans;

bool palindromes(LL n)
{
	VI a;
	while(n)
	{
		a.PB(n % 10);
		n /= 10;	
	}	
	
	VI b = a;
	reverse(b.begin(), b.end());
	
	return a == b;
}

int count(LL key)
{
	return upper_bound(ans.begin(), ans.end(), key) - ans.begin();	
}

int main()
{
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	
	for(LL i = 1; i < MAXN; ++ i)
	{
		if(palindromes(i) && palindromes(i * i))
		{
			ans.PB(i * i);	
		}	
	}
	
////	for(int i = 0; i < ans.size(); ++ i)	cout << ans[i] << " ";
	
	int T;	cin >> T;
	
	for(int cas = 1; cas <= T; ++ cas)
	{
		LL l, r;
		cin >> l >> r;	
		cout << "Case #" << cas << ": " << count(r) - count(l - 1) << endl; 
	}
	
	
	return 0;	
}
