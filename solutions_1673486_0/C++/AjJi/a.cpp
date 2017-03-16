#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,a) for(int i=0;i<(a);i++)
#define ALL(i) i.begin(),i.end()
#define rALL(i) i.rbegin(),i.rend()
#define PB push_back

typedef vector<int> vi;
typedef vector<vector<int> > vvi;

template<class T> string i2a(T x) {ostringstream oss; oss<<x; return oss.str();}

void printvec(vector<int> a)
{
 cout<<"Vecteur:  ";
 REP(i,a.size()) cout<<a[i]<<"  ";
 cout<<endl;
}

bool ok(string s) {
	REP(i,s.size()) if(s[i]=='X') return false;
	return true;
}

int main()
{

   freopen("A-small-attempt2.in","r",stdin);
   freopen("output-aa.out","w",stdout);


	int cases;
	cin>>cases;
	REP(k,cases) {
		int a, b;
		cin>>a>>b;
		vector<double> p;
		REP(i,a) {
			double  tmp;
			cin>>tmp;
			p.PB(tmp);
		}

		vector<double> probs;
		vector<string> ss;
		for(int i = 0; i < 1<<p.size(); i++) {
			double prod = 1.0;
			string tmp="";
			for(int j = 0; j <(int)p.size();j++) {

				if(i & 1<<j) {
					prod *= p[j];
					tmp+="a";
				} else {

					prod *= (1 - p[j]);
					if(p[j] == 1) tmp+="a";
					else tmp+="X";
				}
			}
			ss.PB(tmp);
			probs.PB(prod);
		}

		if(a == 1) {
			//keep

			//back1

			//press
		} else if(a == 2) {
			//keep

			//back1

			//back2

			//press
		} else if(a == 3) {
			//keep

			//back1

			//back2

			//back3

			//press
		}


		int x = 1 + b + 1;
		double res = 0;
		//REP(i,probs.size()) cout<<probs[i]<< " ";
		//cout<<endl;

		REP(i,(int)probs.size()) {
			res += probs[i]*x;
		}

		x = b - a + 1;
		int z = b + 1;

		double good = 1.0;
		double res2 = 0.0;
		REP(i,(int)p.size()) {
			if(p[i] == good) res2 += x;
			else res2 += x + z;
		}

		double rest = -1;
		for(int back = 0; back <= a - 1; back++) {

			double rt = 0.0;
			for(int i = 0; i < (int)ss.size(); i++) {
				int x = back;
				string t = ss[i].substr(0, ss[i].size() - back);
				//cout<<"back="<<back<<" ss="<<ss[i]<<" t="<<t<<endl;
				if(ok(t) == false) {
					x += back + 1 + b - a + b + 1;
				} else x += back + 1 + b - a;
			//	printf("x=%d\n", x);
				rt += x*probs[i];
			}
			//cout<<"rt="<<rt<<endl;
			if(rest == -1) rest = rt;
			else rest = min(rt, rest);
		}

		if(rest == -1) rest = max(res, res2) + 1;
		printf("Case #%d: %.6lf\n",k+1,min(min(res,res2),rest));

	}


    return 0;
}
