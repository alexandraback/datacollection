
#include <iostream>
#include <vector>

using namespace std;
vector < vector <long long> > box;
vector < vector <long long> > toy;


long long maxMatch(int x,int y)
{
	if(x==box.size()|| y==toy.size())
		return 0;
	if(box[x][1] == toy[y][1])
	{
		long long min = box[x][0];
		if(min > toy[y][0])
		{
			min = toy[y][0];
			box[x][0] -= min;
			long long max = maxMatch(x,y+1)+min;
			box[x][0]+=min;
			return max;
		}
		else
		{
			toy[y][0]-=min;
			long long max = maxMatch(x+1,y)+min;
			toy[y][0]+=min;
			return max;
		}
	}
	long long max1 = maxMatch(x,y+1);
	long long max2 = maxMatch(x+1,y);
	if(max1>max2)
		return max1;
	return max2;
}

int main()
{
	int c;
	int i,j;
	int m,n;
	long long x,y;
	cin>>c;
	for(i=1;i<=c;i++)
	{
		cin>>n>>m;
		box.clear();
		toy.clear();
		for(j=0;j<n;j++)
		{
			vector <long long> bb;
			cin>>x>>y;
			bb.push_back(x);
			bb.push_back(y);
			box.push_back(bb);
		}
		for(j=0;j<m;j++)
		{
			vector <long long> bb;
			cin>>x>>y;
			bb.push_back(x);
			bb.push_back(y);
			toy.push_back(bb);
		}

		cout<<"Case #"<<i<<": "<<maxMatch(0,0)<<endl;
	}
	return 1;
}