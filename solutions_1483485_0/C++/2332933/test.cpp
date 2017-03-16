#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define swap(a,b) a=a^b,b=a^b,a=a^b

const char list[]="ynficwlbkuomxsevzpdrjgthaq";//{'e','t','a','o','i','n','s','h','r','l','d','c','u','m','w','f','g','y','p','b','v','k','x','j','q','z'};

string in[35];
int con[26];
char conv[26];
int sum;

void out(string txt)
{
	int i,l=txt.length();
	for (i=0;i<l;i++)
	{
		if (txt[i]==' ')
			printf(" ");
		else
		{
			printf("%c",conv[txt[i]-'a']);
		}			
	}
	printf("\n");
}

int main()
{
//	freopen("1.txt", "r", stdin);
//	freopen("2.txt", "w", stdout);

	int i,j;
	int l;
	int t;
	int tt[26];
	scanf("%d",&t);
	getline(cin,in[0]);

	memset(con,0,sizeof(con));
	for (i=0;i<t;i++)
	{
		getline(cin,in[i]);
		l=in[i].length();
		for (j=0;j<l;j++)
		{
			if (in[i][j]!=' ')
			{
				con[in[i][j]-'a']++;
				sum++;
			}
		}
	}

	for (i=0;i<26;i++)
	{
		tt[i]=i;
	}
	for (i=0;i<26;i++)
	{
		for (j=i+1;j<26;j++)
		{
			if (con[j]>con[i])
			{
				swap(con[i],con[j]);
				swap(tt[i],tt[j]);
			}
		}
	}
	for (i=0;i<26;i++)
	{
//		conv[tt[i]]=list[i];
		conv[list[i]-'a']=i+'a';
	}

/*	int z;
	char a,b;
	scanf("%d",&z);
	for (i=0;i<z;i++)
	{
		cin>>a>>b;
		for (j=0;j<26;j++)
		{
			if (conv[j]==a)
				conv[j]=b;
			else if (conv[j]==b)
				conv[j]=a;
		}
	}*/

	for (i=0;i<t;i++)
	{
		printf("Case #%d: ",i+1);
		out(in[i]);
	}

	return 0;
}