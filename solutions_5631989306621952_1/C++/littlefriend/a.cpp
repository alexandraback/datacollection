#include <cstdio>
#include <string>
#include <cstring>
using namespace std;
string st;
char s[1005];
int main(int argc, char** argv)
{
	if (argc > 1)
	{
		freopen(argv[1], "r", stdin);
		freopen(argv[2], "w", stdout);
	}
	int T;
	scanf("%d", &T);
	for (int i = 0; i < T; ++i)
	{
		printf("Case #%d: ", i+1);
		scanf("%s", s);
		int len = strlen(s);
		st.clear();
		for (int j = 0; j < len; ++j)
		{
			if (j && s[j] >= st[0])
				st.insert(st.begin(), s[j]);
			else
				st.push_back(s[j]);
		}
		printf("%s\n", st.c_str());
	}
	return 0;
}