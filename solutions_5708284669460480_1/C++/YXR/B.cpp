#include<cstdio>
#include<cstring>
#include<iostream>
#include<cstdlib>
#include<algorithm>
using namespace std;
void getAns(const int Case)
{
	static int K,L,S;
	static char key[200];
	static char tar[200];
	static int a[30];
	static int p[200];
	scanf("%d%d%d",&K,&L,&S);
	scanf("%s%s",key,tar);
	memset(a,0,sizeof a);
	for(int i=0;i<K;++i)
		++a[key[i]-'A'];
	p[0]=-1;
	for(int i=1;i<L;++i)
	{
		int k=p[i-1];
		while(k!=-1&&  tar[k+1]!=tar[i])
			k=p[k];
		if(tar[k+1]==tar[i])
			p[i]=k+1;
		else p[i]=-1;
	}
	double ans=1+(S-L)/(L-p[L-1]-1),tmp=1;
	bool flag=1;
	for(int i=0;i<L;++i)
	if(a[tar[i]-'A']==0)
	{
			printf("Case #%d: 0.0\n",Case);
			return;
	}else tmp*=(double)a[tar[i]-'A']/K;
	printf("Case #%d: %.7lf\n",Case,ans-tmp*(S-L+1));
}
int main()
{
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	int T;
	scanf("%d",&T);
	for(int i=0;i<T;++i)
		getAns(i+1);
	return 0;
}