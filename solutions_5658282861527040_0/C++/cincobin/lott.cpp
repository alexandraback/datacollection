#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <stack>
#include <list>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    int num, n, l;
    ifstream fin;
    ofstream fout;
    string input;
    fin.open("lottsmall.in", std::ifstream::in);
    fout.open("lottsmall.out", std::ofstream::out);
    fin>>num;
    for(int i = 0; i < num; i++)
    {
	int a, b, k;
	fin>>a>>b>>k;
	int count = 0;
	for(int j = 0; j < a; j++)
	{
	    for(int p = 0; p <  b; p++)
	    {
		int c = j & p;
		if(c < k)
		    count++;
	    }
	}
	fout<<"Case #"<<i+1<<": "<<count<<endl;
    }
    fin.close();
    fout.close();
    return 0;
}
