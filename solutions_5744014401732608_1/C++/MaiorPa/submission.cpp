#include <algorithm>
#include <iomanip>
#include <istream>
#include <map>
#include <numeric>
#include <ostream>
#include <set>
#include <fstream>
#include <sstream>
#include <string>
#include <utility>
#include <vector>
#define ll long long

using namespace std;
// Powered by caide (code generator, tester, and library code inliner)
ll t,  k, f = 0, b, m;
vector< vector<int> >ans(55, vector<int>(55, 0));


vector<ll> two(10);

class Solution {
public:
	void solve(std::istream& in, std::ostream& out) {
		two[0] = 1;
		for (int i = 1; i < 10; i++)
		{
			two[i] = 2 * two[i - 1];
		}
		ofstream ttt;
		ttt.open("output.out");
		in >> t;
		for (int ii = 1; ii <= t; ii++)
		{
			f = 0;
			in >> b >> m;
			ttt << "Case #" << ii << ": ";
			k = 2;
			ll powtwo = 1;
			while ((k<=b) && (powtwo<m))
			{
				powtwo *= 2;
				k++;
			}			
			if (k==b+1)
			{
				ttt << "IMPOSSIBLE";
				ttt << endl;
			}
			else
			{
				for (int i = 1; i <= b; i++)
				{
					for (int j = 1; j <= b; j++)
					{
						if (i<j)
						{
							ans[i][j] = 1;
						}
						else
						{
							ans[i][j] = 0;
						}
					}
				}
				if (k != b || powtwo != m){
					for (int j = 0; j <= b; j++)
					{
						ans[1][j] = 0;
					}
					int p = b - 1;
					while (m > 0){
						ans[1][p] = m % 2;
						m /= 2;
						p--;
					}
				}
				ttt << "POSSIBLE" << endl;
				for (int i = 1; i <= b; i++)
				{
					for (int j = 1; j <= b; j++)
					{
						ttt<<ans[i][j];
					}
					ttt<<endl;
				}
			}
		}

	}
};

void solve(std::istream& in, std::ostream& out)
{
	out << std::setprecision(12);
	Solution solution;
	solution.solve(in, out);
}

#include <iostream>

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    istream& in = cin;

    ostream& out = cout;
    solve(in, out);
    return 0;
}
