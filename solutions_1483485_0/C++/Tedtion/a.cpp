#include <stdio.h>
#include <string.h>

int main()
{
	int n,i,t;
	char in[188], out[188], gmap[129] = "yhesocvxduiglbkrztnwjpfmaq";

	freopen("A-small.in", "r", stdin);
	freopen("a_res.out", "w", stdout);

	scanf("%d",&t);
	gets(in);
	for (int cas = 1; cas <= t; cas++)
	{
		gets(in);
		for (i=0; in[i]; i++)
		{
			if (in[i] != ' ') out[i] = gmap[in[i]-'a'];
			else out[i] = ' ';
		}
		out[i] = 0;
		printf("Case #%d: %s\n", cas, out);
	}
	return 0;
}

