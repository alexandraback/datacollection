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
#define saludo cout << "HOLAA" << endl;

int main(){
	freopen("1A-A.in","r",stdin);
	freopen("1A-A.out","w",stdout);
	int t;
	cin >> t;
	forn(i,t){
		int a, b;
		cin >> a >> b;
		double correct[a];
		forn(j,a)
			scanf("%lf",&correct[j]);
		double exp[a + 1];
		exp[0] = b + 1;
		double ps = 1;
		forsn(j, 1, a + 1){
			ps *= correct[j - 1];
			double d1 = ps * (b + 1 - j) + ((1 - ps) * (2 * b + 2 - j));
			exp[j] = min(d1, exp[j - 1] + 1);
		}
		cout << "Case #" << i + 1 << ": ";
		if(exp[a] > b + 2){
			printf("%.5lf",double(b + 2));
		}else{
			printf("%.5lf",exp[a]);
		}
		cout << endl;
	}
}
