#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <map>
#include <string>
#include <string.h>
#include <queue>
#include <set>
#include <complex>
#include <iostream>
#include <fstream>
#include <time.h>
using namespace std;
const int T_SIZE=1125077+1,NUM=26;
int l;
char s[51];
int dp[51][T_SIZE][6];
struct trie
{
	trie* next[NUM];
	bool have;
	int id;
}T[T_SIZE],*root;
int trie_sz,ans;
void Build_trie()
{
	trie *p=root;
	char c;
	while((c=getchar())&&c!='\n')
	{
		c-='a';
		if(p->next[c]==NULL)
		{
			p->next[c]=&T[trie_sz];
			T[trie_sz].id=trie_sz;
			trie_sz++;
		}
		p=p->next[c];
	}
	p->have=1;
}
int dfs(int idx,int id,int dif)
{
	if(idx==l)
	{
		if(id==0) return 0;
		else return 4000; 
	}
	int &res=dp[idx][id][dif];
	if(res==-1)
	{
		res=4000;
		trie *p;
		p=&T[id];
		char now=s[idx]-'a';
		if(p->next[now]!=NULL)
		{
			p=p->next[now];
			res=min(res,dfs(idx+1,p->id,min(dif+1,5)));
			if(p->have) res=min(res,dfs(idx+1,0,min(dif+1,5)));
		}
		if(dif>=5)
		{
			for(int i=0;i<26;i++)
			{
				if(i==now) continue;
				p=&T[id];
				if(p->next[i]!=NULL)
				{
					p=p->next[i];
					res=min(res,dfs(idx+1,p->id,1)+1);
					if(p->have) res=min(res,dfs(idx+1,0,1)+1);
				}
			}
		}
	}
	return res;
}
int main()
{
	freopen("garbled_email_dictionary.txt","r",stdin);
	root=&T[0];
	trie_sz=1;
	for(int i=1;i<=521196;i++) 
		Build_trie();
	freopen("C-small-attempt0.in","r",stdin);
	freopen("a.out","w",stdout);
	int cas;
	scanf("%d",&cas);
	for(int cs=1;cs<=cas;cs++)
	{
		memset(dp,-1,sizeof(dp));
		scanf("%s",s);
		l=strlen(s);
		int ans=4000;
		printf("Case #%d: %d\n",cs,dfs(0,0,5));
	}
}
