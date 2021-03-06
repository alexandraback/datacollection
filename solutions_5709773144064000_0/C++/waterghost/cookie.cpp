#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

double cookie(vector<double>, int);
double farmcost(double c, double f, int n);

int main()
{
	ifstream fin("B-small-attempt0.in");
	ofstream fout("res.txt");
	if(!fin.is_open() || !fout.is_open())
	{
		cout << "file error\n";
		return 0;
	}
	int T;
	string s;
	getline(fin, s);
	T = atoi(s.c_str());
	char ch[255];
	double f;

	for(int k = 0; k < T; k++)
	{
		vector<double> dat;
		for(int i = 0; i < 3; i++)
		{
			fin >> ch;
			f = atof(ch);
			//printf("%.2f\n", f);
			dat.push_back(f);
		}
		double res = cookie(dat, 0);
		fout << "Case #" << k+1 << ": ";
		fout << setiosflags(ios::fixed);
		fout.precision(7);
		fout << res << endl;
		getline(fin, s);
	}
	system("pause");
	fin.close();
	fout.close();
	return 0;
}

double cookie(vector<double> dat, int n)
{
	double res = 0;
	vector<double>::iterator it = dat.begin();
	double c = *it++;
	double f = *it++;
	double x = *it++;

	double no_buy = x / (f * n + 2);
	double buy_one = x / (f * n + f + 2) + c / (f * n + 2);
	if(no_buy < buy_one)
	{
		return no_buy + farmcost(c, f, n);
	}
	else
	{
		return cookie(dat, n+1);
	}

}

double farmcost(double c, double f, int n)
{
	double res = 0;
	if(n <= 0)
		return res;
	for(int i = 0; i < n; i++)
	{
		res += c / (2 + f * i);
	}
	return res;
}