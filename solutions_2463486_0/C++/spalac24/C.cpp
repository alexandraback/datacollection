using namespace std;
#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <cassert>
#include <ctime>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
#include <sstream>
#include <fstream>
#include <iterator>
#include <bitset>
#include <cstdlib>
#include <set>

template <class T> string toStr (T x){stringstream ss;ss << x;return ss.str();}
template <class T> long long toInt (T x){stringstream ss; ss << x; long long r; ss >> r; return r;}


#define FOR(i,a,b) for(int i = (a); i <(b); ++i)
#define foreach(x,v) for(typeof (v).begin() x = v.begin(); x != v.end(); ++x)
#define sz(x) (int)(x).size()
#define DEBUG
#ifdef DEBUG
#define REACH  cout<<" reached line "<<__LINE__<<endl
#define D(x) cout<<#x " is "<<(x)<<endl
#else
#define REACH
#define D(x)
#endif	
#define D2(x) cout<<#x " is "<<(x)<<endl
typedef long long ull; 

const ull MAXN = 100000000000000;

vector<string> all;

bool is_palin(string s) {
	int n = s.size();
	for (int i = 0; i < (n+1)/2; ++i) {
		if (s[i] != s[n-i-1]) return false;
	}
	return true;
}

string all2 [39] = {"1" , "4" , "9" , "121" , "484" , "10201" , "12321" , "14641" , "40804" , "44944" , "1002001" , "1234321" , "4008004" , "100020001" , "102030201" , "104060401" , "121242121" , "123454321" , "125686521" , "400080004" , "404090404" , "10000200001" , "10221412201" , "12102420121" , "12345654321" , "40000800004" , "1000002000001" , "1002003002001" , "1004006004001" , "1020304030201" , "1022325232201" , "1024348434201" , "1210024200121" , "1212225222121" , "1214428244121" , "1232346432321" , "1234567654321" , "4000008000004" , "4004009004004"};

ull solve(string n) {
	if (n == "-1") return 0;
	int ans = 0;
	while(ans < 39 and (toInt(all2[ans]) <= toInt(n))) {++ans;}
	return ans;
}

int main (){
	ios::sync_with_stdio(false);
	// for (ull x = 1; x*x <= MAXN; ++x) {
	// 	string a,b;
	// 	if (!(x%100000))
	// 	D(MAXN-x*x);
	// 	a = toStr(x);
	// 	b = toStr(x*x);
	// 	if (is_palin(a) and is_palin(b)) {
	// 		all.push_back(b);
	// 	}
	// }
	// cout<<all.size()<<endl<<"{";
	// for (int i = 0; i < all.size(); ++i) {
	// 	cout<<"\""<<all[i]<<"\" , ";
	// }
	// cout<<"}\n";

	int cases;
	cin>>cases;
	for (int cas = 1; cas <= cases; ++cas) {
		cout<<"Case #"<<cas<<": ";
	    ull a,b;
		cin>>a>>b;
		cout<<solve(toStr(b))-solve(toStr(a-1))<<endl;
	}
}
