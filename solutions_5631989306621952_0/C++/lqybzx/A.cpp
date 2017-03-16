#include<queue>
#include<cstdio>
#include<string>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int a[100001],q[100001];
int main()
{
	freopen("A-small-attempt0.in","r",stdin);
	freopen("A-small-attempt0.out","w",stdout);
	int T;
	int k=0;
	scanf("%d",&T);
	while(T>0)
	{
		T--;
		k++;
		string x;
		cin>>x;
		int lx=x.size();
		int i;
		for(i=1;i<=lx;i++)
			a[i]=x[i-1]-'A';
		int l=lx,r=lx-1;
		r++;
		q[r]=a[1];
		for(i=2;i<=lx;i++)
		{
			if(a[i]>=q[l])
			{
				l--;
				q[l]=a[i];
			}
			else
			{
				r++;
				q[r]=a[i];
			}
		}
		printf("Case #%d: ",k);
		for(i=l;i<=r;i++)
			printf("%c",q[i]+'A');
		printf("\n");
	}
	return 0;
}
