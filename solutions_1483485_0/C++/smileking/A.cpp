/*
 * A.cpp
 *
 *  Created on: 2012-4-14
 *      Author: jesliwang
 */

#include <stdio.h>

using namespace std;

char str[] = "yhesocvxduiglbkrztnwjpfmaq";

int main(int argc, char* argv[])
{
	int T = 0;
	int i = 0;
	scanf("%d\n", &T);
	for( i = 1; i <= T; i++)
	{
		char tmp[110];
		gets(tmp);
		printf("Case #%d: ", i);
		for(int j = 0; tmp[j] != 0; j++)
		{
			if(tmp[j] >= 'a' && tmp[j] <= 'z')
				tmp[j] = str[ tmp[j] - 'a' ];
		}
		printf("%s\n", tmp);
	}
	return 0;
}



