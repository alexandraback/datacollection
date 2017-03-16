#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(0);
	freopen("c.in", "r", stdin); 
	freopen("c.out", "w", stdout);
	int test;
	cin >> test;
	for (int noTest = 1; noTest <= test; noTest++)
	{
		cerr << "Running test " << noTest << endl;
    int n, h, x, t0;
    vector < pair<int,int> > a;
    cin >> n;
    while (n--)
    {
      cin >> x >> h >> t0;
      for (int i = 0; i < h; i++)
        a.push_back(make_pair(t0 + i, x));
    }
    
    int ans = 0;
    sort(a.begin(), a.end());
    if (a.size() == 2 && (720LL - a[0].second) * a[0].first <= (360LL - a[1].second) * a[1].first)
      ans = 1;
    
		printf("Case #%d: %d\n", noTest, ans);
	}
}
