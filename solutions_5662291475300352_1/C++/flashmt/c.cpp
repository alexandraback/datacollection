#include <bits/stdc++.h>
using namespace std;
const int oo = 27081993;

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
    
    int ans = oo;
    sort(a.begin(), a.end());
    for (int i = 0; i < int(a.size()); i++)
    {
      int hit = 0;
      for (int j = 0; j < int(a.size()); j++)
        if (i != j)
        {
          int x = min(i, j), y = max(i, j);
          if ((720LL - a[x].second) * a[x].first <= (360LL - a[y].second) * a[y].first)
            hit++;
        }
      ans = min(ans, hit);
    }
    
		printf("Case #%d: %d\n", noTest, ans);
	}
}
