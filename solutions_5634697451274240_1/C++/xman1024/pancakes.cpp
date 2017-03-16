#include <bits/stdc++.h>
using namespace std;

int T;
int l;
int z;
char S[200];


int main()
{
	scanf("%d", &T);
	for(int i = 1; i <= T; ++i)
	{
		scanf("%s", S);
		l = 1;
		z = 0;
		for( ; S[l] != '\0' ; ++l)
			if(S[l] != S[l-1]) ++z;
		if(S[l-1] == '-') ++z;
		printf("Case #%d: %d\n", i, z);
	}
	
	return 0;
}
