#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

bool check_lawn(vector<vector<int> > &lawn)
{
	int n=lawn.size();
	int m=lawn[0].size();
	int i, j, count_valid=0;
	vector<vector<bool> > isValid(n, vector<bool>(m));
	for (i=0; i<n; i++)
		for (j=0; j<m; j++)
			isValid[i][j] = false;
	// check rows
	for (i=0; i<n; i++)
	{
		int row_max = 0;
		for (j=0; j<m; j++)	// find row max
			row_max = max(row_max, lawn[i][j]);
		for (j=0; j<m; j++)	// those equal to row_max  are already valid
		{
			if (lawn[i][j]==row_max)
			{
				isValid[i][j] = true;
				count_valid++;
			}
		}
	}
	// check columns
	for (j=0; j<m; j++)
	{
		int col_max = 0;
		for (i=0; i<n; i++)
			col_max = max(col_max, lawn[i][j]);
		for (i=0; i<n; i++)
		{
			if (!isValid[i][j] && lawn[i][j]==col_max)
			{
				isValid[i][j] = true;
				count_valid++;
			}
		}
	}
	return (count_valid==n*m);
}

int main()
{
	ifstream inFile;
	inFile.open("B-large.in");
	ofstream outFile;
	outFile.open("B_large.out");
	int nCases, n, m, i, j, k, num;
	vector<vector<int> > lawn;
	vector<int> temp;
	inFile >> nCases;
	inFile.ignore(10,'\n');	
	for (k=0; k<nCases; k++)
	{	// input the current lawn
		inFile >> n >> m;
		inFile.ignore(10,'\n');
		lawn.clear();
		for (i=0; i<n; i++)
		{
			temp.clear();
			for (j=0; j<m; j++)
			{
				inFile >> num;
				temp.push_back(num);
			}
			lawn.push_back(temp);
			inFile.ignore(10,'\n');
		}
		// check the current lawn and output
		outFile << "Case #" << k+1 << ": ";
		if (check_lawn(lawn))		outFile << "YES" << endl;
		else								outFile << "NO" << endl;
	}

	inFile.close();
	outFile.close();

	return 1;
}