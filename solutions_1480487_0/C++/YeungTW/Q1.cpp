#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    int T, N[50], s[50][200], i, j, sum[50] = {0};
	double e[50];
    ifstream infile("input.txt");
    ofstream outfile("output.txt");
    
    infile >> T;
    for (i=0;i<T;i++)
    {
        infile >> N[i];
        for (j=0;j<N[i];j++)
		{
			infile >> s[i][j];
			sum[i] = sum[i] + s[i][j];
		}
    }
	
	for (i=0;i<T;i++)
	{
		double larger = 0, tmp = 0;
		for (j=0;j<N[i];j++)
		{
			if (s[i][j]>(sum[i]*2/N[i])) {larger++;}
			else tmp = tmp + s[i][j];		
		}
		e[i]=(tmp+sum[i])/(N[i]-larger);
	}
	
	for (i=0;i<T;i++)
	{
		outfile << "Case #" << i+1 << ": ";
		for (j=0;j<N[i];j++)
		{
			outfile.precision(8);
			if (s[i][j]>e[i]) {outfile << 0;}
			else {outfile << (e[i]-s[i][j])/sum[i]*100;}
			if (j!=N[i]) {outfile << " ";}
		}
		outfile << endl;
	}
	    
    infile.close();
    outfile.close();
    return 0;   
}

