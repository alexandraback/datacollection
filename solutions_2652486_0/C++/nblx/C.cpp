#include <iostream>
#include <iomanip>		// setprecision
#include <fstream>
#include <vector>
#include <queue>
#include <stack>
#include <map>			// map, unordered_map
#include <set>			// set, unordered_set
#include <algorithm>	// sort, stable_sort
#include <cstdlib>		// atoi, atof, etc.
using namespace std;


vector<int> solve(const vector<int> &prod, int K)
{
	vector<int> result(3,2);
	int count=0, i;
	int count5=0;
	for (i=0; i<K; i++)
	{
		if (prod[i]%25==0)
		{
			count5=2;
			break;
		} else if (prod[i]%5==0)
			count5=1;
	}
	int count3=0;
	for (i=0; i<K; i++)
	{
		if (prod[i]%9==0)
		{
			count3=2;
			break;
		} else if (prod[i]%3==0)
			count3=1;
	}
	int count2=0;
	for (i=0; i<K; i++)
	{
		if (prod[i]%8==0)
		{
			count2=3;
			break;
		} else if (prod[i]%4==0)
			count2=2;
		else if (prod[i]%2==0)
			count2=1;
	}
	for (i=0; i<count5; i++)
		result[count++]=5;
	for (i=0; i<count3; i++)
		result[count++]=3;
	if (count==1 && count2==3)
	{
		result[1]=4;
		result[2]=2;
	} else if (count==2 && count2==2)
		result[2]=4;
	else
	{
		for ( ; count<3; count++)
			result[count]=2;
	}
	return result;
}

int main()
{
	ifstream infile;
	infile.open("C-small-1-attempt0.in");
	ofstream outfile;
	outfile.open("small.out");
	int nCases;
	infile >> nCases;
	infile.ignore(10,'\n');
	for (int t=1; t<=nCases; t++)
	{
		int R, N, M, K;
		infile >> R >> N >> M >> K;
		infile.ignore(10,'\n');
		outfile << "Case #" << t << ":\n";
		for (int i=0; i<R; i++)
		{
			vector<int> prod(K);
			for (int j=0; j<K; j++)
				infile >> prod[j];
			infile.ignore(10,'\n');
			vector<int> result = solve(prod, K);
			for (int j=0; j<N; j++)
				outfile << result[j];
			outfile << endl;
		}
		cout << "Case #" << t << " solved!\n";
	}
	infile.close();
	outfile.close();
	char c;
	cin >> c;
	return 0;
}