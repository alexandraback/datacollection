#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef long long     LL;

#define For(i,a,b)    for(int i=(a);i<(b);++i)
#define rep(i,n)      For(i,0,(n))

LL powll(LL n, int p)
{
	LL result = 1;
	rep(i, p)
		result *= n;
	return result;
}

LL getpos(int length, int pos, int depth)
{
	if(!depth)
		return pos;

	LL result = 0;
	rep(i, pos)
		result += powll(LL(length), depth);
	return result + getpos(length, (pos + 1) % length, depth - 1);
}

vector<LL> solve()
{
	LL K, C, S;

	cin >> K >> C >> S;

	vector<LL> result;
	if(K > C * S) {
		result.push_back(-1);
		return result;
	}

	for(LL i = 0 ; i < K ; i += C)
		result.push_back(getpos(K, i, C - 1) + 1);

	return result;
}

int main()
{
	int T;

	cin >> T;
	rep(i, T) {
		cout << "Case #" << (i + 1) << ":";
		for(auto i : solve()) {
			if(i < 0)
				cout << " IMPOSSIBLE";
			else
				cout << " " << i;
		}
		cout << endl;
	}
}
