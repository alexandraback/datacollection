#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <assert.h>
#include <math.h>
#include <string.h>
#include <gmpxx.h>
#include <iostream>
using namespace std;
typedef vector<int> VI;
typedef pair<int,int> PII;
typedef vector<PII> VPII;
typedef long long ll;
#define FOREACH(it,vec) for(typeof((vec).begin()) it = (vec).begin(); it != (vec).end(); it++)
#define MOD(a,b) (((a)%(b)+(b))%(b))
#define REP(i,n) for (int i = 0; i < (n); i++)

int T;
char str[1000];

int M;

bool ispal(const mpz_class &S) {
	vector<int> digs;
	mpz_class tmp = S;
	while(tmp > 0) {
		digs.push_back(mpz_class(tmp%10).get_si());
		tmp /= 10;
	}
	for (int i = 0; i < (int)digs.size(); i++)
		if (digs[i] != digs[digs.size()-1-i])
			return false;
	return true;
}

vector<mpz_class> fairsqs;
int calls = 0, fails = 0;

int digm[200];
char strm[200];
void searchrec(int j) {
	for (int i = 0; i <= 2*M; i++) {
		int hi = 0;
		for (int k = 0; k <= i; k++) {
			if (k >= M || i-k >= M)
				continue;
			if (k >= j && k < M-j)
				continue;
			if (i-k >= j && i-k < M-j)
				continue;
			hi += digm[k]*digm[i-k];
		}
		if (hi >= 10)
			return;
	}
	calls++;
	if (j > 0 && digm[0] == 0)
		return;
	strm[M] = 0;
	for (int jj = 0; jj < M; jj++) {
		if (jj < j || jj >= M-j)
			strm[jj] = digm[jj]+'0';
		else
			strm[jj] = '0';
	}
	if (2*j >= M) {
		if (ispal(mpz_class(strm)*mpz_class(strm))) {
			fairsqs.push_back(mpz_class(strm)*mpz_class(strm));
			//if (mpz_class(strm) < 1E9)
				//cout << "fair square " << mpz_class(strm) << "^2 = " << mpz_class(strm)*mpz_class(strm) << endl;
		} else
			fails++;
		return;
	}
	for (digm[j] = 0; digm[j] < 10; digm[j]++) {
		digm[M-1-j] = digm[j];
		searchrec(j+1);
	}
};

int main() {
	ios_base::sync_with_stdio();
	for (M = 1; M < 52; M++)
		searchrec(0);
	cerr << fairsqs.size() << " fair squares" << endl;
	cerr << calls << " calls, " << fails << " fails" << endl;
	scanf("%d ", &T);
	for (int test = 0; test < T; test++) {
		fprintf(stderr, "Test %d/%d\n", test+1, T);
		printf("Case #%d: ", test+1);
		scanf("%s", str);
		mpz_class A(str);
		scanf("%s", str);
		mpz_class B(str);
		int res = 0;
		for (vector<mpz_class>::iterator it = fairsqs.begin(); it != fairsqs.end(); it++)
			if (A <= *it && *it <= B)
				res++;
		printf("%d\n", res);
		//cout << num(B+1)-num(A) << endl;
	}
	return 0;
}
