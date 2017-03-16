//b Hewr
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
#define fo(i,a,b) for (int i = a; i <= b; ++i)

const int mn = 110;

int a[mn];
int n, S, p, Ans;

int main(){
	int Ca;
	scanf("%d", &Ca);
	fo (CA, 1, Ca){
		scanf("%d%d%d", &n, &S, &p);
		fo (i, 1, n) scanf("%d", a + i);
		sort(a + 1, a + n + 1);
		Ans = 0;
		int bd, bd2;
		if (p <= 1) bd = 2; else bd = p * 3 - 4;
		if (p == 0) bd2 = 0; else bd2 = p * 3 - 2;
		fo (i, 1, n){
			if (S && a[i] >= bd && a[i] <= 28){
				--S, ++Ans;
				continue;
			}
			if (a[i] >= bd2) ++Ans;
		}
		cout << "Case #" << CA << ": " << Ans << endl;
	}
}
