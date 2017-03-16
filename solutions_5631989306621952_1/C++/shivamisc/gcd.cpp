#include<bits/stdc++.h>
using namespace std;
char a[10005];
string b;
int main()
{
	freopen("A-large.in","r",stdin);
	freopen("output.txt","w",stdout);
	int t;
	int k=1;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",a);
		int l=strlen(a);
		int i,j;
		b="";
		for(i=0;i<l;i++)
		{
			if(i==0)
			{
				b=b+a[i];
			}
			else
			{
				if(a[i]>=b[0])
				{
					b=a[i]+b;
				}
				else
				{
					b=b+a[i];
				}
			}
		}
		printf("Case #%d: ",k++);
		cout<<b<<endl;
	}
}
