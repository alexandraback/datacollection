#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
#include<stdio.h>
#include<string>
using namespace std;

int test;
FILE *fo = fopen("output.txt","w");
long long int r, m, a, b, res;

long long int process(long long int lo, long long int hi)
{
	// 2rn + 2n^2 - n
	//cout << r << ' ' << m << endl;
	long long int ans=0, mm, val;
	while(lo <= hi) {
		mm = (lo+hi)/2;
		//cout << mm << endl;
		//if (2*r > 1100000000) {
		//	hi = mm-1;
		//}
		//else {
			val = (2*r + 2*mm - 1);
			if (val <= m/mm) {
				lo = mm+1;
				ans = mm;
			}
			else {
				hi = mm-1;
			}
		//}
	}
	return ans;
}

int main()
{
	//FILE *fp = fopen("input.txt", "r");
	FILE *fp = fopen("A-small-attempt0.in", "r");
	fscanf(fp, "%d", &test);
	for(int t = 1; t <= test; t++) {
		//input
		fscanf(fp, "%lld %lld", &r, &m);

		a = 1;
		b = 2000000000000000000;
		//printf("%lld\n", b);

		//process
		res = process(a, b);

		//output
		fprintf(fo, "Case #%d: %lld\n", t, res);
		//scanf("%d");
	}

	fclose(fp);
	fclose(fo);
	
	return 0;
}