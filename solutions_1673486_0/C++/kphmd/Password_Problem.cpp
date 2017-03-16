#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

void solve();
void runCase();

double p[100000];

double get(int A) {
	double res = 1.0;
	for(int i = 0; i < A; i++) {
		res*=p[i];
	}
	return res;
}

double c1(int A,int B) {
	double res = 0;
	double P = get(A);
	res = P*(B-A+1)+(1.0-P)*(B-A+1+B+1);
	return res;
}

double c3(int A,int B) {
	double res = 0;
	double P = get(A);
	res = B+2.0;
	return res;
}

double c2(int A,int B,int i) {
	double res = 0;
	double P = get(A-i);
	res = P*(i+B-A+i+1)+(1.0-P)*(i+B-A+i+1+B+1);
	return res;
}

void runCase()
{
	int A,B;
	scanf("%d%d",&A,&B);
	for(int i = 0; i < A; i++) scanf("%lf",&p[i]);

	double res = B*10;

	double t = 0;
	t = c1(A,B);
	if(res>t) res = t;

	t = c3(A,B);
	if(res>t) res = t;

	for(int i = 1; i <= A; i++) {
		t = c2(A,B,i);
		if(res>t) res = t;
	}


	printf("%lf\n",res);
}

void solve()
{
	int n;
	scanf("%d",&n);
	getchar();
	
	for(int i = 0; i < n; i++) {
		printf("Case #%d: ",i+1);
		runCase();
	}
}

int main()
{
	solve();
	return 0;
}
