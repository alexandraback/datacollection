#pragma warning(disable:4786)
#include<math.h>
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<utility>
#include<algorithm>
#include<string.h>
#include<stdio.h>
#include<set>
#include<stdlib.h>
#include<sstream>
#include<functional>
#include<queue>
#include<stack>
using namespace std;

#define MAX(A,B) ((A)>(B)?(A):(B))
#define MIN(A,B) ((A)<(B)?(A):(B))
#define ABS(A) ((A)>0?(A):(-(A)))
#define S(X) ((X)*(X))

typedef pair<int,int> PII;

//int dr[]={-1,0,1,0};
//int dc[]={0,1,0,-1};
//int dr[]={-2,-2,-1,1,2,2,1,-1};
//int dc[]={-1,1,2,2,1,-1,-2,-2};

typedef __int64 LL;
#define I64d "%I64d"

char input[10][100]=
{
	"ejp mysljylc kd kxveddknmc re jsicpdrysi",
	"rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd",
	"de kr kd eoya kw aej tysr re ujdr lkgc jv"
};

char output[10][100]=
{
	"our language is impossible to understand",
	"there are twenty six factorial possibilities",
	"so it is okay if you want to just give up"
};

int M[500];

void gen()
{
	int i, j, len;

	for(i='a';i<='z';i++)
		M[i] = 0;

	for(i=0;i<3;i++)
	{
		len = strlen(input[i]);
		if(len!=strlen(output[i])) printf("!\n");
		for(j=0;j<len;j++)
			if(input[i][j]!=' ')
			{
				if(M[input[i][j]]==0) M[input[i][j]] = output[i][j];
				else if(M[input[i][j]]!=output[i][j]) printf("!!\n");
			}
	}

	M['z'] = 'q';
	M['q'] = 'z';
	M[' '] = ' ';
	for(i='a';i<='z';i++)
		if(M[i]==0)
		{
			printf("%c!!!\n",i);
		}

}

int main()
{
	freopen("A-small-attempt1.in","r",stdin);
	freopen("A-small-attempt1.out","w",stdout);

//	freopen("B-large.in","r",stdin);
//	freopen("B-large.out","w",stdout);

	int T, ks,i;
	char ch;
	char str[200];

	gen();
	scanf("%d",&T);
	scanf("%c",&ch);
	for(ks=1;ks<=T;ks++)
	{
		
		printf("Case #%d: ",ks);

		gets(str);
//		if(!(ks==4 || ks==5))
		{
			for(i=0;str[i];i++)
				str[i] = M[str[i]];
		}
		printf("%s\n",str);	

	}

	return 0;
}