# include <fstream>
# include <iostream>
# include <string>
# include <vector>
# include <math.h>
# include <algorithm>
# include <string.h>
# include <stack>
# include <queue>
# include <sstream>
# include <set>
# include <map>
# include <assert.h>
using namespace std;

int n;
int f[1000];

const int maxpos = 110;
const int maxa = 1010000;
int memory[maxpos][maxa];

int ans(int pos, int a)
{
	int origin_a = a;
	int origin_pos = pos;
	if (pos < maxpos && a < maxa && memory[pos][a] != -1)
		return memory[pos][a];
	while (pos < n && a > f[pos])
		a += f[pos++];
	if (pos >= n)
		return 0;

	if (a == 1)
		return n - pos;

	int cur = 0;
	while (a <= f[pos]) 
	{
		cur++;
		a += a - 1;
	}
	return memory[origin_pos][origin_a] = min(n - pos, cur + ans(pos, a));
}


int main()
{
    //ios_base::sync_with_stdio(false);
    ifstream cin ("input.txt");
    ofstream cout ("output.txt");
    
	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; test++)
	{
		memset(memory, -1, sizeof(memory));
		int a;
		cin >> a >> n;
		for (int i = 0; i < n; i++)
			cin >> f[i];
		sort(f, f + n);


		cout << "Case #" << test << ": " << ans(0, a) << endl;
	}

    //system("pause");
    return 0;
}
