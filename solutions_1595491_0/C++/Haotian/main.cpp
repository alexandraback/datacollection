#include <iostream>
#include <fstream>
using namespace std;
int min(int a, int b) {return a<b?a:b;}
int main()
{
	ifstream fin;
	//fin.open("test.txt");
	fin.open("B-small-attempt0.in");
	int T;
	fin>>T;
	ofstream fout;
	fout.open("B-small-attempt0.out");
	//fout.open("res.txt");
	int N, S, p, curr;
	for(int t = 1; t <= T; t++)
	{
		fout << "Case #" << t << ": ";
		fin >> N;
		fin >> S;
		fin >> p;
		int finiteThres = 3*p-2;
	    int possThres = 3*p -4;
		int count = 0, possCount = 0;
		for(int n = 0; n < N; n++)
		{
			fin >> curr;
			if(curr >= finiteThres)
				count++;
			else if (curr >= possThres  && curr >0 )
				possCount++;
		}
		fout << count + min(possCount, S) << std::endl;
	}
	return 0;
}
	
	