#include <stdio.h>
#include <string.h>
#include <memory.h>
#include <string>

using namespace std;

int ccnt[200];
int ncnt[10];
char s[2005];
int n;

char primary[11]="ZOWHUFXSGI";
string ns[10] = { "ZERO","ONE","TWO","THREE","FOUR","FIVE","SIX","SEVEN","EIGHT","NINE" };
int t1[5] = { 0,2,4,6,8 };
int t2[5] = { 1,3,5,7,9 };


void process()
{
	scanf(" %s", &s[1]);
	n = strlen(&s[1]);

	memset(ccnt, 0, sizeof(ccnt));
	memset(ncnt, 0, sizeof(ncnt));

	for (int i = 1; i <= n; i++) ccnt[s[i]]++;

	for (int i = 0; i < 5; i++) {
		ncnt[t1[i]] = ccnt[primary[t1[i]]];
		for (int j = 0; j < ns[t1[i]].size(); j++) ccnt[ns[t1[i]][j]] -= ncnt[t1[i]];
	}

	for (int i = 0; i < 5; i++) {
		ncnt[t2[i]] = ccnt[primary[t2[i]]];
		for (int j = 0; j < ns[t2[i]].size(); j++) ccnt[ns[t2[i]][j]] -= ncnt[t2[i]];
	}

	for (int i = 0; i < 10; i++) {
		for (int j = 1; j <= ncnt[i]; j++) printf("%d", i);
	}
	printf("\n");

}

int main()
{
	freopen("A-small-attempt1.in", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	int t;
	scanf("%d", &t);
	for (int i = 1; i <= t; i++) {
		printf("Case #%d: ",i);
		process();
	}
	return 0;
}