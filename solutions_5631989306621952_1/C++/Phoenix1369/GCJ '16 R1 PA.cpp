#include <cstdio>
#include <cstring>
#include <string>
#define MEM(x, y) memset((x), (y), sizeof(x))
typedef std::string str;

const int MAXC = 1005;
char buffer[MAXC];
int count[30]{ };
str out;
int T;

int main()
{
	scanf(" %d", &T);
	for(int _T = 1; _T <= T; ++_T)
	{
		MEM(count, 0);
		scanf(" %s", &buffer);
		out.clear(); out += buffer[0];
		for(int i = 1; buffer[i] != '\0'; ++i)
		{
			if(out[0] <= buffer[i])
				out = buffer[i] + out;
			else
				out += buffer[i];
		}
		printf("Case #%d: %s\n", _T, out.c_str());
	}
	return 0;
}