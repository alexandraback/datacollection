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

vector< tint > v,vfs;
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
	return res;
}
bool palindrome(tint t)
{
	ostringstream ss; ss << t;
	string s = ss.str();
	return s == reverse(s);
}
void precalc()
{
	v.clear();
	vfs.clear();

	v.push_back(1);
	v.push_back(2);
	v.push_back(3);

	forsn(i,1,1 << 7){
		string t = build(i);
		string trev = reverse(t);
		v.push_back(output(t + trev));
		forn(j,3){
			v.push_back(output(t + digs[j] + trev));
		}
	}

	string s = "2";
	forn(i,7){
		string t = reverse(s);
		v.push_back(output(s + t));
		forn(j,2){
			v.push_back(output(s + digs[j] + t));
		}
		s += "0";
	}

	sort(v.begin(),v.end());	
	forn(i,v.size()){
		tint p = v[i]*v[i];
		if(palindrome(p))
			vfs.push_back(p);
	}
}

int solve(tint A, tint B)
{
	return lower_bound(all(vfs),B+1) - lower_bound(all(vfs),A);
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
