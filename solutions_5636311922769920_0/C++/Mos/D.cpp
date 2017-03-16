#include<iostream>
#include<cstdio>
#include<set>
#include<cstdlib>
#include<vector>
using namespace std;

#define FOR(x,N) for(int x = 0 ; x < (N) ; x++ )

int main()
{
	long long T;
	char buf[1000000];
	freopen("in.in", "rt", stdin);
	freopen("out.txt", "wt", stdout);

	cin >> T;
	int K, C, S;
	int cnt = 0;
	FOR(i, T)
	{
		cin >> K;
		cin >> C;
		cin >> S;

		cout <<"Case #"<<i+1<<": ";
		FOR(j, K)
		{
			cout << j+1 << " ";
		}
		cout << endl;
	}

	

	return 0;
}