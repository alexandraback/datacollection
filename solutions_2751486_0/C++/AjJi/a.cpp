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

#define FOR(i,a,b) for(int i=(a);i<(int)(b);i++)
#define REP(i,a) for(int i=0;i<(int)(a);i++)
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

int main()
{

   freopen("A-small-attempt1.in", "r", stdin);
   freopen("A-small-attempt1.out", "w", stdout);

	int cases;
	string s;
	getline(cin, s);
	sscanf(s.c_str(), "%d",&cases);
	REP(k, cases) {
		printf("Case #%d: ", k + 1);
		getline(cin, s);
		stringstream st;
		st<<s;
		string str;
		int n;
		st>>str>>n;
		int count = 0;
		REP(i,str.size()) {
			char c = str[i];
			if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u') {
				str[i] = ' ';
			}
		}
		for(int i = 0; i < (int)str.size(); i++) {
			for(int j = i; j < (int)str.size(); j++) {
				string tmp;
				for(int m = i; m <= j; m++) {
					tmp.PB(str[m]);
				}
				stringstream st2;
				st2<<tmp;
				string r;
				while(st2>>r) {
					if((int)r.size() >= n) {
						count++;
						break;
					}
				}
			}
		}
		printf("%d\n", count);
	}
    return 0;
}
