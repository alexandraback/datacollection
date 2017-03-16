#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);

	int Testow; cin>>Testow;
	for (int test=1; test<=Testow; ++test)
	{
		int N,S,P;
		cin>>N>>S>>P;

		int minA=max(3*P-2,0);
		int minB=max(3*P-4,2);
	
		int cnt=0;

		for (int i=0; i<N; ++i)
		{
			int x; cin>>x;
			if (x>=minA) ++cnt;
			else if (x>=minB && S>0)
			{
				--S;
				++cnt;
			}
		}
		cout<<"Case #"<<test<<": "<<cnt<<endl;
	}

	return 0;
}