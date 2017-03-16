#include <iostream>
#include <fstream>
#include <algorithm>
#include <iomanip>
using namespace std;
#define forn(i,start,Max) for(int i=start;i<Max;i++)
ifstream in("in.txt");
ofstream out("out.txt");



int main()
{
	int T,A,B,K,sum,tem;
	in >> T;
	forn(i, 0, T)
	{
		out << "Case #" << i + 1 << ": ";
		in >> A >> B >> K;
		sum = 0;
		forn(j, 0, A )
		{
			forn (z, 0, B)
			{
				tem = z&j;
				if (tem < K)
					sum++;
			}
		}
		out << sum<<endl;
	}
	return 0;
}
//out << setiosflags(ios::fixed);
//out << setprecision(8) ;