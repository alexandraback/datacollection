#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <sstream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
using namespace std;

int A, B;
vector<double> v;

double give_up()
{
	double ret = 1 + B + 1;
	return ret;
}

int main()
{
	int T; cin >> T;
	for (int tt = 1; tt <= T; ++tt)
	{
		cout << "Case #" << tt << ": ";
		
		cin >> A >> B;
		v.resize(A+1); v[0] = 1.0;
		for (int i = 0; i < A; ++i) cin >> v[i+1];
		for (int i = 1; i <= A; ++i) v[i] *= v[i-1];
		
		double ret = give_up(), rr, rp;
		for (int i = 0; i <= A; ++i)
		{
			rr = i + (v[A-i]*(B-A+i+1)) + ((1-v[A-i])*(B-A+i+1+B+1));
			ret = min(ret, rr);
		}
		
		printf("%.8f\n", ret);
	}
}

