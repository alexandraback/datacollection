#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n;
int a[1000];
struct node
{
	int id;
	vector<node*> parent;
	vector<node*> child;
};

node nd[1000];

vector<node *> root;

void init()
{
	cin>>n;
	int t,s;
	for(int i=1;i<=n;++i)
	{
		nd[i].id=i;
		nd[i].child.clear();
		nd[i].parent.clear();
		cin>>t;
		for(int j=0;j<t;++j)
		{
			cin>>s;
			nd[i].child.push_back(&nd[s]);
			nd[s].parent.push_back((&nd[i]));
		}
	}
}

int cnt[1000];

void solve()
{
	root.clear();
	for(int i=1;i<=n;++i)
	{
		if(nd[i].parent.size()==0)
			root.push_back(&nd[i]);
	}


	bool found=false;
	for(int i=0;i<root.size();++i)
	{

		for(int j=1;j<=n;++j)
			cnt[j]=0;

		node *cur=root[i];
		queue<node*> que;
		que.push(cur);

		while(!que.empty())
		{
			cur=que.front();
			que.pop();
			cnt[cur->id]++;
			for(int i=0;i<cur->child.size();++i)
			{
				que.push(cur->child[i]);
			}
		}

		bool found2=false;
		for(int i=1;i<=n;++i)
		{
			if(cnt[i]>1)
			{
				found2=true;
				break;
			}
		}
		if(found2)
		{
			found=true;
			break;
		}
	}
	if(found)	
		cout<<"Yes"<<endl;
	else
		cout<<"No"<<endl;
}


int main()
{
	int T;
	cin>>T;
	for(int ii=1;ii<=T;++ii)
	{
		cout<<"Case #"<<ii<<": ";
		init();
		solve();
	}
}