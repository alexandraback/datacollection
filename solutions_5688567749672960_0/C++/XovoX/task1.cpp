#include <vector>
#include <tuple>
#include <set>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;
long long reverse(long long j)
{
	long long s = j;
	long long rev=0;
	while (s != 0)
	{
		long long r = s % 10;
		rev *= 10;
		rev += r;
		s /= 10;
	}
	return rev;
}
int main()
{
	ifstream fin;
	fin.open("A-small-attempt1.in");
	if (fin.is_open())
	{
		ofstream fout;
		fout.open("A-small-attempt1.out");
		long long T;
		fin >> T;
		for (int i = 0; i < T; i++)
		{
			long long N;
			fin >> N;
			long long res = 0;

			for (long long j = 1; j <= N; j++)
			{
				res++;
				long long rev1 = reverse(j);
				long long rev2 = reverse(j+1);
				if (rev1>j && rev1 <= N && (rev2<j || rev2>N))
				{ 
					j = rev1; res++;
				}
			}

			fout << "Case #" << i + 1 << ": " << res << endl;
			
			cout << "Case #" << i + 1 << ": "<<res << endl;
			
		}
		fin.close();
		fout.close();
	}
	return 0;
}