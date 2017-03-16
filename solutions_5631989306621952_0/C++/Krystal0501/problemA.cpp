#include <iostream>

using namespace std;

int main() {

	int T;
	cin >> T;
	getchar();
	for (int i = 0; i < T; ++i)
	{
			bool isstart = true;
			char ch;
			string result("");
			while((ch = getchar()) != '\n') {
				if (isstart)
				{
						result += ch;
						isstart = false;
				}
				else if (ch >= result.at(0))
				{
					result = ch + result;
				}
				else {
					result += ch;
				}
			}

			cout << "Case #" << i + 1 << ": " << result << endl;

	}
	return 0;
}