#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int check1(int num, int m)
{
	while(num!=0)
	{
		int rem=num%10;
		if(rem<2||rem>m)
			return 1;
		num=num/10;
	}
	return 0;
}
int check[7];
int solve(int num, int A[], int k)
{
	int i=0,j;
	while(num!=0)
	{
		int rem=num%10;
		num=num/10;
		check[i]=rem;
		i++;
	}
	check[3]=check[0]*check[1];
	check[4]=check[1]*check[2];
	check[5]=check[0]*check[2];
	check[6]=check[0]*check[1]*check[2];
	for(i=0;i<k;i++)
	{
		if(A[i]==1)
		{
			A[i]=0;
			continue;
		}
		for(j=0;j<7;j++)
		{
			if(A[i]==check[j])
			{
				A[i]=0;
			}
		}
	}
	int sum=0;
	for(i=0;i<k;i++)
		sum+=A[i];
	if(sum==0)
		return 1;
	return 0;
}
int main()
{
	int t,u;
	cin>>t;
	u=t;
	while(t--)
	{
		int r,n,m,k;
		cin>>r>>n>>m>>k;
		cout<<"Case #"<<u-t<<":\n";
		while(r--)
		{
			int i,A[k];
			for(i=0;i<k;i++)
				cin>>A[i];
			int num=99;
			while(1)
			{
				num++;
				if(num==999)
				{
					num=222;
					break;
				}
				if(check1(num,m))
					continue;
				int solved=solve(num,A,k);
				if(solved)
					break;
			}
			cout<<num<<endl;
		}
	}
	return 0;
}