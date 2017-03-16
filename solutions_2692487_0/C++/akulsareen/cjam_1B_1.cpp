#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<string>
#include<fstream>
using namespace std;
int process(int a,int sp,vector <int> A,int changes)
{
	for(int i=sp;i<A.size();i++)
	{
		if(a>A[i])
		a+=A[i];
		else
		{
			if((A[i]+1-a)<a)
			{
				changes++;
				a*=2;
				a--;
				a+=A[i];
			}
			else
			{
				int x=0,y=A.size();
				if(a==1)
				return changes+y-i;
				while(a<=A[i])
				{
					a*=2;
					a--;
					x++;
				}
				a+=A[i];
				changes=min(changes+y-i,process(a,i+1,A,changes+x));
				return changes;
			}
		}
	}
	return changes;
}			
int main()
{
	ifstream fin("A.in");
	ofstream fout("A.out");
	int t;
	vector <int> ans;
	fin>>t;
	while(t--)
	{
		int a,n,x;
		vector <int> A;
		fin>>a>>n;
		for(int i=0;i<n;i++)
		{
			fin>>x;
			A.push_back(x);
		}
		sort(A.begin(),A.end());
		x=process(a,0,A,0);
		ans.push_back(x);
	}
	for(int i=0;i<ans.size();i++)
	fout<<"Case #"<<i+1<<": "<<ans[i]<<"\n";
	return 0;
}
