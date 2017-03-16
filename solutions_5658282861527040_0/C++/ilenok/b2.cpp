#include<fstream>
#include<iostream>

using namespace std;

int nwinpairs(int a, int b, int k)
{
	int res = 0;
	for (int i = 0; i < a; ++ i)
		for (int j = 0; j < b; ++ j)
		{
			if ((i & j) < k)
			{
				++ res;
				//cout << i <<" " << j <<"  " <<  endl;
			}
		}
	return res; 
}


int main()
{
	int t, a, b, k;
	ifstream inputfile("in.txt");
	ofstream outputfile("out.txt");
	inputfile >> t;
	for (int i = 0; i < t; ++ i)
	{
		inputfile >> a >> b >> k;
		outputfile << "Case #" << i + 1 << ": " << nwinpairs(a, b, k) << endl;
	}
}
