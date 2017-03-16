#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int main()
{
	int T;
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	cin>>T;
	for(int ind=1;ind<=T;ind++)
	{
		int n;
		bool res=false;
		cin>>n;
		vector<vector<int> > arr;
		arr.clear();
		vector<int> temp(0);
		arr.push_back(temp);
		for(int i=1;i<=n;i++)
		{
			int m;
			cin>>m;
			temp.clear();
			for(int j=0;j<m;j++)
			{
				int x;
				cin>>x;
				temp.push_back(x);
			}
			arr.push_back(temp);
		}
		for(int i=1;i<=n;i++)
		{
			int mas[1002];
			memset(mas,0,sizeof(mas));
			queue<int> q;
			q.push(i);
			while(!q.empty())
			{
				int x=q.front();
				q.pop();
				mas[x]++;
				if(mas[x]>1){res=true;break;}
				for(int j=0;j<arr[x].size();j++)q.push(arr[x][j]);
			}
		}
		if(res)cout<<"Case #"<<ind<<": Yes"<<endl;
		else cout<<"Case #"<<ind<<": No"<<endl;
	}
}