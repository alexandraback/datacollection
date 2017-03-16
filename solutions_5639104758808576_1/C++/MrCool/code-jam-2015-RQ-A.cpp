#include <fstream>
#include <iostream>

using namespace std;

int main()
{
	ifstream istr("test");
	ofstream ostr("out");
	int T;
	istr >> T;
	for(int casenum=1;casenum<=T;casenum++)
	{
		ostr << "Case #" << casenum << ": ";
		int result = 0;
		int currentstand = 0;
		int smax = 0;
		int S;

		istr >> smax;
		cout << "smax:" << smax << endl;
		char ch;
		ch = istr.get();
		for(int i=0;i<=smax;i++)
		{
			ch = istr.get();
			cout << ch;
			S = ch - '0';

			int add = 0;
			if(currentstand < i)
				add = i - currentstand;
			currentstand += (S + add);
			result += add;
		}

		ostr << result << endl;
		cout << endl;
	}
	return 0;
}