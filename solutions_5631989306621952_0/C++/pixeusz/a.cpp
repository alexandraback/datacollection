#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;
using ll = long long;

#define LIM 1003
char in[LIM];
char out[LIM*2];

void SolveCase(int caseId);

int main()
{
	int T;
	scanf("%d", &T);
	for(int i = 1; i <= T; ++i)
		SolveCase(i);
	return 0;
}

void SolveCase(int caseId)
{
	scanf("%s", in);
	int len = strlen(in);
	
	int bI = LIM;
	out[bI] = in[0];
	for(int i = 1; i < len; ++i)
	{
		char c = in[i];
		if(c >= out[bI])
			out[--bI] = c;
		else
			out[bI+i] = c;
	}
	out[bI+len] = 0;
	
	printf("Case #%d: %s\n", caseId, out+bI);
}


