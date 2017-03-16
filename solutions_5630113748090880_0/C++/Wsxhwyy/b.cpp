#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int t[3000];
vector<int> lists;

int main()
{
	int c;
	cin >> c;
	for (int cc = 1; cc <= c; cc++)
	{
		int N;
		cin >> N;
		lists.clear();
		memset(t, 0, sizeof(t));
		for (int i = 1; i < 2 * N; i++)
		{
			vector<int> l;
			for (int j = 0; j < N; j++)
			{
				int tmp;
				cin >> tmp;
				t[tmp]++;
			}
		}
		cout << "Case #" << cc << ": ";
		for (int i = 0; i < 3000; i++)
			if (t[i] % 2)
				lists.push_back(i);
		for (int i = 0; i < N - 1; i++)
			cout << lists[i] << ' ';
		cout << lists[N - 1] << endl;
	}
}