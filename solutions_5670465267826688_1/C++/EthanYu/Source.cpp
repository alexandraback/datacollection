#include <stdio.h>
#include<stdlib.h>
#include<string.h>


char form[9][9] = {
		{ 0, 1, 2, 3, 4, 5, 6, 7, 8 },
		{ 1, 1, 2, 3, 4, 5, 6, 7, 8 },
		{ 2, 2, 5, 4, 7, 6, 1, 8, 3 },
		{ 3, 3, 8, 5, 2, 7, 4, 1, 6 },
		{ 4, 4, 3, 6, 5, 8, 7, 2, 1 },
		{ 5, 5, 6, 7, 8, 1, 2, 3, 4 },
		{ 6, 6, 1, 8, 3, 2, 5, 4, 7 },
		{ 7, 7, 4, 1, 6, 3, 8, 5, 2 },
		{ 8, 8, 7, 2, 1, 4, 3, 6, 5 }
};

char str[110000];
char kmark[110000];
char imark[110000];
long long X;
int  L, resL;
char cal(char x, char in)
{
	return form[x][in];
}

void forminit()
{
	for (int i = 0; i < L; i++)
		str[i] = str[i] - 'i' + 2;
	for (int i = 0; i < L; i++)
		for (int j = 1; j < X; j++)
		{
			str[i + j*L] = str[i];
		}

	kmark[X*L - 1] = cal(1, str[X*L - 1]);
	for (int i = X*L-1; i > 0; i--)
	{
		kmark[i - 1] = cal(str[i - 1], kmark[i]);
	}
	imark[0] = cal(1, str[0]);
	for (int i = 1; i < X*L; i++)
	{
		imark[i] = cal(imark[i - 1], str[i]);
	}
}


int main()
{
	int N;
	char t;
	int templen;
	FILE *fp;
	FILE *fpread;
	fopen_s(&fp, "out03.out", "wt+");
	fopen_s(&fpread, "in.in", "r");
	fscanf_s(fpread,"%d", &N);
	for (int Case = 1; Case <= N; Case++)
	{
		resL= 0;
		int yn = 0;
		char tempchar;
		fscanf_s(fpread,"%d", &L);
		fgets(str, 10002, fpread);
		templen = strlen(str);
		if (templen == 3)
		{
			X = str[templen - 2] - '0';
		}
		else
			X = str[templen - 2] -'0'+ (str[templen - 3]-'0') * 10;
		if(X>X % 4 + 8)
			X=X%4+8;
		//fgetchar(fpread);
		fgets(str, 10002, fpread);
		forminit();

		for (int i = 0; i < X*L; i++)
		{
			if (imark[i] == 2)
			{
				char tempj = 1;
				for (int j = i + 1; j < X*L-1; j++)
				{
					tempj=cal(tempj, str[j]);
					if (tempj == 3 && kmark[j + 1] == 4)
					{
						yn = 1;
						break;
					}

				}
				if (yn == 1)
					break;
			}
		}
		
		if (yn == 1)
		{
			fprintf(fp, "Case #%d: YES\n", Case);
			printf("Case #%d: YES\n", Case);
		}
		else
		{
			fprintf(fp, "Case #%d: NO\n", Case);
			printf("Case #%d: NO\n", Case);
		}

	}
	fclose(fp);
	fclose(fpread);
	system("Pause");
	return 0;
}