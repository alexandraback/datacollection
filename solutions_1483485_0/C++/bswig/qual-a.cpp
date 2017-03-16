#include <cstdio>

char key[] = "yhesocvxduiglbkrztnwjpfmaq";
char line[105];
int ntest;

int main()
{
	sscanf(gets(line), "%d", &ntest);
	for(int test = 1;test <= ntest;++test)
	{
		gets(line);
		for(int i = 0;line[i];++i)
			if(line[i] != ' ')
				line[i] = key[line[i] - 'a'];
		printf("Case #%d: %s\n", test, line);
	}
}
	
