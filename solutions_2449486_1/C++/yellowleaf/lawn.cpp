#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <deque>
#include <algorithm>
#include <stack>
#include <cmath>

using namespace std;
//#define DEBUG

const int BUFSIZE = 2 * 1024 * 1024;

string  processOneCase(ifstream &ifs)
{
	int rows, cols;
	char buf[BUFSIZE];
	ifs.getline(buf, BUFSIZE);
	istringstream iss(buf);
	iss >> rows >> cols;
//	cout << rows << " " << cols << endl;

	vector<vector<int> > matrix(rows, vector<int>(cols));
	for (int row = 0; row < rows; row++)
	{
		ifs.getline(buf, BUFSIZE);
		istringstream iss(buf);
		for (int col = 0; col < cols; col++)
		{
			int val;
			iss >> val;
			matrix[row][col] = val;
		}
	}

#if 0
	for (int row = 0; row < rows; row++)
	{
		for (int col = 0; col < cols; col++)
		{
			cout << matrix[row][col] << ' ';
		}
		cout << endl;
	}
#endif

	vector<int> rowMax(rows, INT_MIN);
	vector<int> colMax(cols, INT_MIN);

	for (int row = 0; row < rows; row++)
	{
		for (int col = 0; col < cols; col++)
		{
			rowMax[row] = max(rowMax[row], matrix[row][col]);
			colMax[col] = max(colMax[col], matrix[row][col]);
		}
	}

	for (int row = 0; row < rows; row++)
	{
		for (int col = 0; col < cols; col++)
		{
			if (matrix[row][col] < rowMax[row] && matrix[row][col] < colMax[col])
			{
				return "NO";
			}
		}
	}

	return "YES";

}

int main(int argc, char *argv[])
{
	ifstream ifs(argv[1]);
	char buf[BUFSIZE];
	ifs.getline(buf, BUFSIZE);
	int lines = atoi(buf);

	for (int i = 0; i < lines; i++)
	{   
		string result = processOneCase(ifs); 
		cout << "Case #" << (i+1) << ": " << result  << endl;
	}   
	return 0;
}
