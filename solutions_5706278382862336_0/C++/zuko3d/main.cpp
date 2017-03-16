#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

#define FOR(i, a, b) for (int i(a), _b(b); i <= _b; ++i)
#define REP(i, n) for (int i(0), _n(n); i < _n; ++i)

template<class T> inline T gcd(T a,T b)//NOTES:gcd(
  {if(a<0)return gcd(-a,b);if(b<0)return gcd(a,-b);return (b==0)?a:gcd(b,a%b);}

long long toInt64(string s){long long r=0;istringstream sin(s);sin>>r;return r;}//NOTES:toInt64(

int main(void){
	int T, good;
	string s;
	ifstream fin("A-small-attempt0.in");
	ofstream fout("out.txt");

	fin >> T;

	REP(t, T){
		long long p, q, g, i, w;
		int z,x;
		fout << "Case #" << t+1 << ": ";
		double pq, pqq;

		//fin >> p >> q;
		fin >> s;
		z = s.find('/');
		p = toInt64(s.substr(0, z));
		q = toInt64(s.substr(z+1));

		g = gcd(p, q);
		p/=g;
		q/=g;
		pq = (double) p;
		pq /= (double) q;

		cout << p << " " << q << endl;

		good = 0;
		i = 2;
		for(w=1 ; w<=40;w++){
			if(i == q){
				good = 1;
				break;
			}
			i*=2;
		}
		if(!good) {
			fout << "impossible" << endl;
			continue;
		}

		pqq = 1;
		i = 0;
		while(pqq > pq){
			pqq /= 2.0;
			i++;
		}
		if(i <= 40){
			fout << i << endl;
		} else {
			fout << "impossible" << endl;
		}
	};


	fout.close();
	return 0;
}
