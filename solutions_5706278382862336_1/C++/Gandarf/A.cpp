#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<queue>
using namespace std;

#define N 105
int test, caseNum;
char s[100];

long long int p, q;

int main()
{
	FILE *in = fopen("A-large.in", "r");
	//FILE *in = fopen("input.txt", "r");
	FILE *out = fopen("output.txt", "w");

	caseNum = 1;
	fscanf(in, "%d", &test);
	while(caseNum <= test)
	{
		fscanf(in, "%s", s);
		string k = s;
		string k2;
		int pos;
		for (int i = 0 ; i < k.size() ; i++)
		{
			if (k[i] == '/') {
				pos = i;
				break;
			}
		}
		p = q = 0;
		long long int temp = 1;
		for (int i = pos-1; i >= 0; i--) {
			p += temp * (long long int)(k[i]-'0');
			temp *= 10;
		}
		temp = 1;
		for (int i = k.size()-1; i >= pos+1; i--) {
			q += temp * (long long int)(k[i]-'0');
			temp *= 10;
		}
		
		// ¾àºÐ
		for (long long int i = 2; i*i <= q; i++) {
			if (p % i == 0 && q % i == 0) {
				p /= i;
				q /= i;
				i = 1;
			}
		}
		//printf("%lld %lld\n", p, q);

		int res = 0;
		bool flag = false;
		for (long long int i = 1; ; i *= 2) {
			if (i > q) break;
			if (i == q) { flag = true; break; }
			res++;
		}
		if (!flag)
			fprintf(out, "Case #%d: impossible\n", caseNum++);
		else {
			if (p == 1)
				fprintf(out, "Case #%d: %d\n", caseNum++, res);
			else {
				res = 1;
				while(1) {
					if (p * 2 >= q) {
						fprintf(out, "Case #%d: %d\n", caseNum++, res);
						break;
					}
					res++;
					q /= 2;
				}
			}
		}
	}

	fcloseall();
	return 0;
}
