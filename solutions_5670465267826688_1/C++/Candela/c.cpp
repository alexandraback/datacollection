#include <algorithm>
#include <bitset>
#include <cmath> 
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <deque>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <utility>
#include <vector>
#define PB push_back
#define MP make_pair
#define LB lower_bound
#define UB upper_bound
#define FT first
#define SD second
#define VI vector<int> 
#define MII map<int,int>
#define SI set<int>
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long LL;
typedef long double LD;
const int INF = 0x7FFFFFFF;
const LL LINF = 0x7FFFFFFFFFFFFFFFll;

using namespace std;

int a[11111];
int b[10];

int func(int x, int y){
	int ans;
	int sign = 1;
	if (x < 0){
		sign *= -1;
		x = -x;
	}
	if (y < 0){
		sign *= -1;
		y = -y;
	}
	if (x == 1){
		if (y == 1) ans = 1;
		if (y == 2) ans = 2;
		if (y == 3) ans = 3;
		if (y == 4) ans = 4;
	}
	if (x == 2){
		if (y == 1) ans = 2;
		if (y == 2) ans = -1;
		if (y == 3) ans = 4;
		if (y == 4) ans = -3;
	}
	if (x == 3){
		if (y == 1) ans = 3;
		if (y == 2) ans = -4;
		if (y == 3) ans = -1;
		if (y == 4) ans = 2;
	}
	if (x == 4){
		if (y == 1) ans = 4;
		if (y == 2) ans = 3;
		if (y == 3) ans = -2;
		if (y == 4) ans = -1;
	}
	return ans * sign;
}

int func2(int x, int y){
	int ans;
	int sign = 1;
	if (x < 0){
		sign *= -1;
		x = -x;
	}
	if (y < 0){
		sign *= -1;
		y = -y;
	}
	if (x == 1){
		if (y == 1) ans = 1;
		if (y == 2) ans = -2;
		if (y == 3) ans = -3;
		if (y == 4) ans = -4;
	}
	if (x == 2){
		if (y == 1) ans = 2;
		if (y == 2) ans = 1;
		if (y == 3) ans = 4;
		if (y == 4) ans = -3;
	}
	if (x == 3){
		if (y == 1) ans = 3;
		if (y == 2) ans = -4;
		if (y == 3) ans = 1;
		if (y == 4) ans = 2;
	}
	if (x == 4){
		if (y == 1) ans = 4;
		if (y == 2) ans = 3;
		if (y == 3) ans = -2;
		if (y == 4) ans = 1;
	}
	return ans * sign;
}

bool check(int s1, int s2, int s3, LL len){
	if (s2 != 3) return false;
	for (int i = 0; i < 4; i++){
		if (func(b[i], s1) != 2) continue;
		int j = ((len % 4) + 7 - i) % 4;
		if (i + j + 1 > len) continue;
		if (func(s3, b[j]) == 4) return true;
	}
	return false;
}

bool check2(int s1, int s21, int s22, int s3, LL len){
	for (int i = 0; i < 4; i++){
		if (func(b[i], s1) != 2) continue;
		for (int k = 0; k < 4; k++){
			if (func(s3, b[k]) != 4) continue;
			int j = ((len % 4) + 14 - i - k) % 4;
			if (i + j + k + 2 > len) continue;
			if (func(func(s21, b[j]), s22) == 3) return true;
		}
	}
	return false;
}

int main(){

	freopen("c.in", "r", stdin);
	freopen("c.out", "w", stdout);
	
	int casenum, hh;
	int s1, s2, s3, s21, s22;
	scanf("%d", &casenum);
	for (int z = 1; z <= casenum; z++){

		memset(d, 0, sizeof d);

		bool flag = false;	
		int n;
		scanf("%d", &n);
		LL len;
		cin >> len;
		char c;
		scanf("%c", &c);
		int tot = 1;
		for (int i = 0; i < n; i++){
			scanf("%c", &c);
			if (c == 'i') a[i] = 2;
			if (c == 'j') a[i] = 3;
			if (c == 'k') a[i] = 4;
			tot = func(tot, a[i]);
		}
		b[0] = 1;
		b[1] = tot;
		b[2] = func(tot, tot);
		b[3] = func(b[2], tot);
		s1 = 1;
		for (int i = 0; i < n - 1; i++){
			s2 = 1;
			for (int j = i; j < n; j++){
				s2 = func(s2, a[j]);
				s3 = func2(tot, func(s1, s2));
				if (check(s1, s2, s3, len)){
					flag = true;
					break;
				}
			}
			if (flag) break;
			s1 = func(s1, a[i]);
		}
		s1 = 1;
		for (int i = 0; i < n; i++){
			if (flag) break;
			s1 = func(s1, a[i]);
			s22 = 1;
			for (int j = 0; j < n; j++){
				s21 = func2(tot, s1);
				s3 = func2(tot, s22);
				//printf("i:%d j:%d s1:%d s21:%d s22:%d s3:%d\n", i, j, s1, s21, s22, s3);
				if (check2(s1, s21, s22, s3, len)){
					flag = true;
					break;
				}
				s22 = func(s22, a[j]);
			}
		}
		if (flag) printf("Case #%d: YES\n", z);
		else printf("Case #%d: NO\n", z);
	}

 	fclose(stdin);
 	fclose(stdout);
	
}