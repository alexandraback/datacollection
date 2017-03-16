#include <iostream>
using namespace std;
int m,s,p;
int a[1000];
int main()
{
	freopen("C:\\1.txt","w",stdout);
	freopen("1.in","r",stdin);
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>m>>s>>p;
		for(int j=0;j<m;j++)
			cin>>a[j];
		int res=0;
		for(int j=0;j<m;j++)
		{
			if(a[j]>=p*3)res++;
			else if(a[j]>=p*3-2&&a[j]>0)res++;
			else if(a[j]>=p*3-4&&a[j]>1&&s>0){s--;res++;}
		}
		printf("Case #%d: %d\n",i+1,res);
	}
}