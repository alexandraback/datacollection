#include<iostream>
#include<map>
#include<vector>
using namespace std;
int test()
{
	int n;
	cin >> n;
	map<string,int>A,B;
	vector<pair<int,int>>V;
	for(int i=0;i<n;i++)
	{
		string a,b;
		cin >> a>>b;
		if(A.count(a)==0)A[a]=A.size()-1;
		if(B.count(b)==0)B[b]=B.size()-1;
		V.push_back({A[a],B[b]});
	}
	int ans=0;
	int m1=(1<<A.size())-1,m2=(1<<B.size())-1;
	int L=1<<n;
	for(int i=0;i<L;i++)
	{
		int a=0,b=0,bits=0;
		for(int j=0;j<n;j++)
			if((1<<j)&i)
			{
				a|=1<<V[j].first;
				b|=1<<V[j].second;
				bits++;
			}
		if(a==m1 and b==m2)
		{
				if(n-bits>ans)ans=n-bits;
		}
	}

	return ans;
}
int main()
{
	int t;
	cin >>t;
	for(int i=1;i<=t;i++)
	{
		int a=test();
		cout << "Case #"<<i<<": "<< a<<"\n";
	}
}
