#include <stdio.h>
#include <string.h>
#include <string>
#include <queue>
#include <algorithm>
#include <math.h>
#include <vector>
#include <utility>
#include <map>
#include <stack>

#define fi first
#define se second
#define mp make_pair
#define ll long long
#define pii pair <int, int>
#define vi vector <int>
#define REP(a,b) for(int a = 0; a < b; ++a)
#define FORU(a,b,c) for(int a = b; a <= c; ++a)
#define FORD(a,b,c) for(int a = b; a >= c; --a)
#define MOD 1000000000
#define MODLL 1000007LL
#define INF 2123123123
#define pb push_back
using namespace std;

char kata[105][100005];
	
int main() {
	int n, T, last[33], len[105], ar[105];
	
	scanf("%d", &T);
	
	FORU(tc, 1, T) {
		printf("Case #%d: ", tc);
		
		scanf("%d", &n);
		
		REP(i, n) {
			ar[i] = i;
			
			scanf("%s", kata[i]);
			len[i] = strlen(kata[i]);
		}
		
		bool valid = true;
		
		REP(i, n) {
			memset(last, -1, sizeof(last));
			
			REP(j, len[i]) {
				int ch = kata[i][j] - 'a';
				
				if ((last[ch] == -1) || (last[ch] == (j - 1)))
					last[ch] = j;
				else
					valid = false;
			}
		}
		
		REP(i, n) {
			int posisi = 1;
			
			while (posisi < (len[i] - 1)) {
				if (kata[i][posisi] == kata[i][posisi - 1]) {
					++posisi;
					continue;
				}
				
				while ((posisi < (len[i] - 1)) && (kata[i][posisi] == kata[i][posisi + 1]))
					++posisi;
				
				if (posisi != (len[i] - 1)) {
					REP(j, n) {
						if (i == j)
							continue;
						
						REP(l, len[j]) {
							if (kata[i][posisi] == kata[j][l]) {
								valid = false;
								break;
							}
						}
						
						if (!valid)
							break;
					}
				}
				
				++posisi;
				
				if (!valid)
					break;
			}
			
			if (!valid)
				break;
		}
		
		if (!valid) {
			printf("0\n");
			continue;
		}
		
		int ans = 0;
		
		do {
			bool oke = true;
			int cnt = 0;
			
			REP(i, n - 1) {
				int pos = ar[i];
				bool sambung = false;
				
				if (kata[pos][0] != kata[pos][len[pos] - 1]) {
					char ch = kata[pos][0];
					
					FORU(j, i + 1, n - 1) {
						int pos2 = ar[j];
						
						if ((ch == kata[pos2][0]) || (ch == kata[pos2][len[pos2] - 1]))
							oke = false;
					}
				}
				
				int pos2 = ar[i + 1];
				
				if (kata[pos][len[pos] - 1] != kata[pos2][0]) {
					char ch = kata[pos][len[pos] - 1];
					// printf("%s %c\n", kata[pos], ch);
					
					FORU(j, i + 1, n - 1) {
						int pos3 = ar[j];
						
						if ((ch == kata[pos3][0]) || (ch == kata[pos3][len[pos3] - 1]))
							oke = false;
					}
				}
			}
			
			if (oke) {
				// printf("oke");
				
				// REP(i, n)
					// printf(" %s", kata[ar[i]]);
				// puts("");
				++ans;
			}
		} while (next_permutation(ar, ar + n));
		
		printf("%d\n", ans);
	}
}
