#include <cstdio>
#include <cctype>
using namespace std;

char buf[1024];
int main()
{
    int T;
    scanf("%d", &T);
    fgets(buf, sizeof(buf), stdin);
    for(int testnum = 1; testnum <= T; testnum++)
    {
        printf("Case #%d: ", testnum);

	fgets(buf, sizeof(buf), stdin);
	for(int i = 0; buf[i] != '\n'; i++)
	    if(isalpha(buf[i]))
		printf("%c", "yhesocvxduiglbkrztnwjpfmaq"[buf[i] - 'a']);
	    else
		printf("%c", buf[i]);
	printf("\n");

    }
    return 0;
}
