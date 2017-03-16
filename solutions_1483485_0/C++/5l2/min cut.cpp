#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

char tmp1[110],tmp2[110];
int  len;
int  a[27];
void getdi()
{
	int i,j;
	for(i=1;i<=3;++i)
	{
		gets(tmp1);
		gets(tmp2);
		len=strlen(tmp1);
		for(j=0;j<len;++j)
		{	
			a[tmp1[j]-'a']=tmp2[j]-'a';
		}
	}
	a['q'-'a']='z'-'a';
	a['z'-'a']='q'-'a';
}
int main()
{
	int n,i,j;
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	getdi();
	scanf("%d\n",&n);
	for(i=1;i<=n;++i)
	{
		printf("Case #%d: ",i);
		gets(tmp1);
		len=strlen(tmp1);
		j=0;
		for(j=0;j<len;++j)
		{
			if(tmp1[j]==' ') printf(" ");
			else printf("%c", a[tmp1[j]-'a']+'a');
		}
		printf("\n");
	}
  /*
	for(i=0;i<26;++i)
	{
		printf("%c--->%c\n", i+'a', a[i]+'a');
	}
	*/
	return 0;
}