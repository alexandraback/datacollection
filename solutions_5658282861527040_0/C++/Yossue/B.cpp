#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;


int main()
{
	ifstream ifs("C:/yoshiko/programming/gcj/2014/1b/B/B/B-small-attempt0.in");
	ofstream ofs("C:/yoshiko/programming/gcj/2014/1b/B/B/B-small-attempt0.out");
	string line;


	int nCases = 0;
	ifs >> nCases;

	for(int i=0; i<nCases; ++i)
	{
		long A = 0;
		ifs >> A;

		long B = 0;
		ifs >> B;

		long K = 0;
		ifs >> K;

		long answer = 0;
		for(long j=0; j<A; ++j)
		{
			for(long k=0; k<B; ++k)
			{
				long num = j & k;
				if(num < K)
				{
					answer++;
				}
			}
		}

		ofs << "Case #" << i+1 << ": " << answer << endl;
	}
}