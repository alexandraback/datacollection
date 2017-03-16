#include<bits/stdc++.h>
#include<deque>
using namespace std;
#define fs first
#define sc second
#define p 1000000007
#define pb push_back
#define mp make_pair
typedef long long Int;
typedef pair<Int,Int> pii;
typedef vector<Int> vi;
typedef vector<pii> vii;
int main()
{
	Int T,N,A[2501],data;
	cin>>T;
	for(Int k=1;k<=T;k++)
	{
		vector<Int> v;
		cout<<"Case #"<<k<<": ";
		cin>>N;
		for(Int i=1;i<=2500;i++)
			A[i]=0;
		for(int i=1;i<=2*N-1;i++)
		{
			for(int j=1;j<=N;j++)
			{
				cin>>data;
				A[data]++;
			}
		}
		for(int i=1;i<=2500;i++)
		{
			if(A[i]%2!=0)
				v.pb(i);
		}
		sort(v.begin(),v.end());
		for(int i=0;i<v.size();i++)
		{
			if(i==v.size()-1)
			cout<<v[i]<<endl;
			else
				cout<<v[i]<<" ";
		}


	}


	return 0;
}