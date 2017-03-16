#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 2550;
int cnt[N];
int main(){
	int T,n;
	cin >> T;
	for (int cas = 1;cas <= T;cas ++)
	{
		cin >> n;
		memset(cnt,0,sizeof(cnt));
		for (int i = 1;i <= 2*n - 1;i ++)
		{
			for (int j = 1;j <= n;j++){
			int num;
			cin >> num;
			cnt[num] += 1;
			}
		}
		cout << "Case #" << cas << ":";
		for (int i = 1;i <= 2500;i ++)
		{
			if (cnt[i] & 1)
			{
				cout << " " << i;
			}
		}	
		cout << endl;
	}
	return 0;
}
