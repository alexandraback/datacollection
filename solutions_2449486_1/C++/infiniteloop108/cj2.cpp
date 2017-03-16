#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct gr
{
	int h,r,c;
};
bool operator < (gr g1,gr g2)
{
	return g1.h<g2.h;
}
int work()
{
	int n,m;
	cin>>n>>m;
	vector< vector<int> > field( n, vector<int>(m,0) );
	vector<gr> grass;
	for(int i=0;i<n;++i)
		for(int j=0;j<m;++j)
		{
			cin>>field[i][j];
			gr temp={field[i][j],i,j};
			grass.push_back(temp);
		}
	vector<bool> rdone(n,0),cdone(m,0);
	sort(grass.begin(),grass.end());
	for(int i=0;i<grass.size();++i)
	{
		int h,r,c;
		h=grass[i].h;
		r=grass[i].r;
		c=grass[i].c;
		if(!rdone[r]&&!cdone[c])
		{
			int t=0;
			for(int j=0;j<m;++j)
				if(field[r][j]>h){t=1;break;}
			if(t==0)rdone[r]=1;
			
			t=0;
			for(int j=0;j<n;++j)
				if(field[j][c]>h){t=1;break;}
			if(t==0)cdone[c]=1;
			
			if(!rdone[r]&&!cdone[c])return 0;
		}
	}
	return 1;
}
int main()
{
	int t;
	cin>>t;
	for(int i=1;i<=t;++i)
	{
		cout<<"Case #"<<i<<": ";
		if(work())cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}