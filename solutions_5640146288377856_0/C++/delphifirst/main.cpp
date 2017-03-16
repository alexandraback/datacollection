#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int case_count;
	cin >> case_count;
	for (int case_no = 1; case_no <= case_count; ++case_no)
	{
		cout << "Case #" << case_no << ": ";
		int r, c, w;
		cin >> r >> c >> w;
		int result = c / w * r + w - 1;
		if (c % w != 0)
			++result;
		cout << result << endl;
	}
}
