#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void Open() {
	freopen ("input.dat", "r", stdin);
	freopen ("output.dat", "w", stdout);
}

void Close() {
	fclose(stdin);
	fclose(stdout);
}

int FinishCase() {
	int A, B;
	int ans = 0;
	scanf ("%d %d", &A, &B);
	for (int i = A; i < B; i++) {
		char tmp[100];
		itoa(i, tmp, 10);
		string tmpstr(tmp);
		vector<int> nums;
		nums.clear();
		for (int j = 1; j < tmpstr.size(); j++) {
			string shiftstr = tmpstr.substr(j, tmpstr.size() - j) + tmpstr.substr(0, j);
			int shiftnum = atoi(shiftstr.c_str());
			nums.push_back(shiftnum);
		}
		sort(nums.begin(), nums.end());
		for (int j = 0; j < nums.size(); j++) {
			if (nums[j] > i && A <= nums[j] && nums[j] <= B) {
				if (j == 0 || (j > 0 && nums[j] != nums[j - 1])) ans++;
			}
		}
	}
	return ans;
}

int main() {
	int T;
	Open();
	scanf ("%d\n", &T);
	for (int i = 0; i < T; i++)
	{
	//	printf ("%d\n", i);
		int ans = FinishCase();
		printf ("Case #%d: %d\n", i + 1, ans);
	}
	Close();
	return 0;
}