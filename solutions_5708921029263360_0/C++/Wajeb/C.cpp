#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main()
{
	int T;
	cin >> T;

	for(int t = 1; t <= T; t++)
	{
		int J, P, S, K;
		cin >> J >> P >> S >> K;

		map<pair<int, int>, int> s1, s2, s3;
		vector<vector<int> > res;

		for(int i = 1; i <= J; i++)
		{
			for(int j = 1; j <= P; j++)
			{
				for(int k = 1; k <= S; k++)
				{
					pair<int, int> p1 = make_pair(i, j);
					pair<int, int> p2 = make_pair(i, k);
					pair<int, int> p3 = make_pair(j, k);
					if((s1.count(p1) < 0 || s1[p1] < K) && (s2.count(p2) < 0 || s2[p2] < K) && (s3.count(p3) < 0 || s3[p3] < K))
					{
						if(s1.count(p1) > 0) s1[p1] = s1[p1] + 1;
						else s1[p1] = 1;
						if(s2.count(p2) > 0) s2[p2] = s2[p2] + 1;
						else s2[p2] = 1;
						if(s3.count(p3) > 0) s3[p3] = s3[p3] + 1;
						else s3[p3] = 1;
					} 
					else continue;

					vector<int> dress;
					dress.push_back(i);
					dress.push_back(j);
					dress.push_back(k);
					res.push_back(dress);
				}
			}
		}

		int sz = res.size();

		cout << "Case #" << t << ": " << sz << endl;
		for(int i = 0; i < sz; i++)
		{
			for(int j = 0; j < 3; j++)
			{
				if(j != 0) cout << " ";
				cout << res[i][j];
			}
			cout << endl;
		}
	}

	return 0;
}