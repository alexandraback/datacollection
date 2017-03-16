#include <stdio.h>
#include <string.h>
#include <algorithm>

const int N = 1000;

using namespace std;

char s[N];
int test, n;

int main()
{
	freopen("b-small.in", "r", stdin);
	freopen("b-small.out", "w", stdout);
	
	scanf("%d" ,&test);
	
	for(int t=1; t<=test; t++)
	{
		int ans = 0;
		
		scanf("%s" ,s);
		
		n = strlen(s);
		
		for(int i=1; i<n; i++)
			if(s[i]=='-' && s[i-1]=='+')
				ans+=2;
		
		ans += (s[0]=='-');
		
		printf("Case #%d: %d\n" ,t ,ans);
	}
}
