#include <bits/stdc++.h>
using namespace std;

#define sz(v)			(int)(v.size())
#define all(v)			v.begin(),v.end()
#define mems(a , i)		memset(a , i , sizeof(a))
#define memc(a , b)		memcpy(a , b , sizeof(a))
#define mp(x , y)		make_pair(x , y)
#define pb(x)			push_back(x)
#define ansy			{cout << "-1" << endl;return 0;}
#define ansn			{cout << "No" << endl;return 0;}
#define IOS				ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
#define mod				1000000007
#define PI				3.14159265358979323846
#define fi				first
#define se				second
const double EPS = 1e-8;

bool ch(string s , int n){
	int i = sz(s) - 1;
	for(; i >= 0 && n ; i--){
		int l = n % 10;
		n /= 10;
		if(s[i] == '?')	continue;
		if((l + '0') != s[i])	return 0;
	}
	while(i >= 0){
		if(s[i] != '?' && s[i] != '0')	return 0;
		i--;
	}
	return (n == 0);
}

string to(int n){
	stringstream ss;
	ss << n;
	return ss.str();
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("/home/momen/Downloads/B-small-attempt1.in", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif
	IOS;
	int T;
	cin >> T;
	for(int t = 1 ; t <= T ; t++){
		string c, d;
		cin >> c >> d;
		int Abs = 10000000 , a = 1000000, b = -1000000;
		int aa = a , bb = b;
		for(int i = 0 ; i < 1000 ; i++){
			if(ch(c , i))	a = i;
			if(ch(d , i))	b = i;
			if(abs(a - b) < Abs){
				Abs = abs(a - b);
				aa = a , bb = b;
			}
		}
		string x = to(aa) , y = to(bb);
		while(sz(x) < sz(c))	x = '0' + x;
		while(sz(y) < sz(d))	y = '0' + y;
//		cout << c << ' ' << d << endl;
		cout << "Case #" << t << ": "<< x << ' ' << y << endl;
	}
	return 0;
}
