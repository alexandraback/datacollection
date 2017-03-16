#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#include <map>
#include <stack>
#include <cmath>
#include <algorithm>
#include <cmath>


using namespace std;


typedef long long LL;
typedef unsigned long long ULL;
typedef pair < int , int > pii;
typedef vector < int > vi;
typedef vector < pii > vii;



#define REP(i, a) for (int i = 0; i < a; i++)
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define REPD(i, a) for (int i = a - 1; i >= 0; i--)
#define FORD(i, a, b) for (int i = a; i >= b; i--)
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define CLEAR(x, val) memset(x, val, sizeof(x))

int n;
int in[201];
int pre1[25], pre2[25];
bool ketemu = 0;



void ada (int sum1, int sum2, int id, int c1, int c2) {
	//cout << "sum1 = " << sum1 << " sum2 = " << sum2 << " id = " << id << " c1 = " << c1 << " c2 = " << c2 << endl;
	//cout << "ada\n";
	if (id != 0 && sum1 == sum2 && !ketemu) { //cout << "ADA c1 = " << c1 << endl;
		ketemu = 1;
		REP(i, c1) {
			if (i)
				printf(" ");
			printf("%d", in[pre1[i]]);
		}
		printf("\n");
		
		
		REP(i, c2) {
			if (i)
				printf(" ");
			printf("%d", in[pre2[i]]);
		}
		
		printf("\n");
	}
	//printf("ada\n");
	if (id == n)
		return;
	if (!ketemu) {
		pre1[c1] = id;
		ada(sum1 + in[id], sum2, id + 1, c1 + 1, c2);
	}
	
	if (!ketemu) {
		pre2[c2] = id;
		ada(sum1, sum2 + in[id], id + 1, c1, c2 + 1);
	}
	
	if (!ketemu) {
		ada(sum1, sum2, id + 1, c1, c2);
	}
}

int main () {
	int tc;
		scanf("%d", &tc);
		
		FOR(i, 1, tc) {
			scanf("%d", &n);
			REP(ii, n) {
				scanf("%d", &in[ii]);
			}
			ketemu = 0;
			printf("Case #%d:\n", i);
			ada(0, 0, 0, 0, 0);
			
			if (!ketemu) {
				printf("Impossible");
			}
		}
}








