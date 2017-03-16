#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <list>
#include <set>


using namespace std;

int maxpath[51];

void calcmax()
{
	maxpath[0] = 0;
	maxpath[1] = 0;
	maxpath[2] = 1; 
	for(int i=3;i<51;i++)
	{
		maxpath[i]=maxpath[i-1]+i-2;
		//cout << i << " " << maxpath[i] << endl;
	}
}

int main()
{
	int tt;
	calcmax();
	cin >> tt;
	for(int t = 0;t<tt;t++)
	{
		long long B,M;
		cin >> B >> M;
		//cout << B << M;
		if(maxpath[B]<M)
		{
			cout << "Case #" << t+1 << ": IMPOSSIBLE\n";
			continue;
		}
		int fh = -1;
		for(int i=0;i<=B+1;i++)
		{
			//cout << maxpath[i] << " ";
			if(maxpath[i]>M) {fh = i; break;}

		}
		fh--;
		int diff = M - maxpath[fh];
		//cout << "DIFF: "<< diff << endl;
		bool kell = diff;
		cout << "Case #" << t+1 << ": POSSIBLE\n";
		for(int i= 0;i<B;i++)
		{
			for(int j=0;j<B;j++)
			{
				if(i<fh-1 && j>i && j < fh-1)
				{
					cout << 1 << " ";	
				}
				else if(j==B-1 && i<fh-1)
				{
					cout << 1 << " ";
				}
				else if(j==B-2 && diff>0)
				{
					cout << 1 << " ";
					diff--;
				}else if (i==B-2 && j==B-1 && kell)
				{
					cout << 1 << " ";
				}
				else cout << 0 << " ";
			}
			cout << endl;
		}
	}

	return 0;
}