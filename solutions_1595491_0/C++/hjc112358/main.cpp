#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char** argv)
{
	int i = 0;
	int j = 0;
	int T = 0;
	int N = 0;
	int S = 0;
	int p = 0;
	int t = 0;
	int count = 0;
	int value1 = 0;
	int value2 = 0;
	ifstream inFile("B-small-attempt0.in");
	ofstream outFile("result.out");
	inFile >> T;
	for (i=0;i<T;i++)
	{
		outFile<<"Case #"<<i+1<<": ";
		count = 0;
		inFile >> N >> S >> p;
		value1 = p>0 ? (p-1)*3+1 : 0;
		value2 = p>=2 ? value1-2 : p==1 ? 1 : 0;
		for (j=0;j<N;j++)
		{
			inFile >> t;
			if ((t>=value1))
				count++;
			else if ((t>=value2)&&(S>0))
			{
				count++;
				S--;
			}
		}
		outFile<<count<<endl;
	}
	inFile.close();
	outFile.close();
	return 0;
}

