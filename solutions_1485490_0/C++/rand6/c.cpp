#include<stdio.h>
#include<vector>
using namespace std;
void print(vector<vector<long long int> >a)
{
	for(int i=0;i<a.size();i++)
	{

		for(int j=0;j<a[i].size();j++)
		{
			printf("%Ld ",a[i][j]);
		}
		printf("\n");
	}
}
long long int func(vector<vector<long long int> >a,vector<vector<long long int> >b,int pa,int pb)
{
	long long int c=0;
	/*printf("\n---%d %d\n",pa,pb);
	print(a);
	print(b);
		printf("\n---\n");
	*/
	if(pa>=a.size())return 0;
	if(pb>=b.size())return 0;
	if(a[pa][0]==b[pb][0])
	{
		if(a[pa][1]>b[pb][1])
		{
			c=c+b[pb][1];
			a[pa][1]-=b[pb][1];
			b[pb][1]=0;
			pb++;
			return c+func(a,b,pa,pb);
		}
		else if(a[pa][1]<b[pb][1])
		{
			c=c+a[pa][1];
			b[pb][1]-=a[pa][1];
			a[pa][1]=0;
			pa++;
			return c+func(a,b,pa,pb);
		}
		
		{
			c=c+a[pa][1];
			a[pa][1]=0;
			b[pb][1]=0;
			pa++;
			pb++;
			return c+func(a,b,pa,pb);
		}
	}
	else
	{
		long long int val1=func(a,b,pa+1,pb);
		long long int val2=func(a,b,pa,pb+1);
		return (val1>val2)?val1:val2;
	}
	
}

int main()
{
	int t;
	scanf("%d",&t);
	for(int itr=1;itr<=t;itr++)
	{
		int N,M;
		scanf("%d %d",&N,&M);
		vector<vector<long long int> >a,b;
		vector<long long int>temp(2);
		a.resize(N,temp);
		b.resize(M,temp);		
		for(int i=0;i<N;i++)
		{
			scanf("%Ld %Ld",&a[i][1],&a[i][0]);			
		}

		for(int i=0;i<M;i++)
		{
			scanf("%Ld %Ld",&b[i][1],&b[i][0]);			
		}
		//print(a);
		//print(b);
		printf("Case #%d: %Ld\n",itr,func(a,b,0,0));
	}
	return  0;
}
