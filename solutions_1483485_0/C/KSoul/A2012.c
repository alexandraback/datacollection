#include <stdio.h>

int main()
{
	FILE *pFile1,*pFile2;
	pFile1=fopen("A-small-attempt3.in","r");
	pFile2=fopen("A-small.out","w");
	int i,t,size;
	char sen[102],buff;
	fscanf(pFile1,"%d%c",&t,&buff);
	for(i=0;i<t;i++)
	{
		fgets(sen,102,pFile1);
		for(size=0;sen[size]!='\0';size++)
		{
			if(sen[size]=='a') sen[size]='y';
			else if(sen[size]=='b') sen[size]='h';
			else if(sen[size]=='c') sen[size]='e';
			else if(sen[size]=='d') sen[size]='s';
			else if(sen[size]=='e') sen[size]='o';
			else if(sen[size]=='f') sen[size]='c';
			else if(sen[size]=='g') sen[size]='v';
			else if(sen[size]=='h') sen[size]='x';
			else if(sen[size]=='i') sen[size]='d';
			else if(sen[size]=='j') sen[size]='u';
			else if(sen[size]=='k') sen[size]='i';
			else if(sen[size]=='l') sen[size]='g';
			else if(sen[size]=='m') sen[size]='l';
			else if(sen[size]=='n') sen[size]='b';
			else if(sen[size]=='o') sen[size]='k';
			else if(sen[size]=='p') sen[size]='r';
			else if(sen[size]=='q') sen[size]='z';
			else if(sen[size]=='r') sen[size]='t';
			else if(sen[size]=='s') sen[size]='n';
			else if(sen[size]=='t') sen[size]='w';
			else if(sen[size]=='u') sen[size]='j';
			else if(sen[size]=='v') sen[size]='p';
			else if(sen[size]=='w') sen[size]='f';
			else if(sen[size]=='x') sen[size]='m';
			else if(sen[size]=='y') sen[size]='a';
			else if(sen[size]=='z') sen[size]='q';
		}
		fprintf(pFile2,"Case #%d: %s",i+1,sen);
	}
	
    return 0;
}
