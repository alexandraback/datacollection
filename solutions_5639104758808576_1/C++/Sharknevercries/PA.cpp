#include<bits\stdc++.h>
using namespace std;
int main(){
	freopen("A-large.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t, c = 1;
	scanf("%d", &t);
	while (t--){
		char s[1005];
		int n;
		int w[1005];
		scanf("%d%s", &n, s);
		for (int i = 0; s[i] != '\0'; i++)
			w[i] = s[i] - '0';
		int ans = 0, count = 0;
		if (w[0] <= 0)
			ans++, count++;
		else
			count += w[0];
		for (int i = 1; i <= n; i++){
			int tmp = i - count;
			if (i - count > 0)
				ans += i - count, count += tmp;
			count += w[i];
		}
		printf("Case #%d: %d\n",c++, ans);
	}
	return 0;
}