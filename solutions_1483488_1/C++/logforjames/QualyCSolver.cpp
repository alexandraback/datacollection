#include <iostream>
#include <cstdio>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;

#define forsn(i,s,n) for(int i = (s);i < (int)(n);i++)
#define forn(i,n) forsn(i,0,n)
#define dforsn(i,s,n) for(int i = (n - 1);i >= 0;i--)
#define dforn(i,n) dforsn(i,0,n)
#define esta(x,c) (c.find(x) != c.end())
#define all(v) v.begin(),v.end()

int value[2000001];
int hashr[2000001];

int hash(int i, int base){
	if(hashr[i] != -1) return hashr[i];
	int man = i;
	int orig = i;
	do{
		int moved = 1;
		int m;
		do{
			moved *= 10;
			m = i % moved;
		}while(m == 0);
		i = (int)(i / moved) + ((base / moved) * m);
		man = min(man, i);
	}while(i != orig);
	hashr[i] = man;
	return man;
}

int main(){
	forn(i, 2000001) hashr[i] = -1;
	freopen("QualyC.in","r",stdin);
	freopen("QualyC.out","w",stdout);
	int t;
	cin >> t;
	forn(i,t){
		forn(j, 2000001){ value[j] = 0;}
		int a, b;
		cin >> a >> b;
		int base = 1;
		do{
			base *= 10;
		}while(base <= a);
		forsn(j,a,b+1){
			int h = hash(j, base);
			if(h < 2000001){
				value[h]++;
			}
		}
		long long int tot = 0;
		forn(j,2000001){
			tot += ((value[j] * (value[j] - 1)) / 2);
		}
		cout << "Case #" << i + 1 << ": " << tot << endl;
	}
}
