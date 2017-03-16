#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
//	freopen("K:/input.txt", "rt", stdin);

	int T;

	cin>>T;

	for(int t=1; t<=T; ++t)
	{
		int N, M, x;

		vector<char> root;
		vector<vector<int> > a;
		
		cin>>N;

		a.resize(N);
		root.resize(N);
	
		for(int i=0; i<N; ++i)
		{
			cin>>M;
			
			for(int j=0; j<M; ++j)
			{
				cin>>x;
				--x;
				a[i].push_back(x);
				root[x] = 1;
			}
		}

		bool fin = false;

		for(int i=0; i<N; ++i)
		{
			if(!root[i])
			{
				vector<char> used;
				used.resize(N);

				queue<int> q;
				q.push(i); used[i] = 1;

				while(!q.empty())
				{
					int cur = q.front();
					q.pop();

					vector<int> &cv = a[cur];

					for(int j=0; j<cv.size(); ++j)
					{
						if(used[cv[j]])
						{
							cout<<"Case #"<<t<<": Yes"<<endl;
							fin = true;
							break;
						}
						else
						{
							q.push(cv[j]);
							used[cv[j]] = 1;
						}
					}

					if(fin)break;
				}
			}
			if(fin)break;
		}

		if(!fin)
			cout<<"Case #"<<t<<": No"<<endl;
	}

	return 0;
}