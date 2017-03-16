#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cstring>
#include <fstream>
using namespace std;

#define all(o) (o).begin(), (o).end()
#define allr(o) (o).rbegin(), (o).rend()
#define INF 2147483647
typedef long long ll;
typedef pair<int, int> ii;
template <class T> int size(T x) { return x.size(); }

int main()
{
	string from = "ejp mysljylc kd kxveddknmc re jsicpdrysi rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd de kr kd eoya kw aej tysr re ujdr lkgc jv";
	string to = "our language is impossible to understand there are twenty six factorial possibilities so it is okay if you want to just give up";
	map<char, char> mapping;
	mapping['q'] = 'z';
	mapping['z'] = 'q';

	for (int i = size(from) - 1; i >= 0; i--)
	{
		mapping[from[i]] = to[i];
	}

	int cnt;
	scanf("%d\n", &cnt);
	string line;

	for (int i = 0; i < cnt; i++)
	{
		printf("Case #%d: ", i + 1);
		getline(cin, line);
		int len = size(line);
		for (int j = 0; j < len; j++)
		{
			printf("%c", mapping[line[j]]);
		}

		printf("\n");
	}

	return 0;
}