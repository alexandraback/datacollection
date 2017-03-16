#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void wynik()
{
	int N;
	cin>>N;
	vector < int > V(2501, 0), W;
	for(int i=0; i<N*(2*N-1); i++)
	{
		int pom;
		cin>>pom;
		V[pom]++;
	}
	for(int i=0; i<2501; i++)
		if (V[i]%2==1)
		{
			W.push_back(i);
		}
	for(auto& el : W)
		cout << el << " ";
	
}

int main()
{
//	ios_base::sync_with_stdio(0); cin.tie(0);
	int testy;
	cin>>testy;
	for(int test=1; test<=testy; test++)
	{
		cout << "Case #"<<test<<": ";
		wynik();
		cout<<endl;
	}
}
