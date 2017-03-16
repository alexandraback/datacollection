#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

const int MAXNUM = 100000;
char data[MAXNUM][200];
int len[MAXNUM];
int tot;

void prepare() {
	FILE *fin = fopen("sortnum.txt", "r");
	char num[200], sq[200];
	tot = 0;
	while (fscanf(fin, "%s", num) > 0) {
		fscanf(fin, "%s", sq);
		strcpy(data[tot], sq);
		len[tot] = strlen(data[tot]);
		tot ++;
	}
	fclose(fin);	
}

int Compare(char s1[200], char s2[200]) {
	int l1 = strlen(s1), l2 = strlen(s2);
	if (l1 < l2) return -1;
	if (l2 < l1) return 1;
	for (int i = 0; i < l1; i ++) {
		if (s1[i] < s2[i]) return -1;
		if (s2[i] < s1[i]) return 1;	
	}
	return 0;
}

int main() {
	freopen("C-large-1.in","r",stdin);
	freopen("C-large-1.out","w",stdout);
	prepare();
	fprintf(stderr,"Load OK!");
	int T;
	char A[200], B[200];
	scanf("%d", &T);
	for (int ti = 1; ti <= T; ti ++) {
		cin>>A;
		cin>>B;
		int ans = 0;
		for (int i = 0; i < tot; i ++) {
			if (Compare(A, data[i]) <= 0 && Compare(data[i], B) <= 0)
				ans ++;
		}
		cout<<"Case #"<<ti<<": "<<ans<<endl;
	}
	return 0;
}

