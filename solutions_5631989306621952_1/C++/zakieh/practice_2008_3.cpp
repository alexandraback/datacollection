#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <iostream>


using namespace std;

#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
#define INF (1<<29)


int main()
{
	int i;
	int numCase;
	int f;
	int m;
	int flavor;
	int customer;



	cin >> numCase;
	string s;
	for (int ii = 1; ii <= numCase; ii++) {

		cout << "Case #" << ii <<": ";

		cin >> s;
		char chars[s.length()];
		char chars2[s.length()];

		string fin = "";
		fin = s[0];
		
		for (i = 1 ; i < s.length(); i++) {
			if (s[i] >= fin[0]) {
				fin = s[i] + fin;
			}
			else {
				fin = fin + s[i];
			}

		}
		cout << fin << endl;

	}
	

}