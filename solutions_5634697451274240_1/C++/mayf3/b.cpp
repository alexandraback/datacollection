#include <cstdio>
#include <cstring>

using namespace std;

const int N = 233;

int n;
char s[N];

int main(){
	int T;
	scanf("%d", &T);
	for(int cas = 1; cas <= T; cas++){
		printf("Case #%d: ", cas);
		scanf("%s", s);
		n = strlen(s);
		while(n && s[n - 1] == '+') n--;
		int cnt = (n != 0);
		for(int i = 1; i < n; i++){
			if (s[i] == s[i - 1]) continue;
			cnt++;
		}
		printf("%d\n", cnt);
	}
}
