#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

bool contains(char *s, char c)
{
	for (int i=0; s[i]; i++) {
		if (s[i] == c) { return true; }
	}
	return false;
}
void remove(char *s, char c)
{
	for (int i=0; s[i]; i++) {
		if (s[i] == c) {
			s[i] = 1;
			break;
		}
	}
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);


	int _n;
	scanf("%d", &_n);

	for (int _t=1; _t<=_n; _t++) {
		char S[22] = {0};
		char s[11] = "ZXGWHROFSN";
		int d[11] = {0,6,8,2,3,4,1,5,7,9};
		char l[11][11] = {"ZERO","SIX","EIGHT","TWO","THREE","FOUR","ONE","FIVE","SEVEN","NINE"};
		int ret[20] = {0}, idx = 0;
		scanf("%s", S);
		
		for (int i=0; i<=9; i++) {
			while (contains(S, s[i])) {
				ret[idx++] = d[i];
				for (int j=0; l[i][j]; j++) {
					remove(S, l[i][j]);
				}
			}
		}
		sort(ret, ret+idx);
		printf("Case #%d: ", _t);
		for (int i=0; i<idx; i++) {
			printf("%d", ret[i]);
		}
		printf("\n");
	

	}
}
