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
		
		
		long long a,b;
		f >> a;
		f >> b;
		long long a2 = a;
		int digitNum = 0;
		int digitOffset= 1;
		while (a2 != 0)
		{
			a2 /= 10;
			digitNum++;
			digitOffset *= 10;
		}
		digitOffset /= 10;

		long long result = 0;
		for (long long i = a; i <= b; ++i)
		{
			long long next = (i / 10 + digitOffset * (i % 10));
			while (next != i)
			{
				 if (next > i && next <= b)
				 {
					 ++result;
				 }
				 next = (next / 10 + digitOffset * (next % 10));
			}

		}

		r << "Case #" << i + 1 << ": " << result << endl;		
	}

	r.close();
	f.close();
	return 0;
}
