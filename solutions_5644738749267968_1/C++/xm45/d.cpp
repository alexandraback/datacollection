#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<algorithm>
#include<deque>
#include<functional>
#include<iterator>
#include<vector>
#include<list>
#include<map>
#include<memory>
#include<numeric>
#include<queue>
#include<set>
#include<stack>
#include<utility>
#define abs(a) ((a>0)?(a):-(a))
#define sgm(a) (a==0?(0):((a>0)?(1):(-1)))
#define sqr(a) ((a)*(a))
#define swap(a,b,lx) {lx t;t=a;a=b;b=t;}
#define oo 0xfffffff
using namespace std;
int N,M,K,T;
inline int rd(int a)
{
		long long b=((long long)rand()+1)*((long long)rand()+1)*((long long)rand()+1)%100000007*(rand()+1)%a+1; 
		return(b);
}
void read(int &a)
{
	char c[10]={0};
	scanf("%s",c);
	int l=strlen(c);
	for(int i=2;i<l;i++)
		c[i]-='0';
	a=c[2]*10000+c[3]*1000+c[4]*100+c[5]*10+c[6];
}
int n[1001],k[1001];
int nt,nh,kt,kh;//tail head
int nc,kc;//chosen
void work()
{
	scanf("%d",&N);
	for(int i=1;i<=N;i++)
		read(n[i]);
	for(int i=1;i<=N;i++)
		read(k[i]);
	sort(n+1,n+N+1);
	sort(k+1,k+N+1);
	int ans=0,ans_d=0;
	
	/*printf("\n");
	for(int i=1;i<=N;i++)
		printf("%d ",n[i]);
	printf("\n");
	for(int i=1;i<=N;i++)
		printf("%d ",k[i]);
	printf("\n");
	/**/
	nt=kt=1;
	nh=kh=N;
	for(int i=1;i<=N;i++)//win if N can.
	{ 
		nc=n[nh--];
		if(k[kh]>nc)
			kc=k[kh--];
		else
			kc=k[kt++];
		ans+=nc>kc;
	}
	nt=kt=1;
	nh=kh=N;
	for(int i=1;i<=N;i++)
	{
		if(n[nt]>k[kt])
		{
			nc=n[nt++];
			kc=k[kt++];//N:the smallest,say:above than K's largest,and K:the smallest.
		}
		else
		{
			nc=n[nt++];
			kc=k[kh--];//N:the smallest,say:only below than K's largest,and K:the smallest.
		}
		ans_d+=nc>kc;
	}
	printf("%d %d",ans_d,ans);
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int i,j,k,l;
	scanf("%d",&T);
	for(i=1;i<=T;i++)
	{
		if(i==4)
			i=4;
		printf("Case #%d: ",i);
		work();
		printf("\n");
	}
    return(0);
}
