#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main()
{
	char trans[] = "yhesocvxduiglbkrztnwjpfmaq";

	int T, caseNum;
	scanf("%d",&T);

	char str[256];
	gets(str);

	for(caseNum = 1; caseNum <= T; ++caseNum)
	{
		gets(str);
		printf("Case #%d: ", caseNum);
		for(int i=0; str[i]; ++i)
		{
			if(isalpha(str[i]))
				putchar(trans[str[i]-'a']);
			else
				putchar(str[i]);
		}
		putchar('\n');
	}
	return 0;
}

/*
「アルファベットを異なるアルファベットに置換する」暗号が送られてくるので復号してね
サンプル見るだけですか　そうですか

サンプル及び問題文中に出ていないのは'q'だけで、他の文字は全て出ているのでqはzになるのが確定します

*/
