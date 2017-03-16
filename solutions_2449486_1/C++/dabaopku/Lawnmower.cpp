#include <iostream>
#include <queue>

using namespace std;

struct node
{
	int height;
	int x,y;
	bool operator <(const node & o) const
	{
		return o.height<height ||
			o.height==height && o.x<x ||
			o.height==height && o.x==x && o.y<y;
	}
	node(int x_=0,int y_=0):
		x(x_),y(y_)
	{}
};


int caseNumber;

int row,col;
node board[110][110];
priority_queue<node> que;

void input()
{
	que=priority_queue<node>();
	cin>>row>>col;
	for(int i=0;i<row;++i)
	{
		for(int j=0;j<col;++j)
		{
			board[i][j]=node(i,j);
			cin>>board[i][j].height;
			que.push(board[i][j]);
		}
	}
}
void solve()
{
	while(!que.empty())
	{
		node nd=que.top();
		que.pop();
		int result=0;
		for(int i=0;i<col;++i)
		{
			if(board[nd.x][i].height>nd.height)
			{
				result|=1;
				break;
			}
		}
		for(int i=0;i<row;++i)
		{
			if(board[i][nd.y].height>nd.height)
			{
				result|=2;
				break;
			}
		}
		if(result==3)
		{
			cout<<"NO"<<endl;
			return;
		}
	}
	cout<<"YES"<<endl;
}
int main()
{
	cin>>caseNumber;
	for(int caseId=1;caseId<=caseNumber;++caseId)
	{
		cout<<"Case #"<<caseId<<": ";
		input();
		solve();
	}
	return 0;
}