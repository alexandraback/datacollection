#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cctype>
#include<cstdlib>
#include<algorithm>
#include<bitset>
#include<vector>
#include<list>
#include<deque>
#include<queue>
#include<map>
#include<set>
#include<stack>
#include<cmath>
#include<sstream>
#include<fstream>
#include<iomanip>
#include<ctime>
#include<complex>
#include<functional>
#include<climits>
#include<cassert>
#include<iterator>
#include<valarray>
using namespace std;
int t;
#define MAX 1001
int a[MAX];
int main(){
	scanf("%d", &t);
	int r = 0;
	while (t--){
		r++;
		int n;
		scanf("%d", &n);
		int sum = 0;
		for (int i = 0; i < n; i++){
			scanf("%d", &a[i]);
			sum += a[i];
		}
		int ans = 0;
		int mint = INT_MAX;
		for (int i = 1; i <= sum; i++){
			int maxt = 0;
			int countt = 0;
			for (int j = 0; j < n; j++){
				maxt = max(maxt, min(i, a[j]));
				if (a[j] <= i){
					continue;
				}
				countt += a[j] / i;
				if (a[j] % i){
					countt++;
				}
				countt--;
			}
			countt += maxt;
			mint = min(mint, countt);
		}
		printf("Case #%d: %d\n", r, mint);
	}
	return 0;
}