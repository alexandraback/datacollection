#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int main()
{
	int notime;
	cin>>notime;
	for(int caseno=1;caseno<=notime;caseno++)
	{
	int n;
	cin>>n;
	vector<vector<int> > adjlist;
	adjlist.resize(n+1);
	for(int i=1;i<=n;i++)
	{
		int no;
		cin>>no;
		while(no--)
		{
			int temp;
			cin>>temp;
			adjlist[i].push_back(temp);
		}
	}
	bool breaker=false;
	for (int todo=1;todo<=n;todo++)
	{

		vector<bool> visited;
		visited.resize(n+1,false);
		queue<int> queuer;
		queuer.push(todo);
//		cout<<"START AT "<<todo<<endl;
		visited[todo]=true;
		while(!queuer.empty())
		{
			int head=queuer.front();
			queuer.pop();
//			cout<<"OBTAINED "<<head<<" as the head of queue"<<endl;
			for(int i=0;i<adjlist[head].size();i++)
			{
				int nextvert=adjlist[head][i];
//				cout<<"     IT has adj vertex"<<nextvert<<endl;
				if(visited[nextvert]==true)
				{
//					cout<<"Visited is true "<<endl;
					breaker=true;
					break;
				}
				queuer.push(nextvert);
				visited[nextvert]=true;
			}
			
			if(breaker==true)
				break;

		}
		if(breaker==true)
			break;
	}
	if(breaker==true)
		cout<<"Case #"<<caseno<<": "<<"Yes"<<endl;
	else
		cout<<"Case #"<<caseno<<": "<<"No"<<endl;
	}
}
