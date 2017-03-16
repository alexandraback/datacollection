#include <cstdio>

int t,i,j;
char s[1000],ch;
int a[30];
	
int main ()
{
freopen("A-small-attempt0.in","r",stdin);
freopen("1.out","w",stdout);
a[1]=25;
a[2]=8;
a[3]=5;
a[4]=19;
a[5]=15;
a[6]=3;
a[7]=22;
a[8]=24;
a[9]=4;
a[10]=21;
a[11]=9;
a[12]=7;
a[13]=12;
a[14]=2;
a[15]=11;
a[16]=18;
a[17]=26;
a[18]=20;
a[19]=14;
a[20]=23;
a[21]=10;
a[22]=16;
a[23]=6;
a[24]=13;
a[25]=1;
a[26]=17;
	scanf("%d%c",&t,&ch);
	for(i=1;i<=t;i++)
	{
		gets(s);
		printf("Case #%d: ",i);
		for(j=0;s[j];j++)
		{
			if(s[j]==' ')printf(" ");
			else printf("%c",(char)('a'+(a[s[j]-'a'+1]-1)));
		}
		printf("\n");
	}
	
	return 0;
}

