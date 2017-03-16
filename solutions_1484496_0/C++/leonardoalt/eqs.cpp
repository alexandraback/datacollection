#include <cstring>
#include <iostream>

using namespace std;

#define MAXN 20
#define MAXV 2000000

int v[MAXN];
int ss[MAXV];
int is[MAXV];

int
main()
{
	int N, T;
	int i, j, s, c;
	bool b;
	int s0, s1;

	c = 0;
	cin >> T;
	while(T--)
	{
		memset(ss, 0, sizeof(ss));
		memset(is, 0, sizeof(is));

		cin >> N;
		for(i = 0; i < N; ++i) cin >> v[i];

		b = false;
		for(i = 0; i < (1 << N); ++i)
		{
			s = 0;
			for(j = 0; j < N; ++j)
				if(i & (1 << j)) s += v[j];
			if(ss[s])
			{
				s0 = is[s];
				s1 = i;
				b = true;
				break;
			}
			++ss[s];
			is[s] = i;
		}

		cout << "Case #" << ++c << ":\n";
		if(!b) cout << "Impossible" << endl;
		else
		{
			for(i = 0; i < MAXN; ++i)
				if(s0 & (1 << i)) cout << v[i] << ' ';
			cout << endl;
			for(i = 0; i < MAXN; ++i)
				if(s1 & (1 << i)) cout << v[i] << ' ';
			cout << endl;
		}
	}

	return 0;
}

