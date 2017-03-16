#include <stdio.h>
#include <string.h>
#define MAX 200
#define LETTER 26
#define TEST 30
typedef struct {
	char st[MAX];
	int len;
}a;
a st[TEST];
char letter[LETTER][2];
int t;
void f_in(FILE *in)
{
	int i=0;
	char temp;
	fflush(stdin);
	in=fopen("A-small-attempt1.in", "r");
	fscanf(in, "%d%c", &t, &temp);
	for(i=0; i<t; i++)
	{
		fgets(st[i].st, MAX, in);
		st[i].len=strlen(st[i].st);
	}
}

void data(void)
{
	int i=0;
	char ch='a';
	for(i=0; i<LETTER; i++)
	{
		letter[i][0]=ch;
		ch++;
	}
	letter[0][1]='y', letter[1][1]='h', letter[2][1]='e', letter[3][1]='s', letter[4][1]='o';
	letter[5][1]='c', letter[6][1]='v', letter[7][1]='x', letter[8][1]='d', letter[9][1]='u';
	letter[10][1]='i', letter[11][1]='g', letter[12][1]='l', letter[13][1]='b', letter[14][1]='k';
	letter[15][1]='r', letter[16][1]='z', letter[17][1]='t', letter[18][1]='n', letter[19][1]='w';
	letter[20][1]='j', letter[21][1]='p', letter[22][1]='f', letter[23][1]='m', letter[24][1]='a';
	letter[25][1]='q';
}

void exchange(int index)
{
	int i=0, j=0;
	for(i=0; i<st[index].len; i++)
	{
		if(st[index].st[i]!=NULL)
		{
			for(j=0; j<LETTER; j++)
			{
				if(st[index].st[i]==letter[j][0])
				{
					st[index].st[i]=letter[j][1];
					break;
				}
			}
		}
	}
}

void f_out(FILE *out)
{
	int i=0, j=0;
	out=fopen("output.out", "w");
	for(i=0; i<t; i++)
	{
		fprintf(out, "Case #%d: ", i+1);
		for(j=0; j<st[i].len; j++)
		{
			fprintf(out, "%c", st[i].st[j]);
		}
	}
}
int main(void)
{
	int i=0;
	FILE *in=0, *out=0;
	f_in(in);
	data();
	for(i=0; i<t; i++)
	{
		exchange(i);
	}
	f_out(out);
	return 0;
}
