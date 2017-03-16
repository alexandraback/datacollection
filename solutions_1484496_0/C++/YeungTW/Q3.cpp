#include <iostream>
#include <fstream>
#include <bitset>
using namespace std;

unsigned int T, N[10], S[10][20], sum[1048576], i, j, k;
int main()
{
    ifstream infile("input.txt");
    ofstream outfile("output.txt");
    
    infile >> T;
    for (i=0;i<T;i++)
    {
        infile >> N[i];
        for (j=0;j<N[i];j++)
		{
			infile >> S[i][j];
		}
	}
	
	for (k=0;k<T;k++)
	{
		bool flag = false;
		for (i=1;i<1048576;i++)
		{
			bitset<20> powerset(i);
			sum[i]=0;
			for (j=0;j<20;j++)
			{
				if (powerset[j]==true) {sum[i] = sum[i] + S[k][j];};
			}
			for (j=0;j<i;j++)
			{
			    if (sum[i]==sum[j]) {flag=true;};
				if (flag) {break;};
			}
			if (flag) {break;};
		}
		bitset<20> a(i);
		bitset<20> b(j);
		outfile << "Case #" << k+1 << ":" << endl;
		if (flag==false) {outfile << "Impossible" << endl;}
        else {
		for (j=0;j<20;j++)
		{
			if ((a[j]==true) && (b[j]==false)) {outfile << S[k][j] << ' ';};
		}
		outfile << endl;
		for (j=0;j<20;j++)
		{
			if ((b[j]==true) && (a[j]==false)) {outfile << S[k][j] << ' ';};
		}
		outfile << endl;
		}
	}
	    
    infile.close();
    outfile.close();
    return 0;   
}

