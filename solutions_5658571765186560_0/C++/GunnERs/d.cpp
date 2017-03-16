#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

int tt, x, r, c;

bool doit(){
	if (r*c%x!=0) return true;
	if (r<c) swap(r, c);
	if (x>r || x>=2*c+1) return true;
	if (x>=c+r-1) return true;
	if (r>4 && x>=c+r-3) return true;
	return false;
}

int main(){
	freopen("D-small-attempt0.in", "r", stdin);
	freopen("a.out", "w", stdout);

	scanf("%d", &tt);
	for (int task=1; task<=tt; task++){
		scanf("%d%d%d", &x, &r, &c);
		if (!doit())
			printf("Case #%d: GABRIEL\n", task);else
			printf("Case #%d: RICHARD\n", task);
	}
	return 0;
}
