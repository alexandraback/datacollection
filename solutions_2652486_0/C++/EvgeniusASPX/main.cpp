#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
#include <set>
#include <vector>
using namespace std;

 #pragma comment(linker, "/STACK:16777216")

const long long MOD = 1000000007;
const int MAX = 20000;
long long v[MAX];
long long ce[MAX];
long long saveby[MAX];
long long counter = 0;
long long R , N, M ,K;
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int tt;
	cin >> tt;
					
	for (int t = 0; t < tt; ++t)
	{
		cout << "Case #" << t + 1 << ":" << endl;
		cin >> R >> N >> M >> K;
		for (int rr = 0; rr < R; ++rr)
		{			
			for (int i = 0; i < K; ++i)
				cin >> v[i];
			bool found = false;
			

			for (int i = 2; i <= M && !found; ++i)
				for (int j = 2; j <= M && !found; ++j)
					for (int k = 2; k <= M && !found; ++k)
					{
						bool ok = true;
						for (int q = 0; q < K; ++q)
							{
							int w = v[q];
							if (w == 1 || w == i || w == j || w == k || w == k*j ||
								w == k*i || w == i*j || w == i *j*k)
								ok = ok;
							else
								ok = false;
							}

						if (ok)
						{
							found = true;
						cout << i << j << k << endl;
						}
					}

				if (!found)
					cout<<"222"<<endl;
		}	
	}
	return 0;
}