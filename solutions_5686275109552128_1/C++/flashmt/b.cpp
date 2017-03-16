#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("b-large.in", "r", stdin); 
	freopen("b-large.out", "w", stdout);
	int test;
	cin >> test;
	for (int noTest = 1; noTest <= test; noTest++)
	{
    int n, a[1010];
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];

    int ans = 1000;
    for (int eat = 1; eat <= 1000; eat++)
    {
      int need = 0;
      for (int i = 0; i < n; i++)
        need += (a[i] - 1) / eat;
      ans = min(ans, eat + need);
    }
    
		printf("Case #%d: %d\n", noTest, ans);
	}
}
