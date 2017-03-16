#include <cstring>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
const long double eps = 1e-9;

using namespace std;

int n;
int x[300];
long double ans[300];

void Solve()
{
	cin >> n;
	long double sum = 0;
	int i;

	vector<pair<int, int> > e;
	for (i = 0; i < n; i++) {
		cin >> x[i];
		e.push_back(make_pair(x[i], i));
		sum += x[i];
		ans[i] = 0;
	}
	sort(e.begin(), e.end());
	int j;
	long double cur = sum;
	e.push_back(make_pair(e.back().first+2*sum, n));
	for (i = 0; i < n; i++) {
		long double l = e[i+1].first -  e[i].first;
		if ((i+1) * l < cur + eps) {
			cur -= (i+1) * l;
		} else {
			long double pos = e[i].first + cur/(i+1);
			cur = 0;
			for (j = 0; j <= i; j++) {
				ans[e[j].second] = (pos-e[j].first)/sum;
			}
			break;
		}
	}
	
	cout.precision(7);
	cout.setf(ios::fixed | ios::showpoint);
	for (i = 0; i < n; i++) 
		cout << 100*ans[i] << ' ';
	cout << "\n";

}

int main()
{
	int nt, tt;
	cin >> nt;
	for (tt = 1; tt <= nt; tt++) {
		cout << "Case #" << tt << ": ";
		Solve(); 
	}
	return 0;
}
