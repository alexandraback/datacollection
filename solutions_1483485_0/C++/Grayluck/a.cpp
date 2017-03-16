#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <iostream>
#include <cmath>
#include <set>
#include <ctime>
#include <algorithm>
#define min(a,b)	((a)<(b)?(a):(b))
#define max(a,b)	((a)>(b)?(a):(b))
#define abs(a)	((a)<0?-(a):(a))
#define inf 214748364
#define pi 3.141592653589793
using namespace std;
typedef long long ll;
//           abcdefghijklmnopqrstuvwxyz
char ma[30]="yhesocvxduiglbkrqtnwjpfmaz";
char mb[30]="yhesocvxduiglbkrztnwjpfmaq";

void readln()
{
	char ch;
	scanf("%c",&ch);
	while(ch!='\n')
		scanf("%c",&ch);
}

int main()
{
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	int tim;
	scanf("%d",&tim);
	readln();
	for(int tt=1;tt<=tim;++tt)
	{
		printf("Case #%d: ",tt);
		while(1)
		{
			char ch;
			scanf("%c",&ch);
			if('a'<=ch&&ch<='z')
				printf("%c",mb[ch-'a']);else
				printf("%c",ch);
			if(ch=='\n')
				break;
		}
	}
	return 0;
}

