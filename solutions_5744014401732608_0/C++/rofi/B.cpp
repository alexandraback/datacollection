#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include <utility>
#include <list>
#include <functional>

#include <cstdlib>
#include <cmath>
#include <map>
#include <set>
#include <sstream>
#include <iterator>
#include <stack>
#include <queue>
#include <numeric>
using namespace std;

#define	mp						make_pair
#define	pb						push_back
#define	For(i,a,b)				for(int i=(a);i<(b);++i)
#define	rep(i,n)				For(i,0,(n))
#define	all(v)					(v).begin(),(v).end()

typedef	long long				LL;
typedef	vector<int>				VI;
typedef	vector<LL>				VLL;
typedef	vector<vector<int> >	VVI;
typedef	vector<bool>			VB;
typedef	vector<string>			VS;
typedef	pair<int,int>			PII;


string tobin(int w, int s)
{
	string res(w, '0');

	rep(i, w)
		if(s & (1 << (w - i - 1)))
			res[i] = '1';

	return res;
}

LL check(const vector<int> &matrix)
{
	LL result = 0;

	vector<LL> c(matrix.size());
	c[0] = 1;
	rep(i, matrix.size()) {
		vector<LL> next(matrix.size());
		rep(j, matrix.size()) {
			For(k, j + 1, matrix.size()) {
				if(matrix[j] & (1 << (matrix.size() - k - 1)))
					next[k] += c[j];
			}
		}
		result += next.back();

		swap(c, next);
	}
	return result;
}

bool recv(int B, LL M, int index, vector<int> &matrix)
{
	if(B == index + 1) {
		matrix.pb(0);
		bool f = check(matrix) == M;
		if(!f)
			matrix.pop_back();
		return f;
	}

	for(int i = 0 ; i < (1 << (B - index - 1)) ; ++i) {
		matrix.pb(i);
		if(recv(B, M, index + 1, matrix))
			return true;
		matrix.pop_back();
	}
	return false;
}

string solve()
{
	int B;
	LL M;
	cin >> B >> M;

	vector<int> result;
	if(!recv(B, M, 0, result))
		return "IMPOSSIBLE";

	string restr = "POSSIBLE";
	rep(i, B)
		restr += "\n" + tobin(B, result[i]);
	return restr;
}

int main()
{
	int T;

	cin >> T;
	rep(i, T)
		cout << "Case #" << (i + 1) << ": " << solve() << endl;
}

