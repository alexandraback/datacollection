#pragma comment (linker, "/STACK:64000000")
#include <memory.h>
#include <cstdio> 
#include <sstream> 
#include <iostream> 
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <algorithm>
#include <cstring>
#include <list>
#include <cmath>

using namespace std;

//485271451

typedef long long lint;
typedef pair<int,int> pii;
#define pb push_back
#define sz(a) (int)((a).size())


void prepare(string s){
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

#else
	//freopen((s + ".in").c_str(), "r", stdin); 
	//freopen((s + ".out").c_str(), "w", stdout);
#endif
}


int b[100 * 1000 * 5];
int a[100];
bool solve(){

	int T;
	cin >> T;
	for (int t = 0; t < T; ++ t)
	{
	
		int n;
		cin >> n;
		for (int i = 0; i < n; ++ i)
			cin >> a[i];
		cout << "Case #" << t + 1 << ":" << endl;
		for (int msk = 1; msk < (1 << n); ++ msk)
		{
			memset(b, 0, sizeof(b));
			b[0] = -1;
			int sum = 0;
			for (int i = 0; i < n; ++ i)
				if (msk & (1 << i))
					sum += a[i];
				else
				{
					for (int j = 100 * 1000 * 5 - a[i] - 1; j >= 0; -- j)
						if (b[j])
							b[j + a[i]] = i + 1;
				}
			if (b[sum])
			{
				for (int i = 0; i < n; ++ i)
					if (msk & (1 << i))
						cout << a[i] << ' ';
				cout << endl;
				int cur = sum;
				while (cur != 0)
				{
					cout << a[b[cur] - 1] << ' ';
					cur -= a[b[cur] - 1];
				}
				cout << endl;
				break;
			}
		}

	}

	return false;
}

int main(){

	prepare("");
	while (solve());



	return 0;
}