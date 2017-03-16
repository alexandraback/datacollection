#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <stack>
#include <set>
#include <list>
#include <sstream>
#include <map>
#include <limits>

using namespace std;

int T, A, B;
double c1[1000000];

int main() {
	cin>>T;
	for(int t=1; t<=T; t++)
	{
		double ans = 999999999999.0;
		cin>>A>>B;
		c1[0] = 1.0;
		for(int i=1; i<=A; i++)
		{
			cin>>c1[i];
			c1[i] = c1[i-1]*(double)c1[i];
		}
		ans = min(ans, c1[A]*(B-A+1) + (1.0-c1[A])*(B-A+1+B+1));
		for(int i=0; i<=A; i++) {
			//cout<<c1[i]*(B-A+1+2*(A-i)) + (1.0-c1[i])*(B-A+1+B+1+2*(A-i))<<endl;
			ans = min(ans, c1[i]*(B-A+1+2*(A-i)) + (1.0-c1[i])*(B-A+1+B+1+2*(A-i)));
		}
		ans = min(ans, B+2.0);
		cout.setf(ios::floatfield, ios::fixed);
		cout.precision(9);
		cout<<"Case #"<<t<<": "<<ans<<endl;
	}

	return 0;
}