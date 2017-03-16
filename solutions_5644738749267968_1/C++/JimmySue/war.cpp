#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

int main()
{
	ifstream infile("D-large.in");
	ofstream outfile("large1.out");
	
	int t;
	infile	>> t;
	int n;
	vector<double> b1,b2;
	double tmp;
	int winDec,winHon;
	for (int i = 1 ; i < t+1; ++i)
	{
		infile >> n;
		for (int j = 0; j < n; j++)
		{
			infile >> tmp;
			b1.push_back(tmp);
		}
		for (int j = 0; j< n; j++)
		{
			infile >> tmp;
			b2.push_back(tmp);
		}
		sort(b1.begin(),b1.end());
		sort(b2.begin(),b2.end());

		winDec = winHon = 0;
		vector<double> ::reverse_iterator it1,it2;
		it1 = b1.rbegin();it2 = b2.rbegin();
		// decietful
		while (it2!= b2.rend())
		{
			if(*it1 > *it2)
			{
				winDec ++;
				it1++;
				it2++;
			}
			else if (*it1 < *it2)
			{
				it2++;
			}
			
		}
		// honest
		it1 = b1.rbegin();it2 = b2.rbegin();
		while(it1 != b1.rend())
		{
			if(*it1 > *it2)
			{
				winHon ++;
				it1++;
			}
			else if(*it1 < *it2)
			{
				it2++;
				it1++;
			}
		}
		b1.clear();
		b2.clear();
		outfile << "Case #" << i <<": " << winDec <<" " << winHon <<'\n';

	}
}