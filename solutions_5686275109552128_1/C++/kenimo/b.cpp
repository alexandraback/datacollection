#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <map>
#include <list>
#include <set>
#include <numeric>
#include <queue>
#include <stack>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <climits>
#include <cfloat>
#include <ctime>
#include <complex>
#include <cassert>
#include <iomanip>
using namespace std;
typedef long long LL;

int P[1000];
void run()
{
	int D;
	cin >> D;
	for(int i=0;i<D;i++){
		cin >> P[i];
	}
	int ret=1000;
	for(int i=1;i<=1000;i++){
		int sum=i;
		for(int j=0;j<D;j++){
			sum+=(P[j]-1)/i;
		}
		ret=min(ret, sum);
	}

	cout << ret << endl;
}


int main() {
	int TotalCase;
	cin >> TotalCase;
	for (int Case=1;Case<=TotalCase;Case++) {
		cout << "Case #" << Case << ": ";
		run();
	}
}
