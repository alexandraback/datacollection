#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <string>
#include <string.h>

using namespace std;

vector<pair<long long,int>> mask;


int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	int i,j,k, t, n, m;

	n = (1 << 20)-2;
	mask.assign( n, make_pair(0,0));
	for (i=0; i< n; i++)
	{
		mask[i].second = i + 1;
	}
	
	cin >> t;
	for (int tt = 1; tt <= t; tt++)
	{
		long long sum1=0, sum2=0;

		cin >> m;
		vector<long long> v(m);
		for (i=0; i<m; i++)
		{
			cin >> v[i];
		}

		for (i=0; i<n; i++)
		{
			mask[i].first = 0; // CLEAR

			for (j =0; j < 20; j ++)
			{
				if ( (mask[i].second >> j) & 1 )
					mask[i].first += (long long) v[j];
			}
		}

		sort(mask.begin(), mask.end());

		bool b = false;
		int ans1 = -1, ans2 = -1;
		for (i=0; i<n; i++)
		{
			if (i+1 < n)
			{
				if (mask[i].first == mask[i+1].first)
				{
					int cnt = 0;
					for (j=i; j <n; j++)
					{
						if (mask[j].first == mask[i].first)
							cnt++;
						else
							break;
					}

					if (cnt <= 1)
						continue;
					else
					{
						b = false;
						for (j = i; j < i + cnt; j++)
						{
							for (k = j + 1; k < i + cnt; k++)
							{
								b = true;
								for (int ii =0 ; ii < 20; ii++)
									if ( ((mask[j].second >> ii)&1) * ((mask[k].second >> ii)&1) == 1)
									{
										b = false;
										break;
									}
								if (b)
								{
									// ANS DAS+DOA+S_DO+_ASOd
									ans1 = j;
									ans2 = k;
									break;
								}
							}
							if (b)
								break;
						}
					}
				}
			}

			if (b)
				break;
		}

		cout << "Case #" << tt << ":" << endl;
		if (ans1 == -1 || ans2 == -1)
			cout << "Impossible" << endl;
		else
		{
			for (j =0; j < 20; j++)
			{
				if ( (mask[ans1].second >> j) & 1 )
					cout << v[j] << " ";
			}
			cout << endl;
			for (j =0; j < 20; j++)
			{
				if ( (mask[ans2].second >> j) & 1 )
					cout << v[j] << " ";
			}
			cout << endl;
		}
	}


	return 0;
}