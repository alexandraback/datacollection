#include<bits/stdc++.h>
using namespace std;
std::string to_string(int tt)
{
	std::string st;
	int ct=0;
	int x=tt;
	while(x!=0)
	{
		x=x/10;
		ct++;
	}
	//cout<<tt<<endl;
	for(int i=0;i<ct;i++)
	{
		int jj=ct-i-1;
		jj=pow(10,jj);
		int y=tt/jj;
		tt=tt-y*jj;
		//cout<<y<<" "<<tt<<endl;
	    char yy='0'+y;
		st.push_back(yy);
	}
	return st;
}
class node{
public:
	int val;
	int vis;
	vector<int> con;
};
int main()
{
	int t;
	cin>>t;
	for(int ii=1;ii<=t;ii++)
	{
		int n,m;
		cin>>n>>m;
		vector< node > A(n+1);
		for(int i=1;i<=n;i++)
		{
			int valu;
			cin>>valu;
			A[i].val=valu;
			A[i].vis=0;
		}
		for(int i=0;i<m;i++)
		{
			int f,l;
			cin>>f>>l;
			A[f].con.push_back(l);
			A[l].con.push_back(f);
		}
		vector<int> B;
		int min=10000000;
		int curii=0;
		for(int i=1;i<=n;i++)
		{
			if(A[i].val<min)
			{
				min=A[i].val;
				curii=i;
			}
		}
		A[curii].vis=1;
		B.push_back(A[curii].val);
			int count=1;
			while(count<n)
			{
				int min=10000000;
				int curi=-1;
				for(int j=1;j<=n;j++)
				{
					if(A[j].vis==1)
					{
						for(int pq=0;pq<A[j].con.size();pq++)
						{
							if((A[A[j].con[pq]].vis!=1) && (A[A[j].con[pq]].val<=min))
							{
								curi=A[j].con[pq];
								min=A[A[j].con[pq]].val;
							}
						}
					}
				}
				if(curi!=-1)
				{
					count++;			
				//cout<<count<<endl;
					A[curi].vis=1;
					B.push_back(A[curi].val);
				}
			}
			for(int i=0;i<B.size();i++)
			{
			cout<<"Case #"<<ii<<": "<<B[i];
			}
			cout<<endl;
	}
	return 0;
}
