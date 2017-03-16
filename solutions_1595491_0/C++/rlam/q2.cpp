#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int case_num = 0;
	int i = 0;
	int j = 0;
	int nGoogler = 0;
	int nSurprise = 0;
	int p = 0;
	int ans = 0;
	int temp = 0;
	int bestResult[2][31] = {
		{0, 1, 1, 1, 2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7, 7, 8, 8, 8, 9, 9, 9, 10, 10, 10},
		{-1, -1, 2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7, 7, 8, 8, 8, 9, 9, 9, 10, 10, 10, -1, -1}};
	vector<int> nums;
	vector<int>::reverse_iterator rit;

	cin >> case_num;
	for (i = 0; i < case_num; i++) {

		cin >> nGoogler >> nSurprise >> p;
		nums.clear();
		ans = 0;
		for (j = 0; j < nGoogler; j++) {
			cin >> temp;
			nums.push_back(temp);
		}		
		sort(nums.begin(), nums.end());
		
		for (rit = nums.rbegin(); rit < nums.rend(); rit++) {
			if (bestResult[0][*rit] >= p)
				ans++;
			else if (nSurprise-- > 0 && bestResult[1][*rit] >= p)
				ans++;
		}

		cout << "Case #" << i + 1 << ": " << ans << endl;
	}
}
