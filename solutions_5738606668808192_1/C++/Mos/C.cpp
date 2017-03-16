#include<iostream>
#include<cstdio>
#include<set>
#include<cstdlib>
#include<vector>
using namespace std;

#define FOR(x,N) for(int x = 0 ; x < (N) ; x++ )

unsigned long long n_rep(string s, unsigned long long n)
{
	unsigned long long ret = 0;
	FOR(i, s.length())
	{
		ret += (s[i]-48) * _Pow_int(n, s.length() - i - 1);
	}
	return ret;
}

int main()
{
	long long T;
	char buf[1000000];
	freopen("in.txt", "rt", stdin);
	freopen("out2.txt", "wt", stdout);

	cin >> T;
	int N, J;
	string a,temp;
	string b[500];
	int cnt = 0;
	FOR(i, T)
	{
		cin >> N;
		cin >> J;
		a.resize(N / 2 );
		FOR(j, N / 2) a[j] = '0';
		a[a.length() - 1] = '1';
		bool flag = false;
		FOR(j, N / 2)
		{
//			FOR(k, _Pow_int(2, N / 2 - 2))
			FOR(k, J)
			{
				if (j == 0)	b[k] = a;

				if (j > 0)
				{
					if (k % (_Pow_int(2, j-1)) == 0)
					{
						if (flag)
							flag = false;
						else
							flag = true;
					}

					if (flag) b[k][a.length() - 1-j] = '1';
				}
			}
		}

		cout << "Case #1:" << endl;
		FOR(j, J)
		{
			int cnt = 0;
			FOR(l, b[j].length())
			{
				if (b[j][l] == '1')
					break;
				cnt++;
			}
			temp = a;
			temp[a.length() - 1] = '0';
			FOR(l, b[j].length()-cnt)
			{
				temp[l] = b[j][l + cnt];
			}
			cout <<(temp+b[j]).c_str() <<" ";
			FOR(k, 9)
			{
				cout << n_rep(b[j], k + 2) << " ";
			}
			cout << endl;
		}
	}

	return 0;
}