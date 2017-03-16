#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int main()
{
	int T,N,y,M,state;
	cin >> T;
	vector<vector<int> > A;
	vector<int> temp;
	vector<int> count;
	queue<int> q;
	for(int i=0;i<T;i++)
	{
		cin >> N;
		A.clear();
		state=0;
		for(int j=0;j<N;j++)
		{
			cin >> M;
			temp.clear();
			for(int k=0;k<M;k++)
			{
				cin >> y;			
				temp.push_back(y-1);
			}
			A.push_back(temp);
		}
		for(int j=0;j<N;j++)
		{
			while(!q.empty())
				q.pop();
			q.push(j);
			count.clear();
			count.assign(N,0);
			while(!q.empty())
			{
				y=q.front();
				q.pop();
				for(int k=0;k<A[y].size();k++)
				{
					q.push(A[y][k]);
					count[A[y][k]]=count[A[y][k]]+1;
				//	cout << "cnt " << A[y][k] << " " << count[A[y][k]] << endl;
					if(count[A[y][k]] >= 2)
					{
						state=1;
						break;
					}
				}
				if(state == 1)
					break;
			}
			if(state == 1)
				break;
		}
		if(state == 1)
			cout << "Case #" << i+1 <<": " << "Yes" << endl;
		else
			cout << "Case #" << i+1 <<": " << "No" << endl;
	}
}
