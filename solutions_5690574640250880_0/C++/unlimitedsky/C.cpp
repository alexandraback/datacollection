//Template for Dev-C++ 5.3.0.4 by unlimitedsky
//2013 March 4 20:58 (UTC +07.00)
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<climits>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<set>
using namespace std;
#define FOR(i,a,b,c) for (int i = a; i <= b; i+=c)
#define FORR(i,a,b,c) for (int i = a; i >= b; i-=c)
#define INC(i,a,b) for (int i = a; i <= b; i++)
#define DEC(i,a,b) for (int i = a; i >= b; i--)
#define MP make_pair
#define pb push_back
#define reset(a,b) memset(a,b,sizeof a)
typedef long long LL;
typedef pair<int,int> pii;
typedef vector<pii> vii;

int tc, n, r, c, temp, tmp;
bool can;
char ar[55][55];

int main(){
	scanf("%d", &tc);
	INC(i,1,tc){
		scanf("%d %d %d", &r, &c, &n);
		tmp = n;
		can = true;
		for (int j = 0; j < r; j++){
			for (int k = 0; k < c; k++){
				ar[j][k] = '.';
			}
		}
		if (r == 5 && c == 5 && n == 16){
			for (int j = 0; j < 2; j++){
				for (int k = 0; k < c; k++){
					ar[j][k] = '*';
				}
			}
			for (int j = 2; j < r; j++){
				for (int k = 0; k < 2; k++){
					ar[j][k] = '*';
				}
			}
		}
		else if (r == 1 || c == 1){
			if (r == 1){
				for (int j = 0; j < n; j++){
					ar[0][j] = '*';
				}
			}
			else if (c == 1){
				for (int j = 0; j < n; j++){
					ar[j][0] = '*';
				}
			}
		}
		else if (r*c - n == 1){
			for (int j = 0; j < r; j++){
				for (int k = 0; k < c; k++){
					ar[j][k] = '*';
				}
			}
		}
		else{
			if (r*c - n < 4){
				can = false;
			}
			else{
				if (n <= (r-2)*(c-2)){
					for (int j = 0; j < r-2; j++){
						if (n <= 0) break;
						for (int k = 0; k < c-2; k++){
							if (n <= 0) break;
							n--;
							ar[j][k] = '*';
						}
					}
				}
				else{
					n -= (r-2)*(c-2);
					if (n%2 == 1){
						can = false;
					}
					else{
						for (int j = 0; j < r-2; j++){
							for (int k = 0; k < c-2; k++){
								ar[j][k] = '*';
							}
						}
						for (int j = 0; j < r-2; j++){
							if (n <= 0) break;
							n -= 2;
							for (int k = c-2-1; k < c; k++){
								ar[j][k] = '*';
							}
						}
						for (int k = 0; k < c-2; k++){
							if (n <= 0) break;
							n -= 2;
							for (int j = r-2-1; j < r; j++){
								ar[j][k] = '*';
							}
						}
					}
				}
				if (!can){
					n = tmp;
					if (n/r < c-2){
						if (n % r <= r-2){
							can = true;
							for (int k = 0; k < n/r; k++){
								for (int j = 0; j < r; j++){
									ar[j][k] = '*';
								}
							}
							for (int j = 0; j < n%r; j++){
								ar[j][n/r] = '*';
							}
						}
						else if ((n%r) % (c - n/r) <= (c - n/r - 2) && (n%r) / (c - n/r) < r-2){
							can = true;
							for (int k = 0; k < n/r; k++){
								for (int j = 0; j < r; j++){
									ar[j][k] = '*';
								}
							}
							for (int j = 0; j < (n%r) / (c - n/r); j++){
								for (int k = n/r; k < c; k++){
									ar[j][k] = '*';
								}
							}
							for (int k = n/r; k < n/r + (n%r) % (c - n/r); k++){
								ar[(n%r) / (c - n/r)][k] = '*';
							}
						}
					}
					if (!can){
						if (n/c < r-2){
							if (n % c <= c-2){
								can = true;
								for (int j = 0; j < n/c; j++){
									for (int k = 0; k < c; k++){
										ar[j][k] = '*';
									}
								}
								for (int k = 0; k < n%c; k++){
									ar[n/c][k] = '*';
								}
							}
							else if ((n%c) % (r - n/c) <= (r - n/c - 2) && (n%c) / (r - n/c) < c-2){
								can = true;
								for (int j = 0; j < n/c; j++){
									for (int k = 0; k < c; k++){
										ar[j][k] = '*';
									}
								}
								for (int k = 0; k < (n%c) / (r - n/c); k++){
									for (int j = n/c; j < r; j++){
										ar[j][k] = '*';
									}
								}
								for (int j = n/c; j < n/c + (n%c) % (r - n/c); j++){
									ar[(n%c) / (r - n/c)][j] = '*';
								}
							}
						}
					}
				}
			}
		}
		printf("Case #%d:\n", i);
		if (can){
//			int temp = 0;
			ar[r-1][c-1] = 'c';
			for (int j = 0; j < r; j++){
				for (int k = 0; k < c; k++){
					printf("%c", ar[j][k]);
//					if (ar[j][k] == '*') temp++;
				}
				printf("\n");
			}
//			if (temp != tmp) printf("SALAH %d %d\n", temp, tmp);
		}
		else printf("Impossible\n");
	}	
	return 0;
}
