#include <iostream>
#include <cstdio>
using namespace std;

long long MAX(int E, int maxE, int R, long long v[], int l, int r)
{
	if (E > maxE)
		E = maxE;
	/*cout << "E=" << E << ";R=" << R << ";v=";
	for (int x=l; x<=r; x++)
		cout << v[x] << "/";
	cout << endl;*/
	if (r-l == 0)
		return E * v[l];

	long long max = 0;
	for (int e=0; e<=E; e++)
	{
		long long gain = e * v[l] + MAX(E-e+R, maxE, R, v, l+1, r);
		if (gain > max)
			max = gain;
	}
	return max;
}
		

int main(int argc, char *argv[])
{
	freopen(argv[1], "r", stdin);
	freopen(argv[2], "w", stdout);

	int T;
	cin >> T;
	for (int t=0; t<T; t++)
	{
		int E, R, N;
		cin >> E >> R >> N;
		long long v[N];
		for (int n=0; n<N; n++)
			cin >> v[n];

		long long ans = MAX(E, E, R, v, 0, N-1);		

		cout << "Case #" << t+1 << ": " << ans << endl;
	}

	return 0;
}
