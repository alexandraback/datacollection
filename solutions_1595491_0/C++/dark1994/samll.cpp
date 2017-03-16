#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<numeric>
#include<cmath>

#include<fstream>

using namespace std;

int max(int x,int y)
{
	if(x<=y)
		return y;
	return x;
}

int noSurprise(int n,int p)
{
	int i;

	for(i=0;i<=10;++i)
	{
		if(3*i>n)
			return 0;

		if(3*i==n && i>=p)
			return 1;
		if(3*i+1==n && i+1>=p)
			return 1;
		if(3*i+2==n && i+1>=p)
			return 1;
	}

	return 0;
}

int Surprise(int n,int p)
{
	int i;

	for(i=0;i<=10;++i)
	{
		if(3*i+2>n)
			return 0;

		if(3*i+2==n && i+2>=p)
			return 1;
		if(3*i+3==n && i+2>=p)
			return 1;
		if(3*i+4==n && i+2>=p)
			return 1;
	}

	return 0;
}



int B(vector<int> v,int s,int p)
{
	int i,j;
	int n;
	int dp[200][200]={0};

	n=v.size();

	for(i=1;i<=n;++i)
	{
		for(j=0;j<=s;++j)
		{
			int vv=v[i-1];
			if(j==i)
			{
				dp[i][j]=dp[i-1][j-1]+Surprise(v[i-1],p);
			}
			else if(j<i)
			{
				if(j==0)
					dp[i][j]=dp[i-1][j]+noSurprise(v[i-1],p);
				else
					dp[i][j]=max(dp[i-1][j]+noSurprise(v[i-1],p),dp[i-1][j-1]+Surprise(v[i-1],p));
			}
		}
	}

	return dp[n][s];
}


void main()
{
	int i,j,num;
	int n,s,p,t,ret;
	vector<int> v;
	ifstream fin("C:\\Documents and Settings\\Administrator\\×ÀÃæ\\gcj\\B\\B-small-attempt0.in");
	ofstream fout("C:\\Documents and Settings\\Administrator\\×ÀÃæ\\gcj\\B\\B-small.txt");
	
	fin>>num;

	for(i=1;i<=num;++i)
	{
		fin>>n>>s>>p;
		v.clear();
		
		for(j=1;j<=n;++j)
		{
			fin>>t;
			v.push_back(t);
		}

		ret=B(v,s,p);

		fout<<"Case #"<<i<<": ";
		fout<<ret<<endl;
	}

/*	vector<int> v;
	v.push_back(8);
	v.push_back(0);
	v.push_back(21);
	v.push_back(18);
	v.push_back(18);
	v.push_back(21);

	int ret=B(v,1,1);
	cout<<ret<<endl;*/

}
