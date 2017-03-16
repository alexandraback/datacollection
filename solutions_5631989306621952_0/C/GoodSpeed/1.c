#include<stdio.h>
#include<memory.h>
#include<math.h>
#include<string.h>

#define Tmax 100
#define Nmax 1001


void Last(char *s,int length)
{
	int i,j;
	char c[Nmax];
	if(length<=1) return;
	Last(s,length-1);
	c[0] = s[length-1];
	for(i=1;i<length;i++)	c[i] = s[i-1];
	for(i=0;i<length;i++)
	{
		if(s[i]>c[i])	return;
		else if(s[i]<c[i])
		{
			for(j=0;j<length;j++)
			{
				s[j]=c[j];
			}
			return;
		}
		else continue;
	}
	return;
}

int main()
{
	int T,k,length;
	FILE *fin,*fout;
	char s[Nmax];
	fin = fopen("A-small-attempt0.in","r");
	if(fin == NULL)
	{
		printf("Cannot open the file!\n");
		return(0);
	}
	fout = fopen("output.txt","w");
	if(fout == NULL)
	{
		printf("Cannot open the file!\n");
		return(0);
	}
	fscanf(fin,"%d",&T);
	for(k=1;k<=T;k++)
	{
		fscanf(fin,"%s",&s);
		length = strlen(s);
		Last(s,length);
		fprintf(fout,"Case #%d: %s\n",k,s);
		printf("%s\n",s);
	}
	fclose(fin);
	fclose(fout);
	
}
