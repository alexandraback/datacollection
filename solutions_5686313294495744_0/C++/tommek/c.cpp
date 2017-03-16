#include <bits/stdc++.h>
using namespace std;

const int MX = 1e6 + 5;

int n;
pair<string, string> a[MX];

void Solve()
{
	cin >> n;
	for (int i = 0; i < n; ++ i){
		cin >> a[i].first >> a[i].second;
	}
	
	
	
	int res = 0;
	
	for (int bm = 0; bm < (1<<n); ++ bm){
	set<string> A, B;
		for (int i = 0; i < n; ++ i){
			if (bm & (1 << i)){
				//printf("%d praw\n",i);
				A.insert(a[i].first);
				B.insert(a[i].second);
			}
		}
		bool czy=true;
		for (int i = 0; i < n; ++ i){
			if (bm & (1 << i)){
				
			}else {
				if (A.find(a[i].first) == A.end() || B.find(a[i].second) == B.end()){
					czy= false;
				}
			}
		}
		if (czy){
		//puts("TAK");
			res = max(res, n-__builtin_popcount(bm));
		}
	}
	
	printf("%d\n", res);
}

int main()
{
	int __test; scanf("%d", &__test); 
	for (int __i = 1; __i <= __test; ++ __i)
	{
		printf("Case #%d: ", __i);
		Solve();
	}
	return 0;
}
