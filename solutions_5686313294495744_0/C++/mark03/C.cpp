#include<bits/stdc++.h>
using namespace std;

int N;
vector<string> S[2];

int calcola(int pos, int mask)
{
	if(pos == N)
	{
		vector<string> presi[2];
		int conta=0;

		for(int i=0;i<N;++i)
			if((mask & (1<<i)) != 0) presi[0].push_back(S[0][i]), presi[1].push_back(S[1][i]);

		for(int i=0;i<N;++i)
			if((mask & (1<<i)) == 0)
			{
				if(find(presi[0].begin(), presi[0].end(), S[0][i]) != presi[0].end() && 
						find(presi[1].begin(), presi[1].end(), S[1][i]) != presi[1].end())
					conta++;
			}

		return conta;
	}

	return max(calcola(pos+1, mask), calcola(pos+1, mask|(1<<pos)));
}

int foo()
{
	cin >> N;
	S[0].resize(0);
	S[1].resize(0);

	for(int i=0;i<N;++i)
	{
		string A;
		cin >> A;
		S[0].push_back(A);
		cin >> A;
		S[1].push_back(A);
	}

	return calcola(0,0);
}


int main()
{
	int T;
	cin >> T;
	for(int i=0;i<T;++i)
	{
		cout << "Case #" << i+1 <<": " << foo() <<"\n";
	}
}
