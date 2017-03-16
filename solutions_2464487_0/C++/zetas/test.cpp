#include<iostream>
#include<fstream>
#include <algorithm>
using namespace std;
ifstream fin("A-small-attempt0.in");
ofstream fout("A-small-attempt0.out");

int T=1;


int main()
{
	fin >> T;
	for(int i = 1; i <= T; i++)
	{
		int r = 1;
		int t = 1;
		int count = 0;
		fin >> r >> t;
		int a = 2*r + 1;
		while(t >= a){
			count++;
			t -= a;
			a += 4;
		}
		fout << "Case #" << i << ": " << count;
		if(i < T) fout << endl;
	}
	return 0;
}