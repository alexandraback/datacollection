#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int num[110],cnt[110];
char A[110],B[110];
int lenA,lenB,ans;
int res[50]={3,2,5,3,8,5,13,9,22,16,37,27,60,43,93,65,138,94,197,131,272,177,365,233,478,300,
613,379,772,471,957,577,1170,698,1413,835,1688,989,1997,1161,2342,1352,2725,1563
,3148,1795,3613,2049,4122,2326};
int pre[50];

int stot;
int s[41555][100];
int Len[41555];

void update(int l,int r,int v)
{
	for(int i=l;i<=r;i++)
	{
		if(i==l || i==r) num[i]=v;
		else num[i]=0;
	}
}

bool check(int len)
{
	int i,j;
	for(i=0;i<2*len;i++)
	cnt[i]=0;
	for(i=0;i<len;i++)
	for(j=0;j<len;j++)
	cnt[i+j]+=num[i]*num[j];
	for(i=0;i<2*len-1;i++)
	{
		if(cnt[i]>=10) return false;
		s[stot][i]=cnt[i];
	}
	Len[stot]=2*len-1;
	stot++;
	return true;
}

void doit(int inx,int len)
{
	if(check(len))
	{
		num[len/2]++;
		if(len%2==0) num[len/2-1]++;
		doit(len/2,len);
	}
	else
	{
		if(inx-1>=0)
		{
			update(inx-1,len-1-inx+1,num[inx-1]+1);
			doit(inx-1,len);
		}
	}
}

void init()
{
	for(int i=1;i<=50;i++)
	{
		memset(num,0,sizeof(num));
		num[0]=num[i-1]=1;
		doit(i/2,i);
	}
	for(int i=0;i<50;i++)
	{
		pre[i]=res[i];
		if(i-1>=0) pre[i]+=pre[i-1];
	}
}

int dblcmp(int x,char y[],int len)
{
	if(Len[x]<len) return -1;
	if(Len[x]>len) return 1;
	for(int i=0;i<len;i++)
	{
		if(s[x][i]>y[i]-'0') return 1;
		if(s[x][i]<y[i]-'0') return -1;
	}
	return 0;
}

int find_A()
{
	int first,last=pre[min(49,(lenA-1)/2+1)]-1;
	if(lenA==1) first=0;
	else first=pre[lenA/2-1]-1;
//	cout<<first<<' '<<last<<endl;
	int inx=stot;
	while(first<=last)
	{
		int mid=(first+last)>>1;
		if(dblcmp(mid,A,lenA)>=0)
		{
			inx=mid;
			last=mid-1;
		}
		else first=mid+1;
	}
	return inx;
}

int find_B()
{
	int first,last=pre[min(49,(lenB+1)/2)]-1;
	if(lenB==1) first=0;
	else first=pre[lenB/2-1]-1;
//	cout<<first<<' '<<last<<endl;
	int inx=-1;
	while(first<=last)
	{
		int mid=(first+last)>>1;
		if(dblcmp(mid,B,lenB)<=0)
		{
			inx=mid;
			first=mid+1;
		}
		else last=mid-1;
	}
	return inx;
}


int main()
{
	freopen("C-large-1.in","r",stdin);
	freopen("C-large-1.out","w",stdout);
	init();
	int t,cas;
	scanf("%d",&t);
	for(cas=1;cas<=t;cas++)
	{
		scanf("%s %s",A,B);
		lenA=strlen(A);
		lenB=strlen(B);
		int l=find_A();
		int r=find_B();
//		cout<<"l = "<<l<<' '<<r<<endl;
		ans=r-l+1;
		printf("Case #%d: %d\n",cas,ans);
	}
	return 0;
}
