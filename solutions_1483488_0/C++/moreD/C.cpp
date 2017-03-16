#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <set>

using namespace std;

int T, a, b, ans;
set<int> S;

void calc(int x){
	char s[50];
	memset(s, 0, sizeof(s));
	itoa(x, s, 10);
	int l = strlen(s);
	S.clear();
	for (int i = 1; i < l; i++){
		s[l + i - 1] = s[i - 1];
		int k = atoi(s + i);
		if (k >= a && k <= b && k < x && S.count(k) == 0){
			ans++; S.insert(k);
		}
	}
}

int main(){
	scanf("%d", &T);
	for (int ca = 1; ca <= T; ca++){
		scanf("%d%d", &a, &b);
		ans = 0;
		for (int i = a; i <= b; i++)
			calc(i);
		printf("Case #%d: %d\n", ca, ans);
	}
}
