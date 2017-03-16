#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <cstring>
#include <map>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <bitset>
#define f first
#define s second
#define ll long long
#define ull unsigned long long
#define mp make_pair
#define pb push_back
#define vi vector <int>
#define ld long double
#define pii pair<int, int>
using namespace std;    
const int N = int(3e5), mod = int(1e9)  + 7;
int T;
int s[N];
map <ll,int> ma;
int a[N];
ll res;

int get(int n){
	ll m = 0;
	for(int i=1;i<=16;i++){
		m = m * n + s[i];
	}
	for(int i=2;i<=1000;i++){
		if(m % i == 0){
			return i;
		}
	}
	return -1;
}

bool check(ll res){
	if(ma.count(res)) return 0;
	ma[res] = 1;
	for(int i=2;i<=10;i++){
		a[i] = get(i);
		if(a[i] == -1) return 0;
	}
	return 1;
}

int main () {
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	srand(time(0));
	int cnt = 0;
	int n = 16;
	printf("Case #1:\n");
	while(cnt < 50){
		s[1] = s[16] = 1;
		res = 1;
		for(int i=2;i<=15;i++){
			s[i] = rand() & 1;
			res = res * 10 + s[i];
		}
		res = res * 10 + 1;
		if(check(res)){
			cnt++;
			printf("%lld ",res);
			for(int i=2;i<=10;i++){
				printf("%d",a[i]);
				if(i == 10) puts("");
				else printf(" ");
			}
		}
	}
return 0;
}