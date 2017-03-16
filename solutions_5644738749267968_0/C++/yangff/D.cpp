#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <set>

using namespace std;
const int MaxN = 1111;
double a[MaxN], b[MaxN];
void print(set<double> S){
	for (set<double>::iterator it = S.begin(); it != S.end(); it ++)
		printf("%lf ", *it);
	puts("");
}
int main(){
	freopen("D.in", "r", stdin);
	freopen("D.out", "w", stdout);
	int T; scanf("%d", &T);
	for (int cas = 1; cas <= T; cas++){
		printf("Case #%d: ", cas);
		int n; scanf("%d", &n);
		for (int i = 0; i < n; i++)
			scanf("%lf", a + i);
		for (int i = 0; i < n; i++)
			scanf("%lf", b + i);
		set<double> A, B;
		for (int i = 0; i < n; i++)
			A.insert(a[i]), B.insert(b[i]);
		int ans1 = 0;
		while (!A.empty()){
			if (*A.begin()>*B.begin()){
				ans1++;A.erase(A.begin());B.erase(B.begin());
			} else {
				A.erase(A.begin());B.erase(--B.end());
			}
		}
		for (int i = 0; i < n; i++)
			A.insert(a[i]), B.insert(b[i]);
		int ans2 = 0;
		//puts("");
		while (!A.empty()){
			//print(A); print(B);
			if (*A.begin() > *(--B.end())){
			//	printf("1 A erase %lf, B erase %lf\n", *A.begin(), *B.begin());
				ans2++;A.erase(A.begin());B.erase(B.begin());
			} else {
			//	printf("2 A erase %lf, B erase %lf\n", *A.begin(), *B.lower_bound(*A.begin()));
				B.erase(B.lower_bound(*A.begin()));A.erase(A.begin()); 
			}
		}
		printf("%d %d\n", ans1, ans2);
	}
}
