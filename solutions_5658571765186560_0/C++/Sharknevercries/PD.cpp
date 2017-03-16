#include<bits\stdc++.h>
using namespace std;
int x, r, c;
bool solve(){
	if (r * c % x != 0)	return false;
	if (r > c)	swap(r, c);
	if (x == 1)	return true;
	if (x == 2)	return r * c % 2 == 0;
	if (x == 3){
		if (r == 2 && c == 3)	return true;
		if (r == 3 && c == 3)	return true;
		if (r == 3 && c == 4)	return true;
	}
	if (x == 4){
		if (r == 3 && c == 4)	return true;
		if (r == 4 && c == 4)	return true;
	}
	return false;
}
int main(){
	freopen("D-small-attempt0.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t, a = 1;
	scanf("%d", &t);
	while (t--){
		scanf("%d%d%d", &x, &r, &c);
		printf("Case #%d: %s\n", a++, solve() ? "GABRIEL" : "RICHARD");
	}
	return 0;
}