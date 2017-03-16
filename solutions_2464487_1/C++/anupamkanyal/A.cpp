
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdlib>
#include<queue>
#include<map>
#include<set>
#include<string>
#include<sstream>
#include<climits>
#include<vector>
#include<cstring>
#include<stack>

using namespace std;

#define REP(i,s,n)  for (int i=(s),_n=(n);i<=_n;i++)
#define FOR(i,s,n)  for (int i=(s),_n=(n);i<_n;i++)
#define REPD(i,e,s)  for (int i=(e),_s=(s);i>=_s;i--)
#define tr(container, it) \
	for (typeof(container.begin()) it=container.begin(); it!=container.end();it++)
#define PB push_back
#define MP make_pair

typedef long long LL;

double r;
double func(double x) {
	double a=2*r+1;
	double d=4;
	return (x*(2*a+(x-1)*d))/2.0;
}

int main() {
	int t;
	cin >> t;
	REP(tc,1,t) {
		double t;
		cin >> r >> t;
		int low=0,high=(int)1e18;
		double res=0.0;
		int tmp=2000;
		while (tmp--) {
			int mid=low+(high-low)/2.0;
			if (func((double)mid)<=t) {
				//almost exact match
				low=mid+1.0;
				res=max(res,(double)mid);
			}
			else
				high=mid-1.0;
		}
		cout << "Case #" << tc << ": " << (long long)res <<  endl;
	}
	return 0;
}
