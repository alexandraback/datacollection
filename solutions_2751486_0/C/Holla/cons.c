/* File name: main.c               */
/* Author: Sharath Holla K.        */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define INPUTFILE "input.in"
#define CMD_LINE_LENGTH 300

FILE *output_file;
FILE *input_file;
char temp_str[CMD_LINE_LENGTH];
char curr_cmd[CMD_LINE_LENGTH];

int isCons(char c)
{
	if(c == 'a')
		return 0;
	if(c == 'e')
		return 0;
	if(c == 'i')
		return 0;
	if(c == 'o')
		return 0;
	if(c == 'u')
		return 0;
	return 1;
}
int findsub(char *inp, int index, int len, int n)
{
	int count = 0;
	int i = index;
	while(count != n)
	{
		if(isCons(inp[i]))
			count++;
		else
			count = 0;
		i++;
		if(i >= len)
			break;
	}
	if(count != n)
		return 0;
	if(i == len)
		return 1;
	return ((len - i + 1)/*+ findsub(inp, i, len, n)*/);
}

void calc_routine(int index_i)
{
    int n, i;
	char inpStr[CMD_LINE_LENGTH];
	int num = 0;
	int cnt = 0;


    fscanf(input_file, "%s %d\n", inpStr, &n);
	cnt = strlen(inpStr);
	for(i = 0; i <= cnt-n; i++)
		num += findsub(inpStr, i, cnt, n);
	
	fprintf(output_file, "Case #%d: %d\n", index_i+1, num);
    return;
}

void main()
{
    int test_cases = 0;
    int index_i;
    input_file = fopen(INPUTFILE, "rt");
    output_file = fopen("output.txt", "wt");

    //fscanf(input_file, "%d", &test_cases);
    {
        fgets((char *)curr_cmd, CMD_LINE_LENGTH, input_file);
        sscanf((char *)curr_cmd, "%s", temp_str);
        test_cases = atoi(temp_str);
    }

    for (index_i = 0; index_i < test_cases; index_i++)
    {
        calc_routine(index_i);
    }

    fclose(input_file);
    fclose(output_file);
}