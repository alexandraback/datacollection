#include <iostream>
#include <cstdio>
#include <set>
#include <utility>
#include <vector>
#include <map>
using namespace std;

#define P pair<int,int>

int main(void)
{
	int T;
	cin >> T;
	for (int i = 1; i <= T; i++)
	{
		cout << "Case #" << i << ": " << endl;
		map < int, int > S;
		int N; cin >> N;
		vector <int> A(N);
		for (int j = 0; j < N; j++)
			cin >> A[j];
		bool poss = false;
		for (int s = 1; s < ( 1 << N); s++)
		{
			int sm = 0;
			for (int j = 0; j < N; j++)
				if ( (1 << j) & s)
					sm += A[j];
			if ( S.count(sm) > 0 )
			{
				int B = S[sm];
				for (int j = 0; j < N; j++)
					if ( ( 1<< j ) & B)
						cout << A[j] << " ";
				cout << endl;
				for (int j = 0; j < N; j++)
					if ( ( 1<< j ) & s)
						cout << A[j] << " ";
				cout << endl;
				poss = true;
				break;
			}
			S[sm] = s;
		}
		if (!poss)
			cout << "Impossible\n";
		S.clear();
//		printf("%1.9f\n", ans);
	}
	return 0;
}
