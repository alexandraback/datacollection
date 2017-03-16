#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <cstring>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <numeric>
#include <cassert>
#include <iomanip>
using namespace std;
static const double EPS = 1e-9;
static const int mod = 100000007;
typedef long long ll;

string IntToString(int number){
	stringstream ss;
	ss << number;
	return ss.str();
}

int main() {
	// freopen ("input.txt", "r", stdin);
	// freopen ("output.txt", "w", stdout);
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		string res="Case #"+IntToString(i+1)+": ";
		double c,f,x;
		cin>>c>>f>>x;
		double s1=2.0,ans=x/s1;
		double now=0.0;

		for(int i=0;i<100000;i++){
			now+=c/s1;
			s1+=f;
			ans=min(ans,now+x/s1);
		}
		cout<<res;
		printf("%.7f\n",ans);
	}
}