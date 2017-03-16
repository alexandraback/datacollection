#include <iostream>
#include <vector>
using namespace std;
typedef vector<int> VI;
typedef vector<VI> VVI;
int main()
{
	int n_case;
	cin >> n_case;
	for (int tc=0; tc<n_case; tc++)
	{
		int m, n;
		cin >> m >> n;
		VVI lawn(m, VI(n));
		for (int i=0; i<m; i++)
		{
			for (int j=0; j<n; j++)
			{
				cin >> lawn[i][j];
			}
		}
		VI max_row(m), max_col(n);
		for (int i=0; i<m; i++)
		{
			for (int j=0; j<n; j++)
			{
				max_row[i] = max(max_row[i], lawn[i][j]);
				max_col[j] = max(max_col[j], lawn[i][j]);
			}
		}
		bool possible = true;
		for (int i=0; i<m; i++)
		{
			for (int j=0; j<n; j++)
			{
				possible &= max_row[i] == lawn[i][j] || max_col[j] == lawn[i][j];
			}
		}
		cout << "Case #" << tc + 1 << ": " << (possible ? "YES" : "NO") << endl;

	}
	return 0;
}
