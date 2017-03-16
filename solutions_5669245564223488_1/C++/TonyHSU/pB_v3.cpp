#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;

/*
bool cmp(struct  a, struct iin b) {
	return (a.start > b.start);
}
*/

char input[101][105];
char s_input[101][105];
int len[101];

long long int my_mod(long long int a) {
	if (a<0) a+= 1000000007;
	return a%1000000007;
}

long long int dd_save[101];

long long int ddd(long long int a) {
	if (a==1) return a;
	if (dd_save[a]>0) return dd_save[a];
	dd_save[a]= my_mod(a*ddd(a-1));
	return dd_save[a];
}

int main() {
	int T, nm= 1;
	int i, j, k;
	for (i=0;i<101;i++) {
		dd_save[i]= 0;
	}
	scanf("%d", &T);
	while (T--) {
		int n;
		scanf("%d", &n);
		for (i=0;i<n;i++) {
			scanf("%s", s_input[i]);
		}
		for (i=0;i<n;i++) {
			int ct= 1;
			input[i][0]= s_input[i][0];
			for (j=1;s_input[i][j]!='\0';j++) {
				if (s_input[i][j] != input[i][ct-1]) {
					input[i][ct++]= s_input[i][j];
				}
			}
			input[i][ct]= '\0';
		}
		for (i=0;i<n;i++) {
			len[i]= strlen(input[i]);
		}
		//for (i=0;i<n;i++) {
		//	printf("%s\n", input[i]);
		//}
		int pass= 1;
		int save[300]= {0};
		for (i=0;i<n;i++) {
			if (len[i]==1) continue;
			if (save[input[i][0]]) {
				pass= 0;
				break;
			}
			else {
				save[input[i][0]]= 1;
			}
		}
		if (pass) {
			for (i=0;i<300;i++) save[i]= 0;
			for (i=0;i<n;i++) {
				if (len[i]==1) continue;
				if (save[input[i][len[i]-1]]) {
					pass= 0;
					break;
				}
				else {
					save[input[i][len[i]-1]]= 1;
				}
			}
		}
		if (pass) {
			for (i=0;i<300;i++) save[i]= 0;
			for (i=0;i<n;i++) {
				save[input[i][0]]++;
				save[input[i][len[i]-1]]++;
			}
			for (i=0;i<n;i++) {
				if (len[i]==1) continue;
				for (j=1;j<len[i]-1;j++) {
					if (save[input[i][j]]) {
						pass= 0;
						break;
					}
					else {
						save[input[i][j]]= 1;
					}
				}
			}
		}
		long long int ans= 1;
		if (pass) {
			for (i=0;i<300;i++) save[i]= 0;
			for (i=0;i<n;i++) {
				if (len[i]==1) {
					save[input[i][0]]++;
				}
			}
			for (i=0;i<300;i++) {
				if (save[i]>0) {
					ans= my_mod(ans*ddd(save[i]));
				}
			}
		}
		//printf("ans= %lld\n", ans);
		if (pass) {
			for (i=0;i<300;i++) save[i]= 0;
			for (i=0;i<n;i++) {
				if (len[i]>1) {
					save[input[i][0]]++;
					save[input[i][len[i]-1]]++;
				}
			}
			int tmp= 0;
			for (i=0;i<n;i++) {
				if (len[i]==1) {
					if (save[input[i][0]]==0) {
						save[input[i][0]]++;
						tmp++;
					}
				}
			}
			int temp= 0;
			for (i=0;i<300;i++) {
				if (save[i]==1) {
					temp++;
				}
			}
			int ttt= (temp-tmp)/2+tmp;
			//printf("ttt= %d, temp= %d, tmp= %d\n", ttt, temp, tmp);
			ans= my_mod(ans*ddd(ttt));
		}

		if (!pass) ans= 0;
		printf("Case #%d: %lld\n", nm++, ans);
	}
	return 0;
}
