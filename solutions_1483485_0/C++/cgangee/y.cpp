#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<climits>
using namespace std;

int i,j,k,m,n,l;
int a[26]={24, 7, 4, 18, 14, 2, 21, 23, 3, 20, 
            8, 6, 11, 1, 10, 17, 25, 19, 13, 22, 
            9, 15, 5, 12, 0, 16 };
char s[1000], t[1000];

int main()
{
	freopen("stdin.txt","r",stdin);
	freopen("stdout.txt","w",stdout);
	int T;
	scanf("%d\n",&T);
	for (int t=1; t<=T; t++)
	{		
		gets(s);
		for (i=0; i<strlen(s); i++) if (s[i]!=' ')
			s[i]=a[s[i]-'a']+'a';
        printf("Case #%d: %s\n",t,s);
	}
	return 0;
}
