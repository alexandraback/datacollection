#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

int solve()
{
	int S;
	char s[1024];

	scanf("%d", &S);
	scanf("%s", s);

	int ct = 0, ret = 0;

	for (int i = 0; i <= S; i++){
		if (i > ct){
			ret += i - ct;
			ct += i - ct;
		}
		ct += s[i] - '0';
	}

	return (ret);
}

int main()
{
	int T;

	scanf("%d", &T);

	for (int i = 0; i < T; i++){
		printf("Case #%d: %d\n", i + 1, solve());
	}

	return (0);
}