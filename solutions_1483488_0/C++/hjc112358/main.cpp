#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <set>

using namespace std;

int main(int argc, char** argv)
{
	unsigned int i = 0;
	unsigned int j = 0;
	unsigned int T = 0;
	unsigned int A = 0;
	unsigned int B = 0;
	unsigned int n = 0;
	unsigned int m = 0;
	unsigned int len = 0;
	unsigned int count = 0;
	char buffer[20];
	char ctemp[20];
	set<int> myset;
	ifstream inFile("C-small-attempt0.in");
	ofstream outFile("result.out");
	//ostream &outFile = cout;
	inFile >> T;
	for (i=0;i<T;i++)
	{
		outFile<<"Case #"<<i+1<<": ";
		inFile >> A >> B;
		count = 0;
		len = (unsigned int)floor(log10((double)A)+1);
		for (n=A;n<B;n++)
		{
			_itoa_s(n, buffer, 10);
			memmove(buffer+len, buffer, len+1);
			ctemp[len] = '\0';
			myset.clear();
			for (j=1;j<len;j++)
			{
				memcpy(ctemp, buffer+j, len);
				m = atoi(ctemp);
				if ((m>n)&&(m<=B))
				{
					if (myset.find(m)==myset.end())
					{
						myset.insert(m);
					}
				}
			}
			count+=myset.size();
		}
		outFile<<count<<endl;
	}
	inFile.close();
	outFile.close();
	return 0;
}

