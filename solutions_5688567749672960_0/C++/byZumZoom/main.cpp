#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <map>
#include <sstream>
#include <cmath>
#include <bitset>
#include <utility>
#include <set>
#include <numeric>
#include <ctime>

#define INF 2147483647
#define PI acos(-1.0)

using namespace std;

#define CHAR_BITS 33

const char *my_itoa_buf(char *buf, size_t len, int num)
{
  if (snprintf(buf, len, "%d", num) == -1)
	return ""; /* or whatever */

  return buf;
}

int reverse(int i)
{
	char buff[33];
	my_itoa_buf(buff, 33, i);
	string s(buff);
	reverse(s.begin(), s.end());
	return atoi(s.c_str());
}

int main(int argc, const char ** argv)
{
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);

	const int N = 1000010;
	int A[N];
	for(int i = 1; i < N; ++i)
		A[i] = INF;
	A[0] = 0;
	A[1] = 1;
	for(int i = 1; i < N; ++i)
	{
		A[i + 1] = min(A[i + 1], A[i] + 1);
		int q = reverse(i);
		if(q < N)
			A[q] = min(A[q], A[i] + 1);
	}

	int t;
	cin >> t;

	for(auto tt = 1; tt <= t; ++tt)
	{
		int n;
		cin >> n;

		cout << "Case #" << tt << ": " << A[n] << endl;
	}


	return 0;
}
