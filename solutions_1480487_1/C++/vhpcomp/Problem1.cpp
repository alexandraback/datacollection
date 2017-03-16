#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;

vector<double> getMinPer(vector<int> scores)
{
	double X = 0;
	for (int i=0; i < scores.size(); i++)
       X += double(scores[i]);
	int size = scores.size();
	
	double total = 2.0 * X;
	double ave = 2.0 * X / size;
	int count = scores.size();
	for (int i=0; i < scores.size(); i++)
	{
		if ((double) (scores[i]) > ave)
		{
			total = total - scores[i];
			count = count - 1;
		}
		
	}
	
	vector<double> res; 
	for (int i=0; i < scores.size(); i++)
	{
		if (scores[i] > ave)
			res.push_back(0.0);
		else {
			double percent = ((total/count) - scores[i]) / X;
			res.push_back(percent);
		}
	}
	return res;
}

int main()
{
    //ifstream infile("A-small-attempt1.in");
	ifstream infile("A-large.in");
	ofstream outfile("result.txt");
	string str;
	getline(infile, str);
    istringstream buffer(str);
    int testCase = 0;
    buffer >> testCase;

    for (int k=0; k < testCase; k++)
	{
		getline(infile, str);
		istringstream buffer1(str);
		
		int level = 0;
		buffer1 >> level;
		vector<int> scores;
		
		for (int i=0; i < level; i++)
		{
			int sco = 0;
			buffer1 >> sco;
			scores.push_back(sco);
		}
		vector<double> res = getMinPer(scores);
		outfile << "Case #" << k+1 << ": ";
		
		for (int i=0; i < res.size(); i++)
		   outfile << setiosflags(ios::fixed) << setprecision(6) << res[i] * 100 << " ";
		outfile << endl;
		res.clear();
		scores.clear();
	}
}