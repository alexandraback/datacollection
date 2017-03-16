#include<string>
#include<iostream>
#include<fstream>
using namespace std;

int levels[1001][3];

int main(void)
{
	ifstream file;
	file.open("B-small-attempt1.in");
	ofstream output;
	output.open("result.out");
	levels[1000][2]=0;

	int caseNo;
	file >> caseNo;

	for(int t=1; t<= caseNo; t++)
	{
		int numberOfLevels;
		file >> numberOfLevels;
		for(int n=0; n<numberOfLevels; n++)
		{
			file >> levels[n][0] >> levels[n][1];
			levels[n][2]=levels[n][1]-levels[n][0];
		}

		int stars=0;
		int result=0;
		int maxLevelsN2=1000;
		for(int n=0; n<2*numberOfLevels; n++)
		{
			for(int m=0; m<numberOfLevels; m++)
			{
				if(levels[m][1]<=stars)
				{
					if(levels[m][0]==9999) stars+=1;
					else stars+=2;
					result+=1;
					levels[m][0]=9999;
					levels[m][1]=9999;
					m=-1;
				}
			}
			for(int m=0; m<numberOfLevels; m++)
			{
				if(levels[m][0]<=stars && levels[m][2]>=levels[maxLevelsN2][2])
					maxLevelsN2=m;
			}
			if(maxLevelsN2 != 1000)
			{
				stars+=1;
				result+=1;
				levels[maxLevelsN2][0]=9999;
				maxLevelsN2=1000;
			}
		}

		output << "Case #" << t << ": ";
		if(stars>=2*numberOfLevels)
			output <<  result << endl;
		else
			output <<  "Too Bad" << endl;
	}

}
