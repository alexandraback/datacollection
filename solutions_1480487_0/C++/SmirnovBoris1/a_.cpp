#pragma comment (linker, "/STACK:64000000")
#include <memory.h>
#include <cstdio> 
#include <sstream> 
#include <iostream> 
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <algorithm>
#include <cstring>
#include <list>
#include <cmath>

using namespace std;

//485271451

typedef long long lint;
typedef pair<int,int> pii;
#define pb push_back
#define sz(a) (int)((a).size())


void prepare(string s){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
}

double a[1000];


bool solve(){

	int T;
	cin >> T;
	for (int test = 0; test < T; ++ test)
	{
		int n;
		cin >> n;
		double X = 0.;
		for (int i = 0; i < n; ++ i)
		{
			cin >> a[i];
			X += a[i];
		}

		cout << "Case #" << test + 1 << ":";
		for (int i = 0; i < n; ++ i)
		{
		
			double left = 0.;
			double right = 1.;

			for (int iter = 0; iter < 100; ++ iter)
			{
				double m = (left+right) / 2.;
				double p = 1. - m;
				for (int j = 0; j < n; ++ j)
				{
					if (i != j && a[j] < a[i] + X * m)
						p -= (a[i] + X * m - a[j]) / X;
				}

				if (p > 0.)
					left = m;
				else
					right = m;
			}
			printf(" %.20lf", left * 100.);
		}
		cout << endl;
	}

	return false;
}

int main(){

	prepare("");
	while (solve());



	return 0;
}