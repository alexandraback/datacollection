#include <functional>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <numeric>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <string>
#include <cstdio>
#include <vector>
#include <deque>
#include <cmath>
#include <list>
#include <set>
#include <map>
#define rep(i,m,n) for(int i=(m),_end=(n);i < _end;++i)
#define repe(i,m,n) for(int i=(m), _end =(n);i <= _end;++i)
typedef long long ll;
using namespace std;


int sol(ifstream& sr) {
	int n;

	static int d[1001];

	memset(d, 0, sizeof(d));

	sr >> n;
	for (int i = 0; i < n; i++)
	{
		int t;
		sr >> t;
		for (int j = 1; j < t; j++)
		{
			d[j] += (t + j - 1) / j - 1;
		}
	}
	int r = 1000;
	for (int i = 1; i < 1001; i++)
	{
		r = std::min(r, i + d[i]);
	}

	return r;
}

int main(){

	ifstream sr = ifstream("D:\\in.in");
	ofstream sw = ofstream("D:\\out.out");

	int T;
	sr >> T;
	for (int i = 0; i < T; i++)
	{
		sw << "Case #" << i + 1 << ": " << sol(sr) << endl;
		cout << i << endl;
	}
	sr.close();
	sw.close();
	cout << "FINISHED type a number and enter to exit";
	cin >> T;

	return 0;
}
