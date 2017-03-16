#include <iostream>
#include <vector>
#include <set>
#include <memory.h>
#include <map>
#include <algorithm>
#include <string>
using namespace std;

int v[66666];
int s = 0;
int n;

double bs(int x) {
	double c,l=0,r=100;
	while (fabs(l-r)>10e-12) {
		c = (l+r)/2.0;
		double my = v[x] + c * s;
		double ot = 0;
		for (int i=0;i<n;i++) if (i!=x && my>v[i]) ot+=(my-v[i]);
		ot/=s;
		if (1-c>ot) l=c; else r=c;
	}
	return (l+r)*50.0;
}

int main() {
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	int t;
	cin >> t;
	for (int z=1;z<=t;z++) {
		
	cin >> n;
	s = 0;
	for (int i=0;i<n;i++) {
		cin >> v[i];
		s+=v[i];
	}
	cout << "Case #" << z << ": ";
	for (int i=0;i<n;i++) {
		printf("%.20lf ",bs(i));
	}
	cout << endl;
	}
}