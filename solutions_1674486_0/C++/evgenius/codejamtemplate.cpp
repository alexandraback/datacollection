// codejamtemplate.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>  // I/O 
#include <fstream>   // file I/O
#include <iomanip>   // format manipulation
#include <ios>
#include <string>
#include <sstream>
#include <math.h>
#include <set>
#include <map>
#include <vector>

using namespace std;

template<typename RT, typename T, typename Trait, typename Alloc>
RT ss_atoi(const basic_string<T, Trait, Alloc>& the_string)
{
    basic_istringstream< T, Trait, Alloc> temp_ss(the_string);
    RT num;
    temp_ss >> num;
    return num;
}

int **mat;
int N;
bool good = false;

set<vector<int>> find(int i, vector<int> path)
{
	set<vector<int>> s;
	for (int j = 0; j < path.size(); j++)
	{
		if (path[j] == i)
			return s;
	}
	path.push_back(i);
		
	s.insert(path);
	for (int j = 0; j < N; j++)
	{
		if (mat[i][j])
		{
			vector<int> p(path);
			set<vector<int>> a = find(j, p);
			for (set<vector<int>>::iterator it = a.begin(); it != a.end(); it++)
			{
				s.insert(*it);
			}
		}
	}
	return s;
}

void FindPaths(int i)
{
	set<vector<int>> *s = new set<vector<int>>[N];
	for (int j = 0; j < N; j++)
	{
		vector<int> path;
		path.push_back(i);
		if (mat[i][j])
		{
			s[j] = find(j, path);
		}
	}
	
	for (int j = 0; j < N-1; j++)
	{
		for (set<vector<int>>::iterator it = s[j].begin(); it != s[j].end(); it++)
		{
			vector<int> v = *it;
			int ve = v[v.size()-1];
			for (int k = j+1; k < N; k++)
			{
				for (set<vector<int>>::iterator kt = s[k].begin(); kt != s[k].end(); kt++)
				{
					vector<int> p = *kt;
					int pe = p[p.size()-1];
					if (ve == pe)
					{
						good = true;
						return;
					}
				}
			}
		}
	}
}

void ProcessCase(int caseIndex, ifstream &inFile, ofstream &outFile)
{
	good = false;
	inFile >> N;

	mat = new int*[N];
	for (int i = 0; i < N; i++)
	{
		mat[i] = new int[N];
		for (int j = 0; j < N; j++)
			mat[i][j] = 0;
	}

	for (int i = 0; i < N; i++)
	{
		int m;
		inFile >> m;
		for (int j = 0; j < m; j++)
		{
			int k;
			inFile >> k;
			mat[i][k-1] = 1;
		}
		
	}


	for (int i = 0; i < N; i++)
	{
		FindPaths(i);
		if (good)
			break;
	}

	outFile << "Case #" << caseIndex << (good ? ": Yes" : ": No") << endl;

}


int _tmain(int argc, _TCHAR* argv[])
{
	ifstream inFile;
	ofstream outFile;
	
	inFile.open("A-small-attempt1.in", ios::in);
	outFile.open("A-small.out", ios::out);

	//inFile.open("A-large.in", ios::in);    // open the streams
	//outFile.open("A-large.out", ios::out);

	int N; // the number of cases
	inFile >> N;
	for (int i = 0; i < N; i++)
	{
		ProcessCase(i + 1, inFile, outFile);
	}
	inFile.close();   // close the streams
	outFile.close(); 

	return 0;
}
