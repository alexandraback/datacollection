/*
name:Rollchuchy
type:
*/
#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int INF=1e9;
const int maxn=20;
int n,m,t;
int len;
string GG,GGG;
ll a[maxn],b[maxn];
int minabs;
ll ansa[maxn],ansb[maxn];
void check();
void DFS(int deep);
int main()
{
	freopen("B-small-attempt2.in","r",stdin);
	freopen("out.txt","w",stdout);
	scanf("%d",&t);
	for (int G = 1; G<=t; G += 1)
	{
		printf("Case #%d: ",G);
		cin>>GG>>GGG;
		len=GG.length();
		for (int i = 0; i < len; i += 1)
		{
			if(GG[i]=='?')a[i]=-1;
			else a[i]=GG[i]-'0';
			if(GGG[i]=='?')b[i]=-1;
			else b[i]=GGG[i]-'0';
		}
		minabs=INF;
		memset(ansa,-1,sizeof(ansa));
		memset(ansb,-1,sizeof(ansb));
		DFS(0);
		for (int i = 0; i < len; i += 1)
		{
			printf("%d",(int)ansa[i]);
		}
		printf(" ");
		for (int i = 0; i < len; i += 1)
		{
			printf("%d",(int)ansb[i]);
		}
		printf("\n");
	}
	return 0;
}
void check(){
	ll anum=0,bnum=0;
	ll pows=1;
	for (int i = len-1; i >=0; i += -1)
	{
		anum+=a[i]*pows;
		bnum+=b[i]*pows;
		pows*=10;
	}
	if(abs(anum-bnum)<minabs){
		minabs=abs(anum-bnum);
		for (int i = 0; i < len; i += 1)
		{
			ansa[i]=a[i];
			ansb[i]=b[i];
		}
	}
}
void DFS(int deep){
	if(deep==len){
		check();
		return;
	}
	if(a[deep]!=-1&&b[deep]!=-1){
		DFS(deep+1);
	}
	else if (a[deep]==-1&&b[deep]!=-1)
	{
		for (int i = 0; i < 10; i += 1)
		{
			a[deep]=i;
			DFS(deep+1);
		}
		a[deep]=-1;
	}
	else if (a[deep]!=-1&&b[deep]==-1)
	{
		for (int i = 0; i < 10; i += 1)
		{
			b[deep]=i;
			DFS(deep+1);
		}
		b[deep]=-1;
	}
	else{
		for (int i = 0; i < 10; i += 1)
		{
			a[deep]=i;
			for (int j = 0; j < 10; j += 1)
			{
				
				b[deep]=j;
				DFS(deep+1);
			}
		}
		a[deep]=-1;
		b[deep]=-1;
	}
	
}
