#include <fstream>
#include <string>
using namespace std;

int main()
{
	unsigned int		T, iIndex = 0, N;
	string				strWord;
	string				strWinningWord;

	ifstream	InFile("A-small-attempt0.in");
	ofstream	OutFile("Test.out", ios_base::ate || ios_base::out);

	if (OutFile.is_open() && InFile.is_open())
	{
		InFile >> T;

		while (T--)
		{
			InFile >> strWord;
			strWinningWord = strWord[0];

			for (int i = 1; i < strWord.length(); ++i)
			{
				if (strWord[i] >= strWinningWord[0])
					strWinningWord = strWord[i] + strWinningWord;
				else
					strWinningWord += strWord[i];
			}

			OutFile << "Case #" << ++iIndex << ": " << strWinningWord << endl;
		}
	}

	return 0;
}
