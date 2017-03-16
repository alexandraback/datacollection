#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int a, n;
int m[104];
int res = 0x3f3f3f3f;

void delsolve(int k, long long int s, int resp);
void addsolve(int k, long long int s, int resp);

void addsolve(int k, long long int s, int resp){
	//printf("add %d %lld %d\n", k, s, resp);
	int x = resp;
	if(k >= n){
		res = min(res, resp);
		return;
	}
	if(s==1) return;
	while(k < n && s > m[k]) s += m[k++];
	while(k < n && s <= m[k]){
		s = s*2-1;
		x++;
	}
	while(s > m[k] && k < n) s += m[k++];
	addsolve(k, s, x);
	delsolve(k, s, x);
}

void delsolve(int k, long long int s, int resp){
	//printf("del %d %lld %d\n", k, s, resp);
	int x = resp;
	if(k >= n){
		res = min(res, resp);
		return;
	}
	while(k < n && s > m[k]) s += m[k++];
	while(s <= m[k] && k < n){
		k++;
		x++;
	}
	while(k < n && s > m[k]) s += m[k++];
	addsolve(k, s, x);
	delsolve(k, s, x);
}

int main(){
	int t, c = 1;
	long long int s;
	
	scanf("%d", &t);
	while(t--){
		scanf("%d %d", &a, &n);
		
		s = a;
		res = 0;
		for(int i = 0; i < n; ++i) scanf("%d", &m[i]);
		sort(m, m+n);
		
		res = 0x3f3f3f3f;
		//printf("--> %lld %d\n", s, a);
		
		int flag = 0;
		for(int i = 0; i < n; ++i){
			if(m[i] < s) s = s + m[i];
			else {
				flag = 1;
				addsolve(i, s, 0);
				delsolve(i, s, 0);
				break;
			}
		}
		if(flag == 0) res = 0;
		printf("Case #%d: %d\n", c++, res);
	
	}
	
return 0;
}
