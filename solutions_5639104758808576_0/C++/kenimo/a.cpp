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
typedef pair<int,int> P;

void run()
{
	int s;
	string sh;
	cin >> s >> sh;
	int ret=0;
	int sum=0;
	for(int i=0;i<=s;i++){
		if(sum<i&&sh[i]!='0'){
			ret+=i-sum;
			sum=i;
		}
		sum+=sh[i]-'0';
	}
	cout << ret << endl;
}


int main() {
	int T;
	cin >> T;
	for (int t=1;t<=T;t++) {
		cout << "Case #" << t << ": ";
		run();
	}
}
