#include <iostream>
using namespace std;

int main()
{
	int t;
	int a, b, k;
	int ans;
	cin >> t;
	for (int i=1;i<=t;i++)
	{
		ans = 0;
		cin >> a >> b >> k;
		for (int j=0;j<a;j++)
			for (int l=0;l<b;l++)
				if ((j&l)<k)
					ans++;
		cout << "Case #" << i << ": " << ans << endl;
	}
	return 0;
}
