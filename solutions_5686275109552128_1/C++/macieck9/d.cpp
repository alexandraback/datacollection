#include<iostream>
#include<cmath>
#include<algorithm>

using namespace std;

int T[1005];

int main()
{
    ios_base::sync_with_stdio(0);
    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; t++)
    {
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) cin >> T[i];
		int ans = 1000000000;
		for (int i = 1; i <= 1000; i++)
		{
			int res = 0;
			for (int j = 0; j < n; j++)
			{
				int k = max(T[j]/i,1);
				//cout << i << " " << j << "\n";
				while(k > 1 and (int)ceil(1.0*T[j]/(k-1)) <= i) k--;
				while((int)ceil(1.0*T[j]/(k)) > i) k++;
				res += k-1;
			}
			ans = min(ans,res+i);
		}
		cout << "Case #" << t << ": " << ans << "\n";
	}


    return 0;
}
