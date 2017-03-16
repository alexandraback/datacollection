// TonTrans.cpp : Defines the entry point for the console application.
//
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

char origin_letters[] = {"abcdefghijklmnopqrstuvwxyz"};
char trans_letters[] =  {"yhesocvxduiglbkrztnwjpfmaq"};

char GetTransChar(char input)
{
	if (input>'z' || input < 'a')
		return input;

	for (int i = 0; i< 26; i++)
	{
		if (origin_letters[i] == input)
		{
			return trans_letters[i];
		}
	}
	return '*';
}

void WriteOutput(const char* strCase, FILE* fout, int index)
{
	fprintf(fout, "Case #%d: ", index+1);
	
	for (int i = 0; i< strlen(strCase); i++)
	{
		fputc(GetTransChar(*(strCase+i)), fout);
	}

}

int main(int argc, char* argv[])
{
	FILE* fp = fopen("A-small-attempt0.in", "r");
	FILE* fout = fopen("a-small.out", "w");
	char buffer[128] = {0};
	fgets(buffer, 128, fp);

	int case_count = atoi(buffer);
	case_count = (case_count > 30? 30: case_count);

	for (int i=0; i< case_count; i++)
	{
		fgets(buffer, 512, fp);
		WriteOutput(buffer, fout, i);
	}
	fclose(fout);
	fclose(fp);

	return 0;
}
