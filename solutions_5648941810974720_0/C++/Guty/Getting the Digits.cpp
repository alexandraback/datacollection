#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <cmath>
#include <algorithm>
#include <cassert>
#include <tuple>
#include <functional>
#include <unordered_set>
#include <unordered_map>
#include <sstream>
#include <stdio.h>
#include <valarray>



#define forn(i,n) for(int i=0;i<(int)(n); i++)
#define forsn(i,s,n) for(int i=(s);i<(int)(n); i++)
#define esta(x,v) (find((v).begin(),(v).end(),(x)) !=  (v).end())
#define index(x,v) (find((v).begin(),(v).end(),(x)) - (v).begin())
#define debug(x) cout << #x << " = "  << x << endl

typedef long long tint;
typedef unsigned long long utint;
typedef long double ldouble; 

using namespace std;



void imprimirVector (vector<tint> v)
{
	if (!v.empty())
	{ 
		int p = v.size();
		cout << "[";
		forn(i,p-1)
			cout << v[i] << ",";
		cout << v[p-1] << "]" << endl;
	}
	else
		cout << "[]" << endl;
}

tint toNumber (string s)
{
	tint Number;
	if ( ! (istringstream(s) >> Number) ) Number = 0; // el string vacio lo manda al cero
	return Number;
}

string toString (tint number)
{    
    ostringstream ostr;
    ostr << number;
    return  ostr.str();
}




int main()
{
	#ifdef ACMTUYO
		assert(freopen("entrada.in", "r", stdin));
		assert(freopen("salida.out", "w", stdout));
	#endif
	ios_base::sync_with_stdio(0);
	tint t;
	cin >> t;
	forsn(caso,1,t+1)
	{
		string s;
		cin >> s;
		tint n = s.size();
		map<char,tint> c;
		forn(i,n)
			c[s[i]]++;
		vector<tint> ans(10);
		tint k = c['Z'];
		ans[0] = k;
		c['Z'] -= k;
		c['E'] -= k;
		c['R'] -= k;
		c['O'] -= k;
		k = c['W'];
		ans[2] = k;
		c['T'] -= k;
		c['W'] -= k;
		c['O'] -= k;
		k = c['U'];
		ans[4] = k;
		c['F'] -= k;
		c['O'] -= k;
		c['U'] -= k;
		c['R'] -= k;
		k = c['O'];
		ans[1] = k;
		c['O'] -= k;
		c['N'] -= k;
		c['E'] -= k;
		k = c['R'];
		ans[3] = k;
		c['T'] -= k;
		c['H'] -= k;
		c['R'] -= k;
		c['E'] -= k;
		c['E'] -= k;
		k = c['F'];
		ans[5] = k;
		c['F'] -= k;
		c['I'] -= k;
		c['V'] -= k;
		c['E'] -= k;
		k = c['X'];
		ans[6] = k;
		c['S'] -= k;
		c['I'] -= k;
		c['X'] -= k;
		k = c['S'];
		ans[7] = k;
		c['S'] -= k;
		c['E'] -= k;
		c['V'] -= k;
		c['E'] -= k;
		c['N'] -= k;
		k = c['G'];
		ans[8] = k;
		c['E'] -= k;
		c['I'] -= k;
		c['G'] -= k;
		c['H'] -= k;
		c['T'] -= k;
		k = c['I'];
		ans[9] = k;
		c['N'] -= k;
		c['I'] -= k;
		c['N'] -= k;
		c['E'] -= k;
		cout << "Case #" << caso << ": ";
		forn(i,10)
		forn(j,ans[i])
			cout << i;
		cout << endl;
		
		
		
	}
	return 0;
}



