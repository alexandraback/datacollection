#include <fstream>
#include <algorithm>

using namespace std;

int main()
{
	ifstream in("input2.txt", ios::in);
	ofstream out("output2.txt", ios::out);
	
	int t; in >> t;
	for (int i = 1;i <= t;i++)
	{
		int n, s, p, ans = 0;
		in >> n >> s >> p;
		int nums[3];
		for (int j = 0;j < n;j++)
			in >> nums[j];
		sort(nums, nums+n);
		reverse(nums, nums+n);
		for (int j = 0;j < n;j++)
		{
			int x = nums[j] / 3;
			if (nums[j]%3) x++;
			if (x >= p) { ans++; continue; }
			if (s == 0 || nums[j] < 2) break;
			if (nums[j]%3 == 0) x = nums[j] / 3 + 1;
			if (nums[j]%3 == 1) x = nums[j] / 3 + 1;
			if (nums[j]%3 == 2) x = nums[j] / 3 + 2;
			if (x >= p) { s--; ans++; }
		}
		out << "Case #" << i << ": " << ans << "\n";
	}
	
	in.close();
	out.close();
	return 0;
}
