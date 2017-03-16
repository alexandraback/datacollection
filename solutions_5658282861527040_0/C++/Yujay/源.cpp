#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
#include <fstream>
#include <numeric>
using namespace std;
ifstream in("in.in");
ofstream out("out.out");
int main()
{
	int N;
	int A, B, K;
	int count;
	int loop = 0;
	in >> N;
	while (N--)
	{
		loop++;
		count = 0;
		in >> A >> B >> K;
		for (int i = 0; i < K; i++)//±éÀúK
		{
			for (int j = 0; j < A;j++)
			for (int k = 0; k < B; k++)
			{
				if ( (j&k) == i)
					count++;
			}
		}
		out <<"Case #"<<loop<<": "<< count << endl;

	}
	getchar();
	getchar();
}