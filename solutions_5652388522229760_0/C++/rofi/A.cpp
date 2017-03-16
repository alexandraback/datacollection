#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

#define  For(i,a,b)    for(int i=(a);i<(b);++i)
#define  rep(i,n)      For(i,0,(n))

void update(vector<bool> &v, int i)
{
	while(i) {
		v[i % 10] = true;
		i /= 10;
	}
}

string solve()
{
	vector<bool> v(10, false);
	int N;

	cin >> N;
	rep(i, 2000) {
		update(v, i * N);
		if (find(v.begin(), v.end(), false) == v.end())
			return to_string(i * N);
	}

	return "INSOMNIA";
}

int main()
{
	int T;

	cin >> T;
	rep(i, T)
		cout << "Case #" << (i + 1) << ": " << solve() << endl;
}
