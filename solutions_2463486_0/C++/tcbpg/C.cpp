#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;
#define forn(i,n) for(int i=0;i<(int)(n);i++)
#define forsn(i,s,n) for(int i=(int)(s);i<(int)(n);i++)
#define dforn(i,n) for(int i=((int)(n)-1);i>=0;i--)
#define all(v) (v).begin(),(v).end()

typedef long long tint;

vector< tint > v;
string build(int i)
{
	string res = "";
	for(;i > 0; i >>= 1){
		res = ((i & 1) ? "1" : "0") + res;
	}
	return res;
}
string reverse(string & s)
{
	string t = s;
	reverse(t.begin(),t.end());
	return t;
}
string digs[] = { "0", "1", "2" };
tint output(const string & s)
{
	tint res; istringstream ss(s);
	ss >> res;
	return res*res;
}
void precalc()
{
	v.push_back(1);
	v.push_back(4);
	v.push_back(9);

	forsn(i,1,1 << 8){
		string t = build(i);
		string trev = reverse(t);
		v.push_back(output(t + trev));
		forn(i,3){
			v.push_back(output(t + digs[i] + trev));
		}
	}

	forn(i,8){
		string s = "2";
		forn(j,i) s += "0";
		string t = reverse(s);
		v.push_back(output(s + t));
		forn(i,2){
			v.push_back(output(s + digs[i] + t));
		}
	}

	sort(v.begin(),v.end());	
}

int solve(tint A, tint B)
{
	return lower_bound(all(v),B+1) - lower_bound(all(v),A);
}

int main()
{
	precalc();

	int tcases; cin >> tcases;
	forsn(tcase,1,tcases+1){
		tint a,b; cin >> a >> b;
		cout << "Case #" << tcase << ": " << solve(min(a,b),max(a,b)) << endl;
	}
	return 0;	
}
