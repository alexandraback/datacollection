#include<string>
#include<algorithm>
#include<stdio.h>
using namespace std;

string segment[105];
char buffer[256];
int order[105];

bool checkvalid(const char* train)
{
	char tmp[30];
	int freq[26];
	for(int i=0;i<26;i++)
		freq[i]=0;
	tmp[0] = train[0];
	freq[train[0]-'a']++;
	int segcount = 1;
	for(int i=1;train[i]!=NULL;i++)
	{
		if(train[i]!=tmp[segcount-1])
		{
			tmp[segcount] = train[i];
			freq[train[i]-'a']++;
			if(freq[train[i]-'a']>1)
				return false;
			++segcount;
		}
	}
	return true;
}

int countpermutation(int N)
{
	string tmp;
	int res=0;
	do 
	{
		tmp="";
		for(int i=0;i<N;i++)
			tmp+=segment[order[i]];
		if(checkvalid(tmp.c_str()))
			++res;
	} 
	while ( next_permutation(order,order+N) );
	return res;
}

void main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int T,N;
	scanf("%d",&T);
	for(int cs=1;cs<=T;cs++)
	{
		scanf("%d",&N);
		for(int i=0;i<N;i++)
			order[i]=i;
		for(int i=0;i<N;i++)
		{
			scanf("%s",buffer);
			segment[i] = buffer;
		}
		printf("Case #%d: %d\n",cs,countpermutation(N));
	}
}