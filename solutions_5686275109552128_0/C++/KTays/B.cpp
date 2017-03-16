#include <iostream>
#include <cstring>
using namespace std;

int cnt[1005], ans;

void search(int it,int c)
{
	while (cnt[it] == 0 && it > 0)it--;
	
	if (it + c < ans){
		ans = it + c;
	}
	if (it == 1)return;

	for (int i = it - 1; i >=  it / 2; i--){
		cnt[i] += cnt[it];
		cnt[it - i] += cnt[it];
		search(it - 1, c + cnt[it]);
		cnt[i] -= cnt[it];
		cnt[it - i] -= cnt[it];
	}
}

int main()
{
	int test_num, d, p;

	//freopen("D:\\B-small-attempt0.in", "r", stdin);
	//freopen("D:\\out.txt", "w", stdout);

	cin >> test_num;
	for (int t = 1; t <= test_num; t++){
		cin >> d;

		memset(cnt, 0, sizeof(cnt));
		for (int i = 0; i < d; i++){
			cin >> p;
			cnt[p]++;
		}
		ans = 1005;
		search(1001, 0);

		cout << "Case #" << t << ": " << ans << endl;
	}
	return 0;
}