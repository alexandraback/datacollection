#include <cstdio>
#include <list>
#include <string>
using namespace std;

list<char> lst;
char t[1002];

int main()
{
	freopen("A-large.in", "r", stdin);
	freopen("A-large.out", "w", stdout);
	int T;
	char chr;
	scanf("%d", &T);
	for (int i = 1; i <= T; ++i)
	{
		scanf("%s", t);
		lst.clear();
		lst.push_back(t[0]);
		for (int i = 1; i < strlen(t); ++i)
		{
			if (t[i] < lst.front())
				lst.push_back(t[i]);
			else
				lst.push_front(t[i]);
		}
		printf("Case #%d: ", i);
		for (list<char>::iterator iter = lst.begin(); iter != lst.end(); ++iter)
			printf("%c", *iter);
		printf("\n");
	}
}