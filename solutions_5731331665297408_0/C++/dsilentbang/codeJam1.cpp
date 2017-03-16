#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#define MAXN 8
using namespace std;
vector<string> arr;
string stringValue(vector<int> &myints)
{
	string temp="";
	for(int i=0;i<myints.size();i++)
	{
		temp+=arr[myints[i]];
	}
	return temp;
}
bool graph[MAXN][MAXN];
bool checkPossible(vector<int> &myints)
{
	stack<int> mystack;
	mystack.push(myints[0]);
	for(int i=1;i<myints.size();i++)
	{
		while(mystack.size()>0&& graph[mystack.top()][myints[i]]!=true)
		{
			mystack.pop();
		}
		if(mystack.size()==0)
			return false;
		else
		{
			mystack.push(myints[i]);
		}
	}
	return true;
}
int main()
{
	freopen("input.txt", "r", stdin);
  	freopen("output.txt", "w", stdout);
	int t;
	scanf("%d",&t);
	for(int testCase=1;testCase<=t;testCase++)
		{
			int n,m;
			cin>>n>>m;
			for(int i=0;i<n;i++)
			{
				for(int j=0;j<n;j++)
				{
					graph[i][j]=false;
				}
			}
			vector<int> myints;
			for(int i=0;i<n;i++)
			{
				myints.push_back(i);
			}
			string temp;
			arr.clear();
			for(int i=0;i<n;i++)
			{
				cin>>temp;
				arr.push_back(temp);
			}
			int x,y;
			for(int i=0;i<m;i++)
			{
				cin>>x>>y;
				x--;y--;
				graph[x][y]=true;
				graph[y][x]=true;
			}
			string mini="";
			do{
				if(checkPossible(myints))
				{
					string val=stringValue(myints);
					if(mini=="")
						mini=val;
					else if(val<mini)
						mini=val;
				}
			}while(next_permutation(myints.begin(),myints.end()));
			printf("Case #%d: ",testCase);
			cout<<mini<<endl;
		}
		return 0;
}