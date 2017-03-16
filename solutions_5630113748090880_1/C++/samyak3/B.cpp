#if 1
#include<iostream>
#include<string>
#include<vector>
using namespace std;

FILE* pF;

FILE* pAnsF;

int N;

int hcount[2501];

void reset()
{
	for (int i = 0; i <= 2500; i++)
	{
		hcount[i] = 0;
	}
}

int main()
{
	freopen_s(&pF, "Text.txt", "r", stdin);
	freopen_s(&pAnsF, "OB.txt", "w", stdout);

	int C;

	cin >> C;

	for (int c = 1; c <= C; c++)
	{
		cin >> N;
		int h;
		vector<int>ans;
		for (int i = 0; i < ((2 * N - 1)*N); i++)
		{
			cin >> h;
			hcount[h] = hcount[h] + 1;
		}
		for (int i = 1; i <= 2500; i++)
		{
			if (hcount[i] != 0 && hcount[i] % 2 != 0)
			{
				ans.push_back(i);
			}
		}
		cout << "Case #" << c << ": ";
		for (int i = 0; i < ans.size(); i++)
		{
			cout << ans[i] << " ";
		}
		cout << endl;
		reset();
	}

	return 0;
}
#endif