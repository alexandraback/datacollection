#include <iostream>

using namespace std;

int N;
int r[10000][3];
int dp[1000000];

int enc(int v[]) {
    int s = 0;
    for (int i = 0; i < N; ++i) {
	s <<= 2;
	s += v[i];
    }
    return s;
}

int dec(int k, int v[]) {
    int s = 0;
    for (int i = 0; i < N; ++i) {
	int x = k & 3;
	s += x;
	v[N-1-i] = x;
	k >>= 2;
    }
    return s;
}

int f(int k)
{
    if (dp[k] >= -1) {
	return dp[k];
    }
    if (k == 0) {
	return 0;
    }

    int v[1024];
    int s = dec(k, v);

    const int M = 1000000000;
    int m = M;
    for (int i = 0; i < N; ++i) {
	switch (v[i]) {
	case 1:
	    if ((s-1) >= r[i][1]) {
		v[i] = 0;
		int c = f(enc(v));
		v[i] = 1;
		if (c >= 0) {
		    m = min(m, 1 + c);
		}
	    }
	    break;
	case 2:
	    if ((s-1) >= r[i][2]) {
		v[i] = 1;
		int c = f(enc(v));
		v[i] = 2;
		if (c >= 0) {
		    m = min(m, 1 + c);
		}
	    }
	    if ((s-2) >= r[i][2]) {
		v[i] = 0;
		int c = f(enc(v));
		v[i] = 2;
		if (c >= 0) {
		    m = min(m, 1 + c);
		}
	    }
	    break;
	}
    }

    if (m == M)
	m = -1;

    return (dp[k] = m);
}


int main()
{
    int nCase;
    cin >> nCase;
    for (int iCase = 1; iCase <= nCase; ++iCase) {
	cin >> N;
	int sz = sizeof(dp)/sizeof(dp[0]);
	for (int i = 0; i < sz; ++i) {
	    dp[i] = -100;
	}

	for (int i = 0; i < N; ++i) {
	    cin >> r[i][1] >> r[i][2];
	}

	int v[1024];
	for (int i = 0; i < N; ++i) {
	    v[i] = 2;
	}
	int r = f(enc(v));

	if (r < 0)
	    cout << "Case #" << iCase << ": Too Bad" << endl;
	else
	    cout << "Case #" << iCase << ": " << r << endl;
    }

    return 0;
}
