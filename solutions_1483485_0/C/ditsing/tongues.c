#include <stdio.h>
#include <string.h>
#define MAXN 260

int rep[MAXN];
const char inp[][100] = 
{
	"ejp mysljylc kd kxveddknmc re jsicpdrysi",
	"our language is impossible to understand",
	"rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd",
	"there are twenty six factorial possibilities",
	"de kr kd eoya kw aej tysr re ujdr lkgc jv",
	"so it is okay if you want to just give up"
};

char input[1000];

int main()
{
	memset( rep, 0, sizeof( rep));

	int T = 3;
	while ( T--)
	{
		int L = strlen( inp[T<<1]);
		int i;
		for ( i = 0; i < L; i++)
		{
			int n = inp[T<<1][i];
			int o = inp[(T<<1)+1][i];
			if ( !rep[n])
			{
				rep[n] = o;
			}
			else
			{
				if ( rep[n] != o)
				{
					printf("ERROR %d %d %d\n", n, o, rep[n]);
				}
			}
		}
	}

	rep['y'] = 'a';
	rep['e'] = 'o';
	rep['z'] = 'q';
	rep['q'] = 'z';


	scanf("%d ", &T);
	int t;
	for ( t = 0; t < T; t++)
	{
		fgets( input, 1000, stdin);
		int L = strlen( input);
		int i;
		for ( i = 0; i < L; i++)
		{
			input[i] = rep[(int)input[i]];
		}
		printf("Case #%d: ", t + 1);
		fputs( input, stdout);
		printf("\n");
	}

	return 0;
}
