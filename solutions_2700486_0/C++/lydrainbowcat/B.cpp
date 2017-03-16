#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int v[200][200],T,t,n,x,y,tot,ans,i,j,k,p,q,num,top;

bool vis(int x,int y)
{
	return v[x+100][y+100]==num;
}
void fill(int x,int y)
{
	v[x+100][y+100]=num;
	if(!x) top+=2; 
}

int main()
{
	freopen("B-small-attempt0.in","r",stdin);
	freopen("B-small-attempt0.out","w",stdout);
	cin>>T;
	for(t=1;t<=T;t++)
	{
		scanf("%d%d%d",&n,&x,&y);
		if(abs(x)<50&&abs(y)<50)
		{
			n--,ans=tot=0;
			for(i=0;i<1<<n;i++)
			{
				num++,top=0;
				fill(0,0);
				for(j=0;j<n;j++)
				{
					k=i>>j&1;
					if(k)
					{
						for(p=0,q=top;q>0&&!vis(p-1,q-1);p--,q--);
						if(!p&&!vis(1,top-1)) break;
						fill(p,q);
					}
					else{
						for(p=0,q=top;q>0&&!vis(p+1,q-1);p++,q--);
						if(!p&&!vis(-1,top-1)) break;
						fill(p,q);
					}
				}
				if(j==n&&vis(x,y)) ans++;
				if(j==n) tot++;
			}
		}
		else ans=0,tot=1;
		printf("Case #%d: %.10f\n",t,ans*1.0/tot);
	}
}
