using namespace std;
#include <iostream>
char multi(char a,char b)
{
	switch(a)
	{
	case '1':return b;break;
	case '2':switch(b)
			 {
			case 'i':return 'a';break;
			case 'j':return 'b';break;
			case 'k':return 'c';break;
			 }
			 break;
	case 'i':switch(b)
			{
			case 'i':return '2';break;
			case 'j':return 'k';break;
			case 'k':return 'b';break;
			 }
			 break;
	case 'a':switch(b)
			 {
			case 'i':return '1';break;
			case 'j':return 'c';break;
			case 'k':return 'j';break;
			 }
			 break;
	case 'j':switch(b)
			 {
			case 'i':return 'c';break;
			case 'j':return '2';break;
			case 'k':return 'i';break;
			 }
			 break;
	case 'b':switch(b)
			 {
			case 'i':return 'k';break;
			case 'j':return '1';break;
			case 'k':return 'a';break;
			 }
			 break;
	case 'k':switch(b)
			 {
			case 'i':return 'j';break;
			case 'j':return 'a';break;
			case 'k':return '2';break;
			 }
			 break;
	case 'c':switch(b)
			 {
			case 'i':return 'b';break;
			case 'j':return 'i';break;
			case 'k':return '1';break;
			 }
			 break;
	}
}
int main()
{
	FILE *fp1,*fp2;
	int n,c,h,l,m,a,b,r;
	if((fp1=fopen("C-small-attempt1.in","r"))==NULL)
	{
		printf("cannot open this file\n");
		exit(0);
	}
	fp2=fopen("C-small-attempt1.out","w");
	fscanf(fp1,"%d\n",&a);
	char *p,i,j,k,s;
	for(b=0;b<a;b++)
	{
	i='1',j='1',k='1',s='1';
	fscanf(fp1,"%d %d\n",&c,&r);
	p=new char[c+1];
	fgets(p,c+1,fp1);
	for(h=0;h<c;h++)
		s=multi(s,p[h]);
	for(h=0;h<c*r-2;h++)
	{
		i=multi(i,p[h%c]);
		if(i=='i')
		{
			for(l=h+1;l<c*r-1;l++)
			{
				j=multi(j,p[l%c]);
				if(j=='j')
				{
					for(m=l+1;m<c*r;m++)
						k=multi(k,p[m%c]);
					goto loop;
				}
			}
			if(l==c*r-1)
				break;
		}
	}
	printf("Case #%d: NO\n",b+1);
	fprintf(fp2,"Case #%d: NO\n",b+1);
	continue;
	loop:
	{
		if(k=='k')
		{
			printf("Case #%d: YES\n",b+1);
			fprintf(fp2,"Case #%d: YES\n",b+1);
		}
		else
		{
			printf("Case #%d: NO\n",b+1);
			fprintf(fp2,"Case #%d: NO\n",b+1);
		}

	}
	}
	fclose(fp1);
	fclose(fp2);
	getchar();
	getchar();
	return 0;
}