#pragma comment(linker, "/STACK:65000000")
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<set>
#include<map>
#include<cstring>
#include<string>
#include<cmath>
#include<ctime>

using namespace std;

#define ll long long
#define pii pair<int,int>
#define vi vector<int>
#define vit vi::iterator
#define vpi vector<pii >
#define sq(x) (x)*(x)

char mas[256];
char buf1[256];
char buf2[256];
int n;
char str[] = "yhesocvxduiglbkrztnwjpfmaq";

int main()
{
	/*for(int i=0; i<3; ++i)
	{
		gets(buf1);
		gets(buf2);
		for(int j=0; buf1[j]; ++j)
			mas[buf1[j]]=buf2[j];
	}
	for(char a = 'a'; a<='z'; ++a)
		printf("%c %c\n",a,mas[a]);*/
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	scanf("%d",&n);
	gets(buf1);
	for(int i=0; i<n; ++i)
	{
		gets(buf1);
		for(int j=0; j==0 || buf1[j-1]; ++j)
		{
			if(buf1[j]>='a' && buf1[j]<='z')
				buf2[j] = str[buf1[j]-'a'];
			else
				buf2[j]=buf1[j];
		}
		printf("Case #%d: %s\n",i+1,buf2);
	}
	return 0;
}