#include <iostream>
#include <string>

using namespace std;

int main()
{
	int t;
	string source, output;
	
	cin >> t;
	
	for (int i = 0; i < t; ++i){
		cin >> source;
		int l = source.length();
		output = "";
		output.append(1, source[0]);
		for (int j = 1; j < l; ++j) {
			if (source[j] >= output[0]) {
				output.insert(0, 1, source[j]);
			}
			else {
				output.append(1, source[j]);
			}
		}
		cout << "Case #" << i + 1 << ": " << output << endl;
	}

	return 0;
}
