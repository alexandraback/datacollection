#include <iostream>
#include <stdio.h>
#include <utility>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <math.h>
#include <cstdio>
 
#define FOR(i,x,y) for(int i=(x);i<(y);i++)
#define RFOR(i,x,y) for(int i=(x);i>=(y);i--)
#define ABS(x) ((x)>0?(x):-(x))
#define SQ(x) ((x)*(x))
#define mset(x,y) memset(x,y,sizeof(x))
#define INF 1000000000
#define MOD 1000000007
#define pb(X) push_back(X) 

using namespace std;

typedef long long int lli;
typedef long double ld;
typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<double> vd;


int main()
{
	// #ifndef ONLINE_JUDGE
    freopen("C-large.in","r",stdin);
    freopen("out.txt","w",stdout);
    // #endif
    int t;
    char arr[60][60];
    scanf("%d",&t);
    for(int tt=1;tt<=t;tt++)
    {
    	int r,c,m;
    	scanf("%d%d%d",&r,&c,&m);
    	bool ans=false;

    	for(int i=0;i<60;i++)
    		for(int j=0;j<60;j++)
    			arr[i][j]='.';

    	if(r*c-m==1)
    	{
    		ans=true;
    		for(int i=0;i<r;i++)
    			for(int j=0;j<c;j++)
    			{
    				arr[i][j]='*';
    			}
    		arr[0][0]='c';
    	}

    	else if(r==1)
    	{
    		if(m<c)
    		{
    			ans=true;
	    		arr[0][0]='c';
	    		for(int i=c-1;i>=c-m;i--) arr[0][i]='*';
	    	}
    	}

    	else if(c==1)
    	{
    		if(m<r)
    		{
	    		ans=true;
	    		arr[0][0]='c';
	    		for(int i=r-1;i>=r-m;i--) arr[i][0]='*';
	    	}
    	}

    	else if(r==2)
    	{
    		if(m%2==0&&r*c-m>=4)
    		{
    			ans=true;
	    		arr[0][0]='c';
	    		for(int i=c-1;i>=c-m/2;i--) arr[0][i]=arr[1][i]='*';
	    	}
    	}

    	else if(c==2)
    	{
    		if(m%2==0&&r*c-m>=4)
    		{
    			ans=true;
	    		arr[0][0]='c';
	    		for(int i=r-1;i>=r-m/2;i--) arr[i][0]=arr[i][1]='*';
	    	}
    	}

    	else if(r*c-m==1||r*c-m==4||r*c-m==6||r*c-m==8)
    	{
    		ans=true;
    		for(int i=0;i<r;i++)
    			for(int j=0;j<c;j++) arr[i][j]='*';

    		arr[0][0]='c';

    		if(r*c-m==1)
    		{}

    		if(r*c-m==4)
    		{
    			arr[0][1]=arr[1][0]=arr[1][1]='.';
    		}

    		if(r*c-m==6)
    		{
    			arr[0][1]=arr[1][0]=arr[1][1]=arr[0][2]=arr[1][2]='.';
    		}

    		if(r*c-m==8)
    		{
    			arr[0][1]=arr[1][0]=arr[1][1]=arr[0][2]=arr[1][2]=arr[2][0]=arr[2][1]='.';
    		}

    	}
    	else if(r*c-8>=m)
    	{

    		//cerr<<tt<<" hi"<<endl;
    		ans=true;
    		int cnt=m;
    		arr[0][0]='c';
    		for(int i=r-1;i>1&&cnt;i--)
    			for(int j=c-1;j>1&&cnt;j--)
				{
					arr[i][j]='*';
					cnt--;
				}

			//cerr<<cnt<<endl;
			int i,j;
			for(i=r-1;i>2&&cnt>=2;i--)
			{
				arr[i][0]=arr[i][1]='*';
				cnt-=2;
			}
			for(j=c-1;j>2&&cnt>=2;j--)
			{
				arr[0][j]=arr[1][j]='*';
				cnt-=2;
			}
			if(cnt==1)
			{
				if(i>2)
				{
					arr[2][2]='.';
					arr[i][1]=arr[i][0]='*';
				}
				else if(j>2)
				{
					arr[2][2]='.';
					arr[1][j]=arr[0][j]='*';
				}
				else cerr<<"Wrong";
			}
    	}

    	printf("Case #%d:\n",tt);
    	if(ans)
    	{
    		for(int i=0;i<r;i++)
    		{
    			for(int j=0;j<c;j++)
    				printf("%c",arr[i][j]);
    			printf("\n");
    		}
    	}
    	else printf("Impossible\n");
    }
    return 0;
    
}