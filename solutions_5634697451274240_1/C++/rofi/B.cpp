#include <iostream>
#include <string>

using namespace std;

#define  For(i,a,b)    for(int i=(a);i<(b);++i)
#define  rep(i,n)      For(i,0,(n))

int solve()
{
	string S;
	int result = 0;

	cin >> S;
	S.push_back('+');
	For(i, 1, S.size())
		if(S[i-1] != S[i])
			++result;

	return result;
}

int main()
{
	int T;

	cin >> T;
	rep(i, T)
		cout << "Case #" << (i + 1) << ": " << solve() << endl;
}
