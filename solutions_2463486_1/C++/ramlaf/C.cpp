#include <iomanip>
#include <algorithm>
#include <numeric>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <cstring>
#include <complex>
#include <cassert>
#include <bitset>
using namespace std;

#define forn(i,n) for(int i=0;i<(int)(n);i++)
#define si(c) ((int)(c).size())
#define forsn(i,s,n) for(int i = (int)(s); i<((int)n); i++)
#define dforsn(i,s,n) for(int i = (int)(n)-1; i>=((int)s); i--)
#define decl(v, c) typeof(c) v = c
#define forall(i, c) for(decl(i, c.begin()); i!=c.end(); ++i)
#define dforall(i, c) for(decl(i, c.rbegin()); i!=c.rend(); ++i)
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define D(a) cout << #a << "=" << a << endl;
#define pb push_back
#define mp make_pair

typedef long long int tint;

vector<string> S;

string operator*(const string s, const string t) {
	int d = si(s);
	string res;
	for(int k = 0; k<2*d-1; k++) {
		int sum = 2*d-2 - k;
		int a = 0;
		forn(i,d) forn(j,d) if (i+j == sum)	a+= (s[i]-'0')*(t[j]-'0');
		res+= a+'0';
	}
	return res;
}	

void add(string a, char c) {
	if (c=='p')	 {
		string tmp = a;
		for(int i = si(a)-1; i>=0; i--)	tmp+= a[i];
		S.pb(tmp);
	}
	else {
		string tmp = a;
		for(int i = si(a)-2; i>=0; i--)	tmp+= a[i];
		S.pb(tmp);	
	}
}

bool cmp(string s, string t) {
	if (si(s)<si(t)) return true;
	if (si(s) == si(t) && s<=t) return true;
	return false;
}

tint contar(string A) {
	tint st = 0, end = si(S)-1;
	while(end-st>1)	{
		tint mid = (end+st)/2;
		if (cmp(S[mid]*S[mid],A)) st = mid;
		else end =mid;	
	}
	if (st == end) return st; 
	if (st+1 == end) {
		if (cmp(S[end]*S[end],A)) return end; 
		else return end-1; 	
	}
}

int main () {
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
	
	
	S.pb("1"); S.pb("2"); S.pb("3");
	forsn(d,1,26) {
		string a; forn(i,d) a+="0";
		
		a.replace(0,1,"2"); add(a,'p');
		add(a+"0",'i'); 
		add(a+"1",'i');
		
		a.replace(0,1,"1"); add(a,'p');
		add(a+"0",'i');
		add(a+"1",'i'); 
		add(a+"2",'i');
		
		forsn(i1,1,d){
			a.replace(i1,1,"1"); add(a,'p'); add(a+"0",'i'); add(a+"1",'i'); add(a+"2",'i');
			forsn(i2,i1+1,d) {
				a.replace(i2,1,"1"); add(a,'p'); add(a+"0",'i'); add(a+"1",'i');
				forsn(i3,i2+1,d) {
					a.replace(i3,1,"1"); add(a,'p'); add(a+"0",'i'); add(a+"1",'i');	
					a.replace(i3,1,"0");
				}
				a.replace(i2,1,"0");
			}			
			a.replace(i1,1,"0");
		} 
		
	}
	sort(S.begin(),S.end(),cmp);
	
//	cout << (string)"20102"*(string)"20102" << endl;
//	forn(i,si(S)) cout << S[i]*S[i] << endl;
	
//	cout << S[1] << " "<< S[1]*S[1] << " " <<cmp(S[1]*S[1],"4")<<endl;
	
	int T; cin >> T;
	forn(caso,T) {
		string A,B;
		cin >> A >> B;		
		tint cb = contar(B), ca = contar(A);
		tint ans = cb-ca;
		
		if (S[ca]*S[ca]==A) ans++;
		cout << "Case #" << caso+1 << ": " << ans << endl;
	//	cout << contar(B) << " " << contar(A) << endl;
	}

	return 0;
}
