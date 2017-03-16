#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int vis[1000010];

int res(int x)
{
    int y = 0;
    while(x)
	{
		int z = x % 10;
		y = y * 10 + z;
		x /= 10;
    }
    return y;
}

int main()
{
	freopen("A-small-attempt1.in","r",stdin);
	freopen("asout.out","w",stdout);
	int T;
 	cin >> T;
	memset(vis, 0x3f3f3f3f, sizeof(vis));
	vis[0] = 0;
	for(int i = 1; i <= 1000000; ++i )
	{
		int temp = res(i);
		vis[i] = min(vis[i], vis[i-1]+1);
		if(temp > i + 1)
		{
			vis[temp] = min(vis[temp], vis[i]+1);
		} 
	}
	for(int j = 1; j <= T; j++)
	{
		int n;
		cin >> n;
		cout << "Case #" << j << ": " << vis[n] << endl;
    }
    return 0;
}
