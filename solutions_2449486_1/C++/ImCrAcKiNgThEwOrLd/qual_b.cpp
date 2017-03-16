#include <iostream>
#include <vector>
#include <string>
using namespace std;

int a[100][100], cur[100][100];
bool good[100][100];

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int t = 0;
	cin >> t; 
	for (int counter = 1; counter <= t; ++counter)
	{
		cout << "Case #" << counter << ": ";
		int n, m;
		cin >> n >> m;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
			{
				cin >> a[i][j];
				cur[i][j] = 100;
			}
		bool result = true;
		for (int h = 100; h >= 1; --h)
		{
			memset(good, false, sizeof(good));
			for (int i = 0; i < n; ++i)
			{
				bool is_good = true;
				for (int j = 0; j < m; ++j)
					if (cur[i][j] > h && cur[i][j] == a[i][j])
						is_good = false;
				if (is_good)
					for (int j = 0; j < m; ++j)
						good[i][j] = true;
			}
			for (int j = 0; j < m; ++j)
			{
				bool is_good = true;
				for (int i = 0; i < n; ++i)
					if (cur[i][j] > h && cur[i][j] == a[i][j])
						is_good = false;
				if (is_good)
					for (int i = 0; i < n; ++i)
						good[i][j] = true;
			}
			for (int i = 0; i < n; ++i)
				for (int j = 0; j < m; ++j)
					if (cur[i][j] > h && a[i][j] == h)
						if (good[i][j])
							cur[i][j] = a[i][j];
						else
							result = false;
			if (!result)
				break;
		}
		if (result) cout << "YES"; else cout << "NO";
		cout << endl;
	}
}