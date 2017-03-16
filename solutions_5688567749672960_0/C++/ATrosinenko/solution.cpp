#include <string.h>
#include <assert.h>

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

using namespace std;

const int MAXN = 100000000;

int arr[MAXN];
int queue[MAXN];
int beg, end;

void test(int n, int ans)
{
    assert(n < MAXN);
	if(arr[n] < 0)
	{
		arr[n] = ans;
		queue[end++] = n;
	}
}

int rev(int n)
{
	int res = 0;
	while(n)
	{
		res = res * 10 + n % 10;
		n /= 10;
	}
	return res;
}

void init()
{
    beg = 0;
	end = 1;
	queue[0] = 1;
	memset(arr, -1, sizeof(arr));
    arr[1] = 1;
}

void solve(const int t)
{
	int N;
	cin >> N;
	while(1)
	{
		assert(beg < end);
        if(arr[N] >= 0)
		{
			cout << "Case #" << t << ": " << arr[N] << "\n";
            return;
		}
		int cur = queue[beg++];
		test(cur + 1, arr[cur] + 1);
		test(rev(cur), arr[cur] + 1);
	}
}

int main()
{
    int T;
    init();
    
    cin >> T;
    for(int t = 1; t <= T; ++t)
    {
        cerr << "Solving #" << t << "\n";
        solve(t);
    }
    return 0;
}
