#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "math.h"

char fs[39][14]=
{
"1",
"4",
"9",
"121",
"484",
"10201",
"12321",
"14641",
"40804",
"44944",
"1002001",
"1234321",
"4008004",
"100020001",
"102030201",
"104060401",
"121242121",
"123454321",
"125686521",
"400080004",
"404090404",
"10000200001",
"10221412201",
"12102420121",
"12345654321",
"40000800004",
"1000002000001",
"1002003002001",
"1004006004001",
"1020304030201",
"1022325232201",
"1024348434201",
"1210024200121",
"1212225222121",
"1214428244121",
"1232346432321",
"1234567654321",
"4000008000004",
"4004009004004"
};

char AA[15];
char BB[15];


int main()
{
	int T;
	int t=1;
	int flag;
	int lena;
	int lenb;
	int lenfs;
	scanf("%d",&T);
	while(t<=T)
	{
		flag=0;
		memset(AA,'\0',15);
		memset(BB,'\0',15);
		scanf("%s%s",&AA,&BB);
		lena=(int)strlen((const char *)AA);
		lenb=(int)strlen((const char *)BB);
		for(int i=0;i<39;i++)
		{
			lenfs=(int)strlen((const char *)fs[i]);
			if(lenfs>=lena&&lenfs<=lenb)
			{
				if(lenfs==lena&&lenfs<lenb)
					if(strcmp((const char *)fs[i],(const char *)AA)>=0)flag++;
				if(lenfs>lena&&lenfs==lenb)
					if(strcmp((const char *)fs[i],(const char *)BB)<=0)flag++;
				if(lenfs>lena&&lenfs<lenb)flag++;
				if(lenfs==lena&&lenfs==lenb)
					if((strcmp((const char *)fs[i],(const char *)AA)>=0)&&(strcmp((const char *)fs[i],(const char *)BB)<=0))flag++;
			}
		}
		printf("Case #%d: %d\n",t,flag);
		t++;
	}
	return 0;
}