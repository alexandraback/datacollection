#include <stdio.h>
#include <string.h>
#define MAX 50
#define LEN 7
typedef struct {
	int result;
	int len;
	int or_a;
	int or_b;
	int present;
	char a_in[LEN];
	int a[LEN];
}a;
a range[MAX];
int t;

void in_ana(void)
{
	int i=0, j=0;
	for(i=0; i<t; i++)
	{
		for(j=0; j<range[i].len; j++)
		{
			range[i].a[j]=range[i].a_in[j]-48;
		}
	}
}

void f_in(FILE *in)
{
	int i=0;
	in=fopen("C-large.in", "r");
	fscanf(in, "%d", &t);
	for(i=0; i<t; i++)
	{
		fscanf(in, "%s %d", &range[i].a_in, &range[i].or_b);
		range[i].len=strlen(range[i].a_in);
	}
	in_ana();
	fclose(in);
}

void ana(int index)
{
	int i=0, mul=1;
	for(i=range[index].len-1; i>=0; i--)
	{
		range[index].or_a+=range[index].a[i]*mul;
		mul*=10;
	}
}
void carry(int index)
{
	int i=0;
	for(i=range[index].len-1; i>=0; i--)
	{
		if(range[index].a[i]==10)
		{
			range[index].a[i]=0;
			range[index].a[i-1]+=1;
		}
	}
}
void shift(int index)
{
	int i=0, j=0, temp=0, mul=1, diff=range[index].len-1, result_temp[LEN], point=0, k=0, check=0;
	for(i=range[index].len-1; i>=0; i--)
	{
		range[index].present+=range[index].a[i]*mul;
		mul*=10;
	}
	mul=1;
	for(i=1; i<range[index].len; i++)
	{
		for(j=range[index].len-1; j>=0; j--)
		{
			temp+=range[index].a[diff-i]*mul;
			mul*=10;
			diff--;
			if((diff+1-i)==0)
			{
				diff=(range[index].len-1)+i;
			}
		}
		if(range[index].present<temp && temp<=range[index].or_b)
		{
			range[index].result++;
			for(k=0; k<point; k++)
			{
				if(result_temp[k]==temp)
				{
					range[index].result--;
					check=1;
				}
			}
			if(check==0)
			{
				result_temp[point]=temp;
				point++;
			}
			check=0;
		}
		mul=1;
		temp=0;
		diff=range[index].len-1;
	}
	range[index].present=0;
}
void loop(int index)
{
	int i=0, j=0;
	for(i=range[index].or_a; i<=range[index].or_b; i++)
	{
		shift(index);
		range[index].a[range[index].len-1]++;
		carry(index);
	}
}

void f_out(FILE *out)
{
	int i=0;
	out=fopen("output.out", "w");
	for(i=0; i<t; i++)
	{
		fprintf(out, "Case #%d: %d\n", i+1, range[i].result);
	}
	fclose(out);
}
int main(void)
{
	int i=0;
	FILE *in=0, *out=0;
	f_in(in);
	for(i=0; i<t; i++)
	{
		ana(i);
		loop(i);
	}
	f_out(out);
	return 0;
}