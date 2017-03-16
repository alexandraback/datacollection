#include <iostream>
#include <fstream>
#include <set>
#include <string>

using namespace std;

int war(set<double>, set<double>);

int main()
{
	ifstream fin("D-small-attempt0.in");
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
		int num = 0;
		getline(fin, s);
		set<double> a,b;
		num = atoi(s.c_str());
		for(int i = 0; i < num; i++)
		{
			fin >> ch;
			f = atof(ch);
			//printf("%.2f\n", f);
			a.insert(f);
		}
		getline(fin,s);
		for(int i = 0; i < num; i++)
		{
			fin >> ch;
			f = atof(ch);
			//printf("%.2f\n", f);
			b.insert(f);
		}
		getline(fin,s);
		int res1 = war(a,b);
		int res2 = war(b,a);
		fout << "Case #" << k+1 << ": ";
		fout << res1 << " " <<  num - res2 << endl;
	}
	//system("pause");
	fin.close();
	fout.close();
	return 0;
}

int war(set<double> a, set<double> b)
{
	int res = 0;
	set<double>::reverse_iterator ita = a.rbegin();
	set<double>::reverse_iterator itb = b.rbegin();
	while(ita != a.rend() && itb != b.rend())
	{
		if(*ita > *itb)
		{
			ita++;
			itb++;
			res++;
		}
		else
		{
			itb++;
		}
	}
	return res;
}