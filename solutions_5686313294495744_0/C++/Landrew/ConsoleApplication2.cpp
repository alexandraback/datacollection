#include "stdafx.h"
#include <fstream>
#include <string>
#include <cstdlib>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <queue>
#include <stdio.h>

#include <math.h>

using namespace std;

ofstream fout("OUT111.txt");
ifstream fin("INP111.txt");

//prewritten template
template< typename tPair >
struct first_t {
	typename tPair::first_type operator()(const tPair& p) const { return     p.first; }
};

template< typename tMap >
first_t< typename tMap::value_type > first(const tMap& m) { return first_t<     typename tMap::value_type >(); }


int main() 
{
	int TT;
	fin >> TT;

	for (int tt = 0; tt < TT; tt++)
	{
		int N;
		fin >> N;
		vector <string> fir, sec;
		for (int i = 0; i < N; i++)
		{
			string a, b;
			fin >> a >> b;
			fir.push_back(a);
			sec.push_back(b);
		}

		typedef map <string, int> MM;
		MM M1, M2;
		for (int i = 0; i < N; i++)
		{
			M1[fir[i]] = 1;
			M2[sec[i]] = 1;
		}

		vector <string> V1, V2;

		std::transform(M1.begin(), M1.end(), std::back_inserter(V1), first(M1));
		std::transform(M2.begin(), M2.end(), std::back_inserter(V2), first(M2));

		//for (MM::iterator it = M1.begin(); it != M1.end(); ++it)
		//	V1.push_back(it->first());

		//for (MM::iterator it = M2.begin(); it != M2.end(); ++it)
		//	V2.push_back(it->first());

		vector <vector<int> > VV1, VV2;

		for (int i = 0; i < V1.size(); i++)
		{
			vector <int> VT;
			for (int j = 0; j < N; j++)
			{
				if (fir[j] == V1[i])
					VT.push_back(j);
			}
			VV1.push_back(VT);
		}

		for (int i = 0; i < V2.size(); i++)
		{
			vector <int> VT;
			for (int j = 0; j < N; j++)
			{
				if (sec[j] == V2[i])
					VT.push_back(j);
			}
			VV2.push_back(VT);
		}


		int bes = 0;

		int up = 1 << N;

		for (int mas = 0; mas < up; mas++)
		{
			bool ok = true;
			for (int i = 0; i < V1.size() && ok; i++)
			{
				bool found = false;
				for (int j = 0; j < VV1[i].size() && !found; j++)
				{
					int sh = 1 << VV1[i][j];
					if ((mas & sh) == 0)
						found = true;
				}
				if (!found)
					ok = false;
			}

			for (int i = 0; i < V2.size() && ok; i++)
			{
				bool found = false;
				for (int j = 0; j < VV2[i].size() && !found; j++)
				{
					int sh = 1 << VV2[i][j];
					if ((mas & sh) == 0)
						found = true;
				}
				if (!found)
					ok = false;
			}

			if (!ok)
				continue;

			int loc = 0;
			for (int i = 0; i < N; i++)
			{
				int sh = 1 << i;
				if ((mas & sh) == 0)
				{
					loc++;
				}
			}

			if ((N-loc) > bes)
				bes = N-loc;
		}

	    fout << "Case #" << tt + 1 << ": " << bes << "\n";
	}

	return 0;
}

