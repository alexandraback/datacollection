#include <iostream>
using namespace std;

#define	For(i,a,b)				for(int i=(a);i<(b);++i)
#define	rep(i,n)				For(i,0,(n))

int solve()
{
	int R, C, W;

	cin >> R >> C >> W;

	int res = (C / W) * R + W;

	if(C % W == 0)
		--res;

	return res;
}

int main()
{
	int T;

	cin >> T;

	rep(i, T)
		cout << "Case #" << (i + 1) << ": " << solve() << endl;
}
