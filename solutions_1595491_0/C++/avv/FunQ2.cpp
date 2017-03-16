#include "stdafx.h"
#include "stdafx.h"
#include "fstream"
#include "vector"
#include "algorithm"
#include "numeric"
#include "sstream"
#include "string"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{


	fstream f("test.txt");
	fstream r("result.txt");
	
	stringstream strStream;
	string line;
	//string word;
	int t;
	f >> t;

	for (int i = 0; i < t; ++i)
	{
		
		int n, s, p;
		f >> n;
		f >> s;
		f >> p;

		int possiblyNumOfBestScore = 0;

		for (int j  = 0; j < n; ++j)
		{
			int point;
			f >> point;

			if (point - p - max((p - 1), 0) - max((p - 1), 0) >= 0)
			{
				++possiblyNumOfBestScore;
			}
			else if (point - p - max((p - 2), 0) - max((p - 2), 0) >= 0 && s != 0)
			{
				s--;
				++possiblyNumOfBestScore;

			}
		}

		r << "Case #" << i + 1 << ": " << possiblyNumOfBestScore << endl;		
	}

	r.close();
	f.close();
	return 0;
}
