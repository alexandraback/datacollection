// code_jam_practice.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iomanip>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

template<typename T>
ostream& operator<<(ostream& str, const vector<T> &v)
{
	str << "[";
	for (int i = 0; i < v.size(); i++)
	{
		str << v.at(i) << ", ";
	}
	str << "]";
	return str;
}

template<typename T>
ostream& operator<<(ostream& str, const vector<pair<T,T>> &v)
{
	str << "[";
	for (int i = 0; i < v.size(); i++)
	{
		str << v.at(i).first << "-" << v.at(i).second << ", ";
	}
	str << "]";
	return str;
}

int simulate_war(vector<double> naomi, vector<double> ken)
{
	sort(naomi.begin(), naomi.end());
	sort(ken.begin(), ken.end());

	int count = 0;
	while(!naomi.empty())
	{
		double nao = naomi.at(0);
		naomi.erase(naomi.begin());
		
		vector<double>::iterator it = lower_bound(ken.begin(), ken.end(), nao);

		if (it == ken.end())
		{
			ken.erase(ken.begin());
			count++;
		} else {
			ken.erase(it);
		}
	}
	return count;
}

int simulate_dec_war(vector<double> naomi, vector<double> ken)
{
	sort(naomi.begin(), naomi.end());
	sort(ken.begin(), ken.end());

	int count = 0;
	while(!naomi.empty())
	{
		double nao = *naomi.begin();

		if (nao > *ken.begin())
		{
			count++;
			naomi.erase(naomi.begin());
			ken.erase(ken.begin());
		} else {
			if (nao > ken.back())
			{
				return count+naomi.size();
			} else {
				naomi.erase(naomi.begin());
				ken.pop_back();
			}
		}
	}
	return count;
}


int _tmain(int argc, _TCHAR* argv[])
{
	int T;
	ifstream ifs("D-small-0.in", ifstream::in);
	ofstream ofs("D-small-0.out", ifstream::out);
	ifs >> T;
	for (int i = 0; i < T; i++)
	{
		vector<double> naomi;
		vector<double> ken;

		int count;
		ifs >> count;

		for (int i = 0; i < count; i++)
		{
			double temp;
			ifs >> temp;
			naomi.push_back(temp);
		}

		for (int i = 0; i < count; i++)
		{
			double temp;
			ifs >> temp;
			ken.push_back(temp);
		}



		ofs << "Case #" << i+1<< ": " <<  simulate_dec_war(naomi, ken) <<" " << simulate_war(naomi, ken)<< endl;
	}
	system("pause");
	return 0;
}

