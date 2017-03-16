#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
#include <string>
#include <memory.h>
using namespace std;

#include <cctype>
#include <cstdio>
#include <cstdarg>
#include <ctime>
#include <cmath>
#include <cassert>


const int INF = (1 << 30) - 1;
const float PI = (float)acos(-1.0);
const float EPS = 1e-5;
const float BASE2 = 1.0/log(2);

int cases;
int n;
long long M;
int a[100];

void deal()
{
	int k = 0;
	int sum = 0;
	while (M >0) {
		a[++k] = M&1;
		sum += a[k];
		M = M>>1;
	}
	if (n < k+1 || (n == k+1 && sum > 1)) {
		cout << "IMPOSSIBLE" << endl;
		return;
	}
	if (a[n-1] == 1) {
		for (int i = 0; i < n-1; i++) {
			a[i] = 1;
		}
		a[n-1] = 0;
	}

	cout << "POSSIBLE" << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <n-1; j++) {
			if (i < n-1 && j > i) cout << 1;
			else cout << 0;
		}

		cout << a[i] << endl;
	}

}


int main ()
{
	scanf("%d", &cases);
	for (int k = 1; k <= cases; k++) {
		printf("Case #%d: ", k);
		
		cin >> n;
		cin >> M;

		memset(a,0,sizeof(a));
		deal();
	}
	return 0;
}


