#include<iostream>
#include<algorithm>

using namespace std;

double N[1005];
double K[1005];

int main()
{
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    for (int l = 1; l <= t; l++)
    {
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) cin >> N[i];
		for (int i = 0; i < n; i++) cin >> K[i];
		sort(N,N+n);
		sort(K,K+n);
		int j = 0;
		int ans2 = 0;
		int ans1 = n;
		for (int i = 0; i < n; i++)
		{
			while(K[j] < N[i] and j < n) j++;
			if (j >= n) {ans2 = n-i; break;}
			j++;
		}
		j = 0;
		for (int i = 0; i < n; i++)
		{
			while(N[j] < K[i] and j < n) j++;
			if (j >= n) {ans1 = i; break;}
			j++;
			//cout << i << " " << j << "\n";
		}
		cout << "Case #" << l << ": " << ans1 << " " << ans2 << "\n";
	}

    //system("pause");
    return 0;
}
