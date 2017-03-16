#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

ifstream input;
ofstream output;

const int MAXN = 1000 + 100;

void singleCase(int case_num)
{
	int N;
	string str;
	input >> N >> str;
	int tot = 0;
	int ans = 0;
	for (int i=0; i<=N; i++) if (str[i] != '0')
	{
		ans = max(ans, i - tot);
		tot += str[i] - '0';
	}

	output << "Case #" << case_num << ": " << ans << endl;
}

int main()
{
	input.open("A.in");
	output.open("ovation.out");

	int T;
	input >> T;

	for (int i=0; i<T; i++)
		singleCase(i + 1);

	return 0;
}