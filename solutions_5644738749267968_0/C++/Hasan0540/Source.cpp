#include <stdio.h>
#include <set>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int n;
double A[1000], B[1000];
int calcA(){
	set<double> a(A, A + n), b(B, B + n);
	set<double>::iterator it,jt;
	int res = 0;
	while (!a.empty()){
		if (*a.begin() > *--b.end()){
			res += a.size();
			break;
		}else{
			for (it = --a.end(), jt = --b.end(); it != a.begin();--it,--jt)
				if (*it < *jt)
					break;
			if (it == a.begin()){
				if (*it>*jt)
					++res;
				a.erase(it);
				b.erase(jt);
			}else{
				a.erase(a.begin());
				b.erase(jt);
			}
		}
	}
	return res;
}
int calcB(){
	set<double> a(A, A + n), b(B, B + n);
	set<double>::iterator it;
	int res = 0;
	while (!a.empty()){
		it = b.upper_bound(*a.begin());
		if (it == b.end()){
			++res;
			b.erase(b.begin());
		}else
			b.erase(it);
		a.erase(a.begin());
	}
	return res;
}
int main()
{
	freopen("src.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int t;
	scanf("%d", &t);
	for (int k = 1; k <= t; ++k){
		printf("Case #%d: ", k);
		scanf("%d", &n);
		for (int i = 0; i < n; ++i)
			scanf("%lf", &A[i]);
		sort(A, A + n);
		for (int i = 0; i < n; ++i)
			scanf("%lf", &B[i]);
		sort(B, B + n);
		printf("%d %d\n", calcA(), calcB());
	}
	return 0;
}