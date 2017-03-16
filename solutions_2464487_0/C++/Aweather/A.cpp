#include<iostream>
#include<fstream>
#include<string>
#include<vector>

using namespace std;

int main(int argc, char *argv[])
{
    if (argc!=3) 
    {
	cout << "Missing arguments." << endl;
	return -1;
    }
    
    ifstream fin(argv[1]);
    ofstream fout(argv[2]);

    int T;

    fin >> T;

    for (int i = 0; i < T; ++i)
    {
	unsigned long long int r, t;

	fin >> r;
	fin >> t;

	unsigned long long int k = 0;

	while(1)
	{
	    unsigned long long int require = 2*r + 1 + 4*k;
	    if (t >= require)
	    {
		t -= require;
		++k;
	    }
	    else
	    {
		fout << "Case #" << i+1 << ": " << k << endl;
		break;
	    }
	}


    }

    return 0;
}
