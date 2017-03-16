#include<fstream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
ifstream cin("C-small-attempt0.in");
int n,m;
int a[9]={1,2,3,5,7,11,13,17,19};
int b[11];

bool Judge(long long p,int k,int m)
{
	int i=0;
	int x,y=0;
		
	while(p)
	{
		x=p%2;
		for(int j=1;j<=i;j++)
			x=x*k%m;
		y=(y+x)%m;
		i++;
		p=p/2;	
	}
	if(y==0)
		return 1;
	return 0;
}

void Print(long long p)
{
	int c[50]={0};
	while(p)
	{
		c[++c[0]]=p%2;
		p=p/2;
	}
	for(int i=c[0];i>=1;i--)
		printf("%d",c[i]);
	for(int i=2;i<=10;i++)
		printf(" %d",b[i]);
	printf("\n");
}

int main()
{
	freopen("3.out","w",stdout);
	cin>>n;
	cin>>n>>m;
	printf("Case #1: \n");
	int ans=0,j,k;
	long long i=pow(2,n-1)+1;
	
	for(;ans<m;i+=2)
	{
		for(j=2;j<=10;j++)
		{
			for(k=1;k<=8;k++)
				if(Judge(i,j,a[k]))
					break;
			if(k>8)
				break;
			
			b[j]=a[k];
		}
		if(j>10)
		{
			ans++;
			Print(i);
		}
	}
	return 0;
}

