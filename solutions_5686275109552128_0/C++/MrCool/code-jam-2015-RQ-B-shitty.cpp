#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

int main()
{
	ifstream istr("test");
	ofstream ostr("output");
	int T;
	istr >> T;
	for(int casenum=1;casenum<=T;casenum++)
	{
		ostr << "Case #" << casenum << ": ";
		int D;
		istr >> D;
		int plates[1010];
		memset(plates, 0, sizeof(plates));
		for(int i=0;i<D;i++)
		{
			int cakes;
			istr >> cakes;
			plates[cakes]++;
		}

		int result = 99999;
		int maxcakes = 1000;
		for(int i=1000;i>=1;i--)
			if(plates[i])
			{
				maxcakes = i;
				break;
			}

		for(int i=1;i<=maxcakes;i++)
		{
			int tmpresult = 0;
			for(int j=maxcakes;j>=1;j--)
				if(plates[j] && j > i)
					{
						if(j%i == 0)
							tmpresult += (j / i - 1) * plates[j];
						else
							tmpresult += j / i * plates[j];
					}
			tmpresult += i;
			//ostr << i << ": " << tmpresult << endl;
			if(tmpresult < result)
				result = tmpresult;
		}
		ostr << result << endl;
	}
	return 0;
}