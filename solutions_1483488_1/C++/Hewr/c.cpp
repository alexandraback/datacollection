//c Hewr
#include <iostream>
#include <cstdio>
using namespace std;
#define fo(i,a,b) for (int i = a; i <= b; ++i)

typedef long long LL;

const int co = 5718967;

int e[8];
int ha[co][3];
int tt(0);

bool hash(int n, int m){
	int x = (((LL) n * e[7] + m) % co + co) % co;
	while (ha[x][0] == tt && (ha[x][1] != n || ha[x][2] != m)) x = (x + 1 == co ? 0 : x + 1);
	bool ret = (ha[x][0] != tt);
	ha[x][0] = tt, ha[x][1] = n, ha[x][2] = m;
	return ret;
}

int main(){
	e[0] = 1;
	fo (i, 1, 7) e[i] = e[i - 1] * 10;
	int Ca;
	scanf("%d", &Ca);
	fo (CA, 1, Ca){
		int A, B, Cnt(0);
		scanf("%d%d", &A, &B);
		int len(1);
		while (e[len] <= B) ++len;
		fo (n, A, B - 1){
			++tt;
			fo (i, 1, len - 1){
				int m = n / e[i] + n % e[i] * e[len - i];
				if (n < m && m <= B) 
					Cnt += hash(n, m);
			}
		}
		cout << "Case #" << CA << ": " << Cnt << endl;
	}
}
