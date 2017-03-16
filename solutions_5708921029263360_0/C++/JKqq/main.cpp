#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <map>

using namespace std;

#define ll long long
#define pii pair<ll, ll>
#define endl "\n"
#define mp make_pair
#define pll pair<ll,ll>

#include <fstream>
ifstream in("task.in");
ofstream out("task.out");

#define cin in
#define cout out
/**/



int main()
{
	ios_base::sync_with_stdio(0);

	int numTests;
	cin >> numTests;
	int ttt = 0;
	while (numTests--)
	{
		++ttt;

		int J, P,S,K;
		cin >> J >> P >> S >> K;

		vector<pair<int, pii>> all;
		for (int i = 1; i <= J; ++i)
			for (int j = 1; j <= P; ++j)
				for (int k = 1; k <= S; ++k)
				{
					pair<int, pii> c = mp(i, mp(j,k));
					all.push_back(c);
				}

				if (J == 3 && P == 3 && S == 3)
				{
					if (K >= 3)
					{
						cout << "Case #"<<ttt<<": 27"<< endl;
						for (int i = 0; i < all.size(); ++i)
							cout << all[i].first << " " << all[i].second.first << " " << all[i].second.second << endl;

					}
					else
					{cout << "Case #"<<ttt<<": ";
						if(K == 1) 
						{ 
							cout << "9\n"; 
							cout << "2 1 1\n"; 
							cout << "1 2 1\n"; 
							cout << "3 3 1\n"; 
							cout << "1 1 2\n"; 
							cout << "3 2 2\n"; 
							cout << "2 3 2\n"; 
							cout << "3 1 3\n"; 
							cout << "2 2 3\n"; 
							cout << "1 3 3\n"; 

						} else if(K == 2) 
						{ 
							cout << "18\n"; 
							cout << "1 1 1\n"; 
							cout << "3 1 1\n"; 
							cout << "1 2 1\n"; 
							cout << "2 2 1\n"; 
							cout << "2 3 1\n"; 
							cout << "3 3 1\n"; 
							cout << "1 1 2\n"; 
							cout << "2 1 2\n"; 
							cout << "2 2 2\n"; 
							cout << "3 2 2\n"; 
							cout << "1 3 2\n"; 
							cout << "3 3 2\n"; 
							cout << "2 1 3\n"; 
							cout << "3 1 3\n"; 
							cout << "1 2 3\n"; 
							cout << "3 2 3\n"; 
							cout << "1 3 3\n"; 
							cout << "2 3 3\n";
						}}
						continue;
					}

					vector<pair<int, pii>> ans;
					int mxAns = 0;
					for (int i = 1; i < (1 << all.size()); ++i)
					{
						vector<vector<int>> a(4, vector<int>(4, 0));
						vector<vector<int>> b(4, vector<int>(4, 0));
						vector<vector<int>> c(4, vector<int>(4, 0));


						vector<pair<int, pii>> cur;
						for (int j = 0; j < 30; ++j)
							if (i & (1 << j))
								cur.push_back(all[j]);

						for (int u = 0; u < cur.size(); ++u)
						{
							int aa = cur[u].first;
							int bb = cur[u].second.first;
							int cc = cur[u].second.second;
							a[aa][bb]++;
							b[aa][cc]++;
							c[bb][cc]++;
						}
						int t = 0;
						for (int i = 1; i <= 3; ++i)
							for (int j = 1; j <= 3; ++j)
								t = max(max(t, max(a[i][j], b[i][j])), c[i][j]);

						if (t <= K && mxAns < cur.size())
						{
							ans = cur;
							mxAns = cur.size();
						}
					}

					cout << "Case #"<<ttt<<": "<< mxAns << endl;
					for (int i = 0; i < ans.size(); ++i)
						cout << ans[i].first << " " << ans[i].second.first << " " << ans[i].second.second << endl;
				}


				return 0;
	}