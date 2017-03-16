#include<bits/stdc++.h>
using namespace std;

vector<int> mask[16];

int main()
{
	int T,N,K;
	cin >> T >> N >> K;
	cout<<"Case #1:\n";

	string S(N, '0');
	S[0] = S[N-1] = '1';
	int conta = 0;

	for(int i=0; i<(1<<(N/2-1)); ++i)
		mask[__builtin_popcount(i)].push_back(i);

	for(int i=1; i<=(N-2)/2 && conta<K; ++i)
	{
		for(int m1 : mask[i])
		{
			for(int m2 : mask[i])
			{
				string t = S;
				for(int j=0; j<(N-2)/2; ++j)
				{
					if(m1 & (1<<j))
						t[j*2+1] = '1';
					if(m2 & (1<<j))
						t[j*2+2] = '1';
				}
				cout<<t<<" ";
				for(int j=2;j<=10;++j)
					cout<<j+1<<" ";
				cout<<"\n";
		
				conta++;
				if(conta >= K) break;
			}
			if(conta >= K) break;
		}
	}

	assert(conta == K);
}
