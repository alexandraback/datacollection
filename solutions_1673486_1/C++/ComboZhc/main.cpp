#include <iostream>
#include <cstdio>
#include <fstream>
#include <iomanip>


using namespace std;

ifstream in("test.txt");
FILE* out = fopen("answer.txt", "w");
double a[200000];

void doit(int t) {
	int A, B;
	in >> A >> B;
	for (int i = 0; i < A; i++)
		in >> a[i];
	double ans = B + 2;
	double p = 1;
	//for (int i = 0; i < A; i++) {
	//	p *= a[i];
	//}
	//double nowAns = p * (B - A + 1) + (1 - p) * (2 * B - A + 2);
	//if (nowAns < ans)
	//	ans = nowAns;
	double nowAns;
	for (int start = 0; start < A; start++) {
		p *= a[start];
		nowAns = (1 - p) * (A - (start + 1) + B - (start + 1) + B + 2)
			+ p * (A - (start + 1) + B - (start + 1) + 1);
		if (nowAns < ans)
			ans = nowAns;
	}
	fprintf(out, "Case #%d: %.6lf\n", t, ans);
}

int main() {
	int T;
	in >> T;
	for (int t = 1; t <= T; t++) {
		doit(t);
	}
	return 0;
}