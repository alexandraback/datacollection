#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <sstream>
#include <stdio.h>
#include <math.h>
#include <bitset>
#include <string> 
#include <iomanip> // za setprecision() !!
#include <cmath> // za abs()
 
#define FOR(i,n) for(int i=0,_n=n;i<_n;i++)
#define FORR(i,s,n) for(int i=s,_n=n;i<_n;i++)
#define mp make_pair
#define vi vector<int>
#define fs first
#define sec second
#define pii pair<int,int>

using namespace std;

int main (){
int t111;
cin >> t111;
long long n;
long double c, f, x, t,tmin;
long double co=0.00000001;
cout << fixed;
cout << setprecision(8);
for (int i111=0 ; i111<t111; i111++){
	cin >> c >> f >> x;
	n=0;
	t=0;
	tmin=x/2;
	while (true){
		t+=c/(2+n*f);
		if (t+x/(2+(n+1)*f)<tmin )
			tmin = t+x/(2+(n+1)*f);
		else
			break;
		//cout << t+x/(2+(n+1)*f) << "  " << tmin << endl;
		n++;
		}
	
	cout << "Case #"<< i111 +1 << ": " << tmin << endl;
	}
return 0;
}
