#include <cstdio>
#include <string>
#include <vector>
#include <memory>
#include <cmath>
#include <algorithm>
#include <map>
#include <set>
#include <stack>
using namespace std;
double EPS = 1e-9;
int gauss (vector < vector<double> > a, vector<double> & ans) {
	int n = (int) a.size();
	int m = (int) a[0].size() - 1;
 
	vector<int> where (m, -1);
	for (int col=0, row=0; col<m && row<n; ++col) {
		int sel = row;
		for (int i=row; i<n; ++i)
			if (abs (a[i][col]) > abs (a[sel][col]))
				sel = i;
		if (abs (a[sel][col]) < EPS)
			continue;
		for (int i=col; i<=m; ++i)
			swap (a[sel][i], a[row][i]);
		where[col] = row;
 
		for (int i=0; i<n; ++i)
			if (i != row) {
				double c = a[i][col] / a[row][col];
				for (int j=col; j<=m; ++j)
					a[i][j] -= a[row][j] * c;
			}
		++row;
	}
 
	ans.assign (m, 0);
	for (int i=0; i<m; ++i)
		if (where[i] != -1)
			ans[i] = a[where[i]][m] / a[where[i]][i];
	for (int i=0; i<n; ++i) {
		double sum = 0;
		for (int j=0; j<m; ++j)
			sum += ans[j] * a[i][j];
		if (abs (sum - a[i][m]) > EPS)
			return 0;
	}
 
	for (int i=0; i<m; ++i)
		if (where[i] == -1)
			return -1;
	return 1;
}
vector< vector<double> > v;
int main(void)
{
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	int t;
	scanf("%d",&t);
	for (int q = 1; q <= t; q++)
	{
		v.clear();
		int n;
		scanf("%d",&n);
		int a[205];
		int sum = 0;
		for (int i = 0 ; i < n; i++)
		{
			scanf("%d",&a[i]);
			sum += a[i];
		}
		/*v.resize(n);
		for (int i = 0; i < n; i++)
			v[i].resize(n+1);
		for (int i = 0 ; i < n-1; i++)
		{
			v[i][0] = sum * 1.0 / 100;
			v[i][i+1] = -sum * 1.0 / 100;
			v[i][n] = a[i+1] - a[0];
		}
		for (int i = 0; i < n; i++)
			v[n-1][i] = 1;
		v[n-1][n] = 100;
		vector<double> ans;
		for (int i = 0 ; i <= n; i++)
			v[n-1][i] *= sum * 1.0 / 100;
		double totalx1 = v[n-1][n];
		for (int i = 0; i < n-1; i++)
			totalx1 += v[i][n];
		ans.resize(n);
		ans[0] = totalx1 * 1.0/ (n * v[0][0]);
		for (int i = 0 ; i < n-1; i++)
			ans[i+1] = (v[i][n] - v[i][0] * ans[0]) / v[i][i+1];*/
		double avg = 2.0 * sum / n;
		double sum1 = 0;
		int n1 = 0;
		for (int i = 0; i < n; i++)
			if (a[i] < avg)
			{
				sum1 += a[i];
				n1++;
			}
		double avg1 = 1.0 * (sum + sum1) / n1;
		vector<double> ans;
		for (int i = 0 ; i < n; i++)
			if (a[i] < avg)
				ans.push_back((avg1 - a[i]) * 100 / sum); else
				ans.push_back(0);
		printf("Case #%d: ", q);
	
			for (int i = 0 ; i < ans.size(); i++)
				printf("%.7lf%c", ans[i], (i == (ans.size()-1) )? '\n' : ' ');
	}
	return 0;
}