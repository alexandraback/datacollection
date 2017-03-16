#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#define fc(x) fputc(x,f2)
FILE *f1,*f2;
char map[26];
void st()
{
	map[0]='y';
	map[1]='n';
	map[2]='f';
	map[3]='i';
	map[4]='c';
	map[5]='w';
	map[6]='l';
	map[7]='b';
	map[8]='k';
	map[9]='u';
	map[10]='o';
	map[11]='m';
	map[12]='x';
	map[13]='s';
	map[14]='e';
	map[15]='v';
	map[16]='z';
	map[17]='p';
	map[18]='d';
	map[19]='r';
	map[20]='j';
	map[21]='g';
	map[22]='t';
	map[23]='h';
	map[24]='a';
	map[25]='q';
}
char re(char c)
{
	int i;
	for(i=0;i<26;i++)
	{
		if(map[i]==c)
		return(i+'a');
	}
	return(' ');
}
void Main()
{
	char c,ch,str[500],co=0;
	int i;
/*	c=fgetc(f1);
	if((c!='\n')&&(c!=' '))
	{
	fputc(map[c-'a'],f2);
	}*/
	c=fgetc(f1);
	while(c!='\n')
	{
		str[co++]=c;
		c=fgetc(f1);
	}
	for(i=0;i<co;i++)
	str[i]=re(str[i]);
	str[co]='\0';
	fprintf(f2,"%s",str);
}
int main()
{
	f1=fopen("/home/vivek/Desktop/s.in","r");
	f2=fopen("/home/vivek/Desktop/s.out","w");
	int cs,i;
	char c;
	st();
	fscanf(f1,"%d",&cs);
	while(fgetc(f1)!='\n');
	for(i=1;i<=cs;i++)
	{
		fprintf(f2,"Case #%d: ",i);
		Main();
		c='\n';
		fputc(c,f2);
		printf("%d",i);
	}
	return(1);
}
