#if 1
#include<iostream>
#include<string>
using namespace std;

FILE* pF;

FILE* pAnsF;

string S;


int main()
{
	freopen_s(&pF, "Text.txt", "r", stdin);
	freopen_s(&pAnsF, "OA.txt", "w", stdout);

	int C;

	cin >> C;

	for (int c = 1; c <= C; c++)
	{
		cin >> S;
		string lastWord;
		lastWord.push_back(S[0]);
		for (int i = 1; i < S.size(); i++)
		{
			if (lastWord[0] <= S[i])
			{
				lastWord = S[i] + lastWord;
			}
			else
			{
				lastWord = lastWord + S[i];
			}
		}
		cout << "Case #" << c << ": ";
		cout << lastWord << endl;
	}
	
	return 0;
}
#endif