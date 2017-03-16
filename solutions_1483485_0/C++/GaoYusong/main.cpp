#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>

using namespace std;

char to[300];
string ore[3] = {
	"ejp mysljylc kd kxveddknmc re jsicpdrysi",
	"rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd",
	"de kr kd eoya kw aej tysr re ujdr lkgc jv"
};
string obj[3] = {
	"our language is impossible to understand",
	"there are twenty six factorial possibilities",
	"so it is okay if you want to just give up"
};

char ss[110];
bool vis[300];

int main()
{
	int T;

	//freopen("A-small-attempt2.in", "r", stdin);
	//freopen("A-small-attempt2.out", "w", stdout);

	memset(vis, false, sizeof(vis));
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < ore[i].length(); j++) {
			to[ore[i][j]] = obj[i][j];
			vis[obj[i][j]] = true;
		}
	}
	
	to['z'] = 'q';
	to['q'] = 'z';
	scanf("%d", &T);
	getchar();
	int cn = 0;
	while (T--) {
		gets(ss);
		int len = strlen(ss);
		for (int i = 0; i < len; i++) {
			if (to[ss[i]] != 0)
				ss[i] = to[ss[i]];
		}
		
		printf("Case #%d: %s\n", ++cn, ss);
	}
	return 0;
}
