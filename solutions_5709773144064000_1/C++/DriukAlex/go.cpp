#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

void solveCase(int t) {
	double C, F, X;
	cin>>C>>F>>X;
	double mintime = X / 2;
	double curtime = C / 2;
	int ferms = 1;
	while (curtime + X / (2 + ferms * F) < mintime) {
		mintime = curtime + X / (2 + ferms * F);
		curtime += C / (2 + ferms * F);
		ferms++;
	}
	printf("Case #%d: %.7lf\n",t+1,mintime);
}

int main()
{
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
	int t;
	cin>>t;
	for (int i=0;i<t;++i) {
		solveCase(i);
	}
	return 0;
}