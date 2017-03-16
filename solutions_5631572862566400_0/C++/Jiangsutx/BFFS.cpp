#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;

int n;
int a[1001];
bool visited[1001];

int dfs(int s[1001], int i, int k)
{
	int sum = 1;
	//if (a[s[k - 1]] < i) return 0;
	if (a[s[k - 1]] == i && s[k - 2] != i) return k - 1;
	if (k > n) return 0;

	if (a[s[k - 1]] != s[k - 2])
	{
		if (visited[a[s[k - 1]]]) return 0;
		s[k] = a[s[k - 1]];
		visited[a[s[k - 1]]] = true;
		int t = dfs(s, i, k + 1);
		sum = (t>sum) ? t : sum;
		visited[a[s[k - 1]]] = false;
	}
	else
	{
		sum = k-1;
		for (int j = 1; j <= n; j++)
		{
			if (!visited[j])
			{
				s[k] = j;
				visited[j] = true;
				int t = dfs(s, i, k + 1);
				sum = (t>sum) ? t : sum;
				visited[j] = false;
			}
		}
	}
	return sum;
}

int main()
{
	ofstream ofile;
	ifstream ifile;

	ofile.open("C-large-practice-out.txt");
	ifile.open("C-small-attempt2.in");

	long T;


	ifile >> T;
	for (int iT = 1; iT <= T; iT++)
	{
		ifile >> n;
		if (n < 3)
		{
			ofile << "Case #" << iT << ": " << n << endl;
			continue;
		}
		for (int i = 0; i < 1001; i++)
		{
			a[i] = 0;
			visited[i] = false;
		}
		for (int i = 1; i <= n; i++)	ifile >> a[i];

		int s[1001];
		int sum = 0;
		for (int i = 1; i <= n; i++)
		{
			s[1] = i;
			s[2] = a[i];
			visited[i] = true;
			visited[a[i]] = true;
			int t = dfs(s, i, 3);
			sum = (t > sum) ? t : sum;
			visited[i] = false;
			visited[a[i]] = false;
		}

		ofile << "Case #" << iT << ": " << sum << endl;

	}
	ifile.close();
	ofile.close();
	system("pause");
}