#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <queue>
#include <map>
#include <string>
#include <vector>

#define forn(i,n) for(int i = 0; i < (n); i++)
#define forsn(i,s,n) for(int i = (s); i < (n); i++)
#define pb push_back
#define mp make_pair

typedef long long int tint;

using namespace std;

tint mcd(tint a, tint b){ return (a==0)?b:mcd(b % a,a);}

int pot2(tint x)
{
	forn(i,50){
		if(x == (1LL<<i)){ return i; }
	}
	return (-1);
}

int get2(tint y)
{
	forn(i,50){
		if(y >= (1LL<<i) and y < (1LL<<(i+1))){ return i; }
	}
	return (-1);
}

int main()
{
	int t;
	tint p,q;
	cin >> t;
	char c;
	forn(caso,t){
		cin >> p >> c >> q;
		tint d = mcd(p,q);
		p /= d;
		q /= d;
		//cout << p << " " << q << " " << d << endl;
		int pot = pot2(q);
		/*if(pot != -1 and (1LL<<pot) != q){
			cout << pot << " " << q << " " << (1LL<<pot) << endl;
		}*/
		cout << "Case #" << (caso+1) << ": ";
		if(pot == -1){
			cout << "impossible" << endl;
		}
		else{
			cout << ( pot - get2(p) ) << endl;
		}
	}
	return 0;
}
