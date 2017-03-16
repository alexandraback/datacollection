#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;
			/*                *        **/
            /*abcdefghijklmnopqrstuvwxyz*/
char mps[] = "yhesocvxduiglbkrztnwjpfmaq";
char s[100000];

int main ()
{
	int t;
	scanf("%d",&t);
	gets(s);
	int cs = 0;
	while( t-- )
	{
		gets(s);
		printf("Case #%d: ", ++cs);
		for(int i = 0; s[i]; i ++ )
		{
			if( s[i] >= 'a' && s[i] <= 'z' )
				putchar(mps[s[i]-'a']);
			else
				putchar(s[i]);
		}
		puts("");
	}
	return 0;
}
