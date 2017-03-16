#pragma error(disable:4996)
#include<iostream>
#include<iomanip>
#include<cstring>
#include<string>
#include<algorithm>
#include<map>
#include<set>
#include<vector>
#include<queue>
using namespace std;
typedef long long LL;
const LL MAXSIZE = 10000000;
int a[1000000];
LL L;


int main()
{
	errno_t err1;
	errno_t err2;
	FILE *fin, *fout;
	err1 = freopen_s(&fin, "A-small-attempt0.in", "r", stdin);
	//err1 = freopen_s(&fin, "A-small-attempt0 (1).in", "r", stdin);
	err2 = freopen_s(&fout, "out.txt", "w", stdout);
	LL T;
	cin >> T;
	memset(a, 0, sizeof(a));

	for (LL z = 1; z <= T; ++z)
	{
		int n,m,k;
		cout << "Case #" << z << ": ";

		cin >> n >> m >> k;
		if (k == 1)
			cout << m << endl;
		else if (m == k)
			cout << k << endl;
		else if (m == k + 1)
			cout << k + 1 << endl; 
		else cout << (m-1) / k + k << endl;
		
	
	}

}
