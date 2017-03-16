#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <set>
#include <map>
#include <cctype>
#include <cmath>
#include <iomanip>
using namespace std;

#define UN(c) SORT(c),v.erase(unique(c.begin(),c.end()),c.end())
#define SORT(c) sort(c.begin(), c.end())

int sc[200];
int ex[200];
double ans[200];

int main()
{
	if( freopen("A-large.in", "rt", stdin) ) {
		freopen("A-large.out", "wt", stdout);
	} else 	if( freopen("A-small.in", "rt", stdin) ) {
		//freopen("A-small.out", "wt", stdout);
	} else ( freopen("test.txt", "rt", stdin) );

	int T;
	cin >> T;
	//cerr << "Total test cases: " << T << endl;

	for(int case_num = 1; case_num <= T; ++case_num)
	{
		//cerr << '#' << case_num << endl;
		int N;
		cin >> N;
		int max = 0, total = 0;
		for(int i = 0; i < N; ++i) {
			cin >> sc[i];
			total += sc[i];
			if(sc[i] > max) max = sc[i]; 
		}
		int exs = 0;
		for(int i = 0; i < N; ++i) {
			ex[i] = max - sc[i];
			exs += ex[i];
		}
		double mmm = 1.0 * (total - exs) / N;
		double negsum = 0;
		int p = 0;
		for(int i = 0; i < N; ++i) {
			ans[i] = (mmm + ex[i]) / total;
			if(ans[i] < 0.0) negsum += ans[i];
			else ++p;
		}
		if(negsum < 0.0) for(int i = 0; i < N; ++i) {
			if(ans[i] < 0.0) ans[i] = 0.0;
			else ans[i] += negsum / p;
		}
		cout << "Case #" << case_num << ": ";
		for(int i = 0; i < N-1; ++i) {
			cout << setprecision(6) << 100 * ans[i] << ' ';
		}
		cout << setprecision(6) << 100 * ans[N-1] << endl;
	}
 	return 0;
}