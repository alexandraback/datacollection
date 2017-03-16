#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int T;
	cin >> T;
	for(int t = 1; t <= T; t++)
	{
		int N, S, p; cin >> N >> S >> p;
		int ans = 0, m;
		vector<int> b(N);
		for(int i = 0; i < N; i++)
		{
			cin >> b[i];
			if(b[i]/3+(b[i]%3>0) >= p) ans++;
			else if(S)
			{
				//in unsurprising form, did not make the cut
				//if make it surprising, will it be good?
				int d = b[i]/3;
				int k = b[i]%3;
				int pa = ans;
				switch(k)
				{
					case(0):
						ans += (d+1 >= p && d-1 >= 0);
						break;
					case(1):
						break;
					case(2):
						ans += (d+2 >= p);
						break;
				}
				S -= (pa != ans);
			}
		}
		cout << "Case #" << t << ": " << ans << endl;
	}
}
