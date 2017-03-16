#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
#include <map>
using namespace std;

typedef long long LL;
typedef unsigned int UINT32;

int A, B;
vector<double> ps;

double case1()
{
    double p = 1;
    for (int i = 0; i < A; ++i) {
        p *= ps[i];
    }

    double ans =  B-A+1 + (1-p)*(B+1);
	//cerr << ans << endl;
	return ans;
}

double case2()
{
    double ans = 2*(B+1) + 100000;
    double p = 1;
    for (int n = 0; n<=A; ++n) {
        double t = A-n + B-n+1 + (1-p) * (B+1);
		//cerr << t << endl;
        if (t < ans) ans = t;
        p *= ps[n];
    }
    return ans;
}

double case3()
{
    double ans = 1 + B + 1;
	//cerr << ans << endl;
	return ans;
}

string calc()
{
    cin >> A >> B;
    ps.resize(A);
    for (int i = 0; i < A; ++i) {
        cin >> ps[i];
    }

    //double ans = case1();
    double ans = case2();
    //if (t < ans) ans = t;
    double t = case3();
    if (t < ans) ans = t;

	/*
	stringstream SS;
	SS << ans;
	return SS.str();
	*/

	LL v = ans * 100000000;

    stringstream S;
	S << v%100000000;
	string p = S.str();
	if (p.length() < 8) p = string(8 - p.length(), '0') + p;

    stringstream S1;
    S1 << v/100000000 << "." << p;
    return S1.str();
}

int main(void)
{
	int N;
	cin >> N;

    // NOTE: if using getline() to read the input, the following two lines should be
    // added to read the line sepeartor in the first line. 
    //string line;
    //getline(cin, line);
	for (int i=1; i<=N; ++i) {
		cout << "Case #" << i << ": " << calc() << endl;
	}

	return 0;
}
