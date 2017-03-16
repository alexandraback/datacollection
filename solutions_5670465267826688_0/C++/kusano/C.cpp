#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	int T;
	cin>>T;

	for (int t=1; t<=T; t++)
	{
		int L, X;
		cin>>L>>X;
		string s;
		cin>>s;

		//	1, i, j, k, -1, -i, -j, -k
		int Q[8][4] = {
			{0, 1, 2, 3},
			{1, 4, 3, 6},
			{2, 7, 4, 1},
			{3, 2, 5, 4},
			{4, 5, 6, 7},
			{5, 0, 7, 2},
			{6, 3, 0, 5},
			{7, 6, 1, 0},
		};

		string S;
		for (int i=0; i<X; i++)
			S += s;

		int c = 0;
		for (int i=0; i<L*X; i++)
			c = Q[c][S[i]-'h'];

		bool ans = false;

		if (c==4)
		{
			int a=0;
			for (int i=0; i<L*X && !ans; i++)
			{
				a = Q[a][S[i]-'h'];
				if (a==1)
				{
					int b = 0;
					for (int j=i+1; j<L*X && !ans; j++)
					{
						b = Q[b][S[j]-'h'];
						if (b==2)
							ans = true;
					}
				}
			}
		}

		cout<<"Case #"<<t<<": "<<(ans?"YES":"NO")<<endl;
	}
}
