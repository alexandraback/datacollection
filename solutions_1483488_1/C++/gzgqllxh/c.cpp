#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
using namespace std;
map<int,bool>dic;
int main()
{
	int tcase,casenum=0,A,B,n,p,ans,temp,rear,i,m;
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	scanf("%d",&tcase);
	while(tcase--)
	{
		scanf("%d%d",&A,&B);
		ans=0;
		for(i=A;i<=B-1;i++)
		{
			//cout<<"yes"<<i<<endl;
			temp=i;
			m=1;
			while(temp)
			{
				temp=i;
				m*=10;
				temp/=m;
			}
			n=10;
			//cout<<m<<endl;
			temp=i;
			dic.clear();
			while(n<m)
			{
				rear=temp%n;
				temp/=n;
				p=rear*(m/n)+temp;
				if(p>i&&p<=B)
				{	
					if(dic[p]==0)
					{
						dic[p]=true;	
						ans++;
					}
				}
				n=n*10;
				temp=i;
			}
		}
		printf("Case #%d: %d\n",++casenum,ans);
	}
	return 0;
}
