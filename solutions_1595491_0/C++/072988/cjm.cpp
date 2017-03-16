#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

vector <int> a;
int n, s, p;

bool  Surp(int n, int p){
	n -= p;
	if(n < 0)
		return false;
	return n / 2 + 2 >= p;
}

bool Common(int n, int p){
	n -= p;
	if(n < 0)
		return false;
	return n / 2 + 1 >= p;
}

int main(){
	int T;
	scanf("%d", &T);
	for(int t = 1; t <= T; t ++){
		a.clear();
		scanf("%d%d%d", &n, &s, &p);
		int tmp;
		for(int i = 0; i < n; i ++){
			scanf("%d", &tmp);
			a.push_back(tmp);
		}
		sort(a.begin(), a.end());
		int ans = 0;
		for(int i = 0; i < n; i ++){
			if(s > 0){
				if(Surp(a[i], p)){
					ans ++;
					s --;
				}
			}else{
				if(Common(a[i], p)){
					ans ++;
				}
			}
		}

		printf("Case #%d: %d\n", t , ans);
	}

	return 0;
}