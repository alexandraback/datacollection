#include <fstream>
#include <string>
#include <iostream>

using namespace std;


int main(int argc, const char *argv[])
{
	int numStrings = 0;
	string name, temp;
	int nValue = 0;

	cin >> numStrings;
	getline(cin, temp);

	for (int i = 0; i < numStrings; ++i) {
		cin >> name >> nValue;
		getline(cin, temp);

		int stringLength = name.size();
		int numConseqs = 0;
		int startPos = 0;
		int endPos = 0; 
		int nameValue = 0;

		while (1) {
			while (numConseqs < nValue) {
				if (endPos >= stringLength) {
					goto done;
				}

				if (name[endPos] == 'a' || name[endPos] == 'e' || name[endPos] == 'i' || name[endPos] == 'o' || name[endPos] == 'u') {
					numConseqs = 0;
				}
				else {
					++numConseqs;
				}

				++endPos;
			}

			nameValue += stringLength - endPos + 1;

			++startPos;

			if (endPos - startPos < numConseqs) {
				--numConseqs;
			}
		}

done:

		cout << "Case #" << (i + 1) << ": " << nameValue << endl;
	}

	return 0;
}
