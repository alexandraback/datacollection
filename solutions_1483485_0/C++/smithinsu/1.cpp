#include<cstdio>
#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<algorithm>
#include<cmath>
#include<string>
#include<cstdlib>
#include<climits>
#include<cstring>
using namespace std;
#define PB push_back
#define INF 1000000000
#define MOD 1000000007

map < char , char > maped;

void precompute(void)
{
	string learnin,learnout;
	int i,l1,l2,flag[26];
	learnin="ejp mysljylc kd kxveddknmc re jsicpdrysi rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd de kr kd eoya kw aej tysr re ujdr lkgc jv";
	learnout="our language is impossible to understand there are twenty six factorial possibilities so it is okay if you want to just give up";
	l1=learnin.size();
	l2=learnout.size();
//	printf("%d %d\n",l1,l2);
	for(i=0;i<26;i++)
	{
		maped[i+'a']='$';
		flag[i]=0;
	}
	for(i=0;i<l1;i++)
	{
		maped[learnin[i]]=learnout[i];
	}
	for(i=0;i<26;i++)
	{
//		printf("%d %d %d\n",i,i,maped[i+'a']-'a');
		flag[maped[i+'a']-'a']=1;
	}
	for(i=0;i<26;i++)
	{
//		if(!flag[i])
//			printf("%c\n",i+'a');
	}
	maped['q']='z';
	maped['z']='q';
}
int main()
{
	precompute();
	int test=0,i,l,t;
	char str[128];
	while(scanf("%d",&t)!=EOF)
	{
		test=0;
		while(t--)
		{
			scanf(" %[^\n]s",str);
			l=strlen(str);
			for(i=0;i<l;i++)
			{
				str[i]=maped[str[i]];
			}
			test++;
			printf("Case #%d: %s\n",test,str);
		}
	}
	return 0;
}
