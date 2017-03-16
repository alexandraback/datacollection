#include <bits/stdc++.h>

#define ll long long
#define ff first
#define ss second
#define mp make_pair

using namespace std;

typedef pair < ll , ll > pie;
int bang[100][100];
int hmmm[3000];

int main()
{
	ios_base::sync_with_stdio(false);
	int T;
	cin >> T;
	for(int i = 1; i <= T; i++)
	{
		int N,tmp;
		cin >> N;
		for(int j = 0; j<3000; j++)
			hmmm[j] = 0;
		for(int j = 0; j<(2*N-1)*N;j++)
		{
			cin>>tmp;
			hmmm[tmp]++;
		}
		vector<int> mvec;
		for(int j = 0; j<3000; j++)
			if(hmmm[j] % 2 == 1)
				mvec.push_back(j);
		sort(mvec.begin(), mvec.end());
		cout<<"Case #"<<i<<":";
		for(int j = 0; j < (int)mvec.size(); j++)
			cout<<" "<<mvec[j];
		cout<<endl;

	}
	return 0;
}