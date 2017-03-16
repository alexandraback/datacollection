#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

ifstream input;
ofstream output;

const int MAXN = 1000 + 10;

int a[MAXN];

void singleCase(int case_num)
{
	int N;
	input >> N;
	for (int i=0; i<N; i++)
		input >> a[i];

	int ans = MAXN * MAXN;
	for (int upper=1; upper <= 1000; upper++)
	{
		int tot = 0;
		for (int i=0; i<N; i++)
		{
			int part = (a[i] - 1) / upper + 1;
			tot += part - 1;
		}
		ans = min(ans, tot + upper);
	}

	output << "Case #" << case_num << ": " << ans << endl;
}

int main()
{
	input.open("B-small.in");
	output.open("B-small.out");

	int T;
	input >> T;

	for (int i=0; i<T; i++)
		singleCase(i + 1);

	return 0;
}