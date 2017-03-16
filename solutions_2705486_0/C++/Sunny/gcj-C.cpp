#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<cstdio>
#include<cassert>
#include<iostream>
#include<queue>
#include<map>
#include<set>
#include<vector>
#include<ctime>

using namespace std;

#define MEM(a,b) memset(a,(b),sizeof(a))
#define MAX(a,b)  ((a) > (b) ? (a) : (b))
#define MIN(a,b)  ((a) < (b) ? (a) : (b))

#define MP make_pair
#define pb push_back
#define inf  1000000000
#define maxn 100001
#define maxc 100001
#define MP make_pair

typedef long long LL;
//typedef long long LL;

typedef pair<LL,LL> pi;
typedef pair<pi,LL> pii;


set<LL> S1;
set<pi> S2;
set<pii> S3;

LL pw[17];


pii calc3(char *str,int l,int i,int j,int p)
{
	LL a=0,b=0,c=0;
	int k;

	for(k=0;k<l;k++)
	{
		int d=str[p+k]-'a'+1;

		if(k<i)
			a=a*27+d;
		else if(k>i && k<j)
			b=b*27+d;
		else if(k>j)
			c=c*27+d;
	}
	return MP(MP(a,b),c);
}

pi calc2(char *str,int l,int i,int p)
{
	LL a=0,b=0;
	int k;

	for(k=0;k<l;k++)
	{
		int d=str[p+k]-'a'+1;
		if(k<i)
			a=a*27+d;
		else if(k>i)
			b=b*27+d;
	}
	return MP(a,b);
}

LL calc(char *str,int l,int p)
{
	LL a=0;
	int k;

	for(k=0;k<l;k++)
	{
	    int d=str[p+k]-'a'+1;
		a=a*27+d;
	}
	return a;
}

void LoadFile()
{
	FILE *fl = fopen("garbled_email_dictionary.txt","r");
	int i,j,k,maxl=0,cnt=0;
	char str[20];

	while(fscanf(fl,"%s",str)!=EOF)
	{
		LL v=0;
		for(i=0;str[i];i++)
			v=(v*27+str[i]-'a'+1);

		S1.insert(v);
		int l=i;

        //if(cnt>520000) printf("%d %s %I64d\n",cnt,str,v);
		for(i=0;i<l;i++)
		{
			for(j=i+5;j<l;j++)
			{
				pii now=calc3(str,l,i,j,0);
				S3.insert(now);

				//if(cnt<3) printf("%d %d %I64d %I64d %I64d\n",i,j,now.first.first,
                    // now.first.second,now.second);
			}

			pi u=calc2(str,l,i,0);
			S2.insert(u);

		}
		cnt++;
		maxl=MAX(maxl,i);
	}
	fclose(fl);
	//printf("%d %d %d\n",maxl,S2.size(),S3.size());
}

char text[4005];
int L;
int memo[4005][12][12][12];

int solve(int pos,int last,int x,int y)
{
	int ret=inf;

	if(pos>L || pos-last+1>10) return inf;
	if(pos==L && last==L) return  0 ;
	if(memo[pos][pos-last][x][y]!=-1) return memo[pos][pos-last][x][y];

	int q;

	q=solve(pos+1,last,x,y);
	ret=MIN(ret,q);

    if(x==10)
	{
		q=1+solve(pos+1,last,pos-last,y);
		ret=MIN(ret,q);
	}

	if(x!=10 && y==10)
	{
		q=1+solve(pos+1,last,x,pos-last);
		ret=MIN(ret,q);
	}

	int l=pos-last;


	if(x==10 && y==10)
	{
		LL now= calc(text,l,last);
		if(S1.find(now)!=S1.end())
		{
			q=solve(pos,pos,10,10);
			ret=MIN(ret,q);
		}
	}


	if(x!=10 && y==10)
	{
		pi now= calc2(text,l,x,last);
		if(S2.find(now)!=S2.end())
		{
			q=solve(pos,pos,10,10);
			ret=MIN(ret,q);
		}

		//printf("%d %d %I64d %I64d\n",pos,x,now.first,now.second);
	}

	if(x!=10 && y!=10)
	{
		pii now= calc3(text,l,x,y,last);
		if(S3.find(now)!=S3.end())
		{
			q=solve(pos,pos,10,10);
			ret=MIN(ret,q);
		}
	}

    //printf("%d %d %d %d %d\n",pos,last,x,y,ret);
	return memo[pos][pos-last][x][y]=ret;
}

int main()
{
	int i,j,k,tests,cs=0,K;
	string s;

	LoadFile();

    cin>>i;

	freopen("C-small-attempt2.in","r",stdin);
	freopen("C-small-attempt2.out","w",stdout);
	scanf("%d",&tests);

	while(tests--)
	{
	    scanf("%s",text);
	    L=strlen(text);
	    MEM(memo,-1);
	    int ans=solve(0,0,10,10);
		printf("Case #%d: %d\n",++cs,ans);
	}

	return 0;
}
