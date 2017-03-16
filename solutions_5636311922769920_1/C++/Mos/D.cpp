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
	freopen("in2.in", "rt", stdin);
	freopen("out2.txt", "wt", stdout);

	cin >> T;
	int K, C, S;
	int cnt = 0;
	FOR(i, T)
	{
		cin >> K;
		cin >> C;
		cin >> S;

		cout <<"Case #"<<i+1<<": ";

		if (C == 1)
		{
			if (S == K)
			{
				FOR(j, K)
				{
					cout << j + 1 << " ";
				}
				cout << endl;
			}
			else
			{
				cout << "IMPOSSIBLE" << endl;
			}
		}
		else if (C > 1)
		{
			int p = K / C;
			if (C*p != K) p++;

			if ( p <= S)
			{ 			
				FOR(j, p)
				{
					unsigned long long  pos = j*(C)*_Pow_int(K, C - 1);
					unsigned long long pos_end = (j*C + 1)*_Pow_int(K, C - 1);
					
					for (int m = C - 2; m>= 0;m--)
					{
						pos += (C - m - 1)*_Pow_int(K, m);
						if (K<C)
						{
							if (m - C + K == 0)
							{
								pos--;
								break;
							}
						}
					}
					if (pos > pos_end-1)
						pos = pos_end-1;
					if (pos > _Pow_int((unsigned long long)K, C) - 1)
						pos = _Pow_int((unsigned long long)K, C) - 1;

					cout << pos +1<< " ";
				}
				cout << endl;
			}
			else
			{
				cout << "IMPOSSIBLE" << endl;
			}
		}
	}
	
	return 0;
}
