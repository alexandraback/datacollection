#include <fstream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;
int T;

long long int solve(long long int A, long long int B, long long int K)
{
	long long int y = 0;
	long long int tmp;
	if(A < B)
	{
		tmp = B;
		B = A;
		A = tmp;
	}
	if(B == 0)
		return A+1;
	long long int Amax = 1;
	tmp = A;
	while(tmp/2 > 0)
	{
		tmp /= 2;
		Amax *= 2;
	}
	y = solve(Amax-1,B,K);
	if(B < Amax)	
		y +=solve(A-Amax,B,K);
	else
	{
		y +=solve(A-Amax,Amax-1,K);
		if(K > Amax)
			y += solve(A-Amax,B-Amax,K-Amax);
	}
	return y;
}

void main()
{
	ifstream fin("B-small-attempt0.in");
	ofstream fout("out.txt");
	fin >> T;
	for (int i = 0; i != T; i++)
	{
		long long int A, B, K;
		long long int y;
		fin >> A >> B >> K;
		A -= 1;
		B -= 1;
		y = solve(A,B,K);
		fout << "Case #" << i+1 << ": " << y << endl;
	}
	fin.close();
	fout.close();
}