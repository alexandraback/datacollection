#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("C-small-attempt2.in","r",stdin);
	freopen("q2.out","w",stdout);
	int t;
	cin>>t;
	int kk=0;
	while(t--)
	{
		kk++;
		int j,p,s,k;
		cin>>j>>p>>s>>k;
		int fr=1,se=1,th=1;
		cout<<"Case #"<<kk<<": ";
		int num=0;
		int a1[j][p];
		int a2[p][s];
		int a3[j][s];
		for(int i=0;i<j;i++)
		{
			for(int l=0;l<p;l++)
			{
				a1[i][l]=0;
			}
		}
		for(int i=0;i<p;i++)
		{
			for(int l=0;l<s;l++)
			{
				a2[i][l]=0;
			}
		}
		for(int i=0;i<j;i++)
		{
			for(int l=0;l<s;l++)
			{
				a3[i][l]=0;
			}
		}
			for(int i=1;i<=j;i++)
			{
				for(int q=1;q<=p;q++)
				{
					for(int w=1;w<=s;w++)
					{
						if(a1[i][w]>k)
						{
							continue;
						}
						if(a2[q][w]>k)
						{
							continue;
						}
						if(a3[i][w]>k)
						{
							continue;
						}
						a1[i][w]++;
						a2[q][w]++;
						a3[i][w]++;
						num++;
					}
				}
			}
			cout<<num<<endl;
			for(int i=0;i<j;i++)
		{
			for(int l=0;l<p;l++)
			{
				a1[i][l]=0;
			}
		}
		for(int i=0;i<p;i++)
		{
			for(int l=0;l<s;l++)
			{
				a2[i][l]=0;
			}
		}
		for(int i=0;i<j;i++)
		{
			for(int l=0;l<s;l++)
			{
				a3[i][l]=0;
			}
		}
		for(int i=1;i<=j;i++)
			{
				for(int q=1;q<=p;q++)
				{
					for(int w=1;w<=s;w++)
					{
						if(a1[i][w]>k)
						{
							continue;
						}
						if(a2[q][w]>k)
						{
							continue;
						}
						if(a3[i][w]>k)
						{
							continue;
						}
						a1[i][w]++;
						a2[q][w]++;
						a3[i][w]++;
						cout<<i<<" "<<q<<" "<<w<<endl;
					}
				}
			}
	}
	return 0;
}
