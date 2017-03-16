#include <iostream>
using namespace std;

#define MAX 1000

bool relation[MAX][MAX];
bool workable[MAX][MAX];

int main()
{
	int T;
	cin >> T;
	for(int t=1;t<=T;t++)
	{
		printf("Case #%d: ", t);
		int N;
		memset(relation,0,sizeof(relation));
		cin >> N;
		for(int i=0;i<N;i++)
		{
			int n;
			cin >> n;
			for(int j=0;j<n;j++)
			{
				int p;
				cin >> p;
				relation[i][p-1] = true;
			}
		}
		bool found = false;
		memcpy(workable,relation,sizeof(workable));
		for(int i=0;i<N;i++)
			workable[i][i] = true;
		for(int i=0;i<N;i++)
			for(int j=0;j<N;j++)
			{
				if(i==j) continue;
				for(int k=0;k<N;k++)
				{
					if(j==k||i==k) continue;
					if(workable[j][i]&&workable[i][k])
						workable[j][k] = true;
				}
			}
		for(int i=0;i<N;i++)
		{
			for(int j=0;j<N;j++)
			{
				if(i==j) continue;
				if(!workable[i][j]) continue;
				for(int k=0;k<N;k++)
				{
					if(!relation[i][k]) continue;
					if(!workable[k][j]) continue;
					for(int l=k+1;l<N;l++)
					{
						if(!relation[i][l]) continue;
						if(workable[l][j])
						{
							found = true;
							goto end;
						}
					}
				}
			}
		}
		end:;
		if(found) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
}
