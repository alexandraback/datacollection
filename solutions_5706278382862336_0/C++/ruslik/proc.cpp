#include <stdlib.h>
#include <stdio.h>


long long int mcd(long long int a, long long int b) {
	if (!a || !b)
		return 1;
	while (a != b) {
		if (a > b)
			a %= b;
		else	
			b %= a;
		if (!a || !b)
			return a | b;
	};
	return a;
};



int solve(int ctry){
	long long int p, q, pr, qr;
	scanf("%I64d/%I64d", &pr, &qr);
	long long int t = mcd(pr, qr);
	p = pr / t;
	q = qr / t;
//	printf("%I64d %I64d, mcd %I64d, rez %I64d %I64d\n", pr, qr, t, p, q);

	int parent_q = 2;
	int gen = 1;
	for (; gen <= 40; gen++,parent_q <<=1) {
		if (p*parent_q  >=  q)
			break;	// found!
	};
	
	// q mush be power of 2!
	while (!(q&1))
		q >>= 1;
	if (q != 1)
		gen = 41;
	
	if (gen == 41)
		printf("Case #%d: impossible\n", ctry);
	else
		printf("Case #%d: %d\n", ctry, gen);
};


int main(){

	if (freopen("test.in", "rt", stdin)){
//		freopen("A-large-practice.out", "wt", stdout);
		int tries = 0;
		scanf("%d", &tries);
		for (int ctry = 1; ctry <= tries; ctry++){
			solve(ctry);
		};
	};
	if (freopen("A-small-attempt0.in", "rt", stdin)){
		freopen("A-small-attempt0.out", "wt", stdout);
		int tries = 0;
		scanf("%d", &tries);
		for (int ctry = 1; ctry <= tries; ctry++){
			solve(ctry);
		};
	};
	if (freopen("A-large-practice.in", "rt", stdin)){
		freopen("A-large-practice.out", "wt", stdout);
		int tries = 0;
		scanf("%d", &tries);
		for (int ctry = 1; ctry <= tries; ctry++){
			solve(ctry);
		};
	};
	return 0;
};