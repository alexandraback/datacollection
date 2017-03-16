#include "graaf.h"

#include <iostream>
#include <fstream>

#include <vector>
#include <map>
#include <queue>
#include <string>
#include <cassert>
#include <algorithm>

#include <iomanip>

using namespace std;


ofstream out;
ifstream in;

void init()
{
	in.open ("A-small-attempt0.in");
	assert(!in.fail());
	out.open("out.txt");
	assert(!out.fail());
}

void close()
{
	in.close();
	out.close();
}

string readLine()
{
	string s;
	getline(in, s);
	return s;
}

int readNumber()
{
	int i;
	in >> i;
	string s;
	getline(in, s);
	return i;
}

char readChar()
{
	char c;
	in >> c;
	string s;
	getline(in, s);
	return c;
}

typedef std::map<int, int>  Knoop;


bool dez(Graaf<RichtType::GERICHT> &g, vector<bool> &gezien, int k)
{
	Knoop kn = g[k];
	for (Knoop::iterator it = kn.begin(); it != kn.end(); it++)
	{
		if (gezien[it->first])
			return true;
		else
		{
			gezien[it->first] = true;
			bool ret = dez(g, gezien, it->first);
			if (ret)
				return ret;
		}
	}
	return false;
}

int main()
{
	init();
	int cases = readNumber();
	
	for (int casenr = 1; casenr <= cases; casenr++)
	{
		int classes = readNumber();
		Graaf<RichtType::GERICHT> g;
		for (int i = 0; i < classes; i++)
			g.voegKnoopToe();
		

		


		for (int i = 0; i < classes; i++)
		{
			int nrs;
			in >> nrs;
			for (int j = 0; j < nrs; j++)
			{
				int naar;
				in >> naar;
				g.voegVerbindingToe(i, naar - 1);
			}

		}

		int k = 0;
		bool bezig = false;
		while (!bezig && k < classes)
		{
			std::vector<bool> gezien(classes, false);
			bezig = dez(g, gezien, k);
			k++;
		}
		//Dez. 
		out << "Case #" << casenr<< ": " << (bezig  ? "Yes" : "No" ) << endl;
	}

	close();
	std::cout << "Finished (A)" << endl;
	cin.get();
	return 0;
}