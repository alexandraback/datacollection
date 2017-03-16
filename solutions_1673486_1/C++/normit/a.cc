#include <cstdio>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>

#define mp make_pair
#define pb push_back

#define REP(i,n) for(int i=0; i < (n); ++i)

typedef long long ll;

using namespace std;

void solve()
{
	int a,b;
	double p[100000];

	cin >> a >> b;
	REP(i,a) {
		cin >> p[i];
	}

	// retype
	double min_prob = b+2;

	double correct_prob = 1.0;

	REP(i,a) {
		correct_prob *= p[i];

		int delete_cost = (a-i-1);
		int type_cost = b-i;
		int retype_cost = b+1;

		
		double expect = correct_prob * (delete_cost + type_cost) 
		+ (1-correct_prob) * (delete_cost + type_cost + retype_cost);
		//cout << expect << endl;
		if(expect < min_prob) {
			min_prob = expect;
		}
	}

	printf("%.6lf\n", min_prob);

}

int main(int argc, char *argv[])
{
	int t;
	cin >> t;
	for(int i = 1; i <= t; ++i) {
		cout << "Case #" << i << ": ";
		solve();
	}
	return 0;
}

