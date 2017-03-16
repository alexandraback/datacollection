#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<sstream>
#include<stack>

int n,m;

using namespace std;

string convertInt(int number)
{
	   stringstream ss;	//create a stringstream
	   ss << number;	//add number to the stream
	   return ss.str();	//return a string with the contents of the stream
}

vector<int> v;
int edge[10][10];
string s,ans;
int perm[10];

int check()
{
	s.clear();
	s=s+convertInt(v[perm[0]]);
	int i,j,ind;
	int ced[10][10];
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			ced[i][j]=edge[i][j];
		}
	}
	stack<int> st;
	st.push(perm[0]);
	i=1;
	while(i<n && !st.empty())
	{
		j=st.top();
		if(ced[j][perm[i]])
		{
			s=s+convertInt(v[perm[i]]);
			st.push(perm[i]);
			ced[j][perm[i]]=0;
			ced[perm[i]][j]=0;
			i++;
		}
		else st.pop();
	}
	if(i!=n)	return 0;
/*	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(ced[i][j])	return 0;
		}
	}
	*/
	return 1;
}
int main()
{
	int i,j,t,p,x,y,a,b,mn,ind;
	scanf("%d",&t);
	for(p=1;p<=t;p++)
	{
//		mn=1000000;
		scanf("%d%d",&n,&m);
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				edge[i][j]=0;
			}
			perm[i-1]=i;
		}
		v.clear();
		ans.clear();
		s.clear();
		v.push_back(123);
		for(i=1;i<=n;i++)
		{
			scanf("%d",&j);
			v.push_back(j);
	//		if(j<mn)
	//		{
	//			mn=j;
	//			ind=i;
	//		}
		}
//		sort(v.begin(),v.end());
		for(i=n;i>=1;i--)	ans=ans+convertInt(999999);
		for(i=1;i<=m;i++)
		{
			scanf("%d%d",&x,&y);
			edge[x][y]=1;
			edge[y][x]=1;
		}
		do {
			if(check())
			{
				if(s<ans)	ans=s;
			}
			      } while ( std::next_permutation(perm,perm+n) );
		cout << "Case #" << p << ": " << ans << '\n';
	}
	return 0;
}

