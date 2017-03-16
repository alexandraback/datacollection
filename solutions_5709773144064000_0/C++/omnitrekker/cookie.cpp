#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream>  
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

template <class T>
bool from_string(T& t, const std::string& s, std::ios_base& (*f)(std::ios_base&)) {
  std::istringstream iss(s);
  return !(iss >> f >> t).fail();
}

template <typename T>
string tostr(const T& t) { 
	ostringstream os; os<<t; 
	return os.str();
} 
/*
double calc_time(int farms, double farm_cost, double farm_cps, double goal) {
	double cps=2;
	double elapsed_time=0;
	for (int i=0; i<farms; i++) {
		elapsed_time += farm_cost / cps;
		cps += farm_cps;
	}
	elapsed_time += goal / cps;
	return elapsed_time;
}
*/

int _tmain(int argc, _TCHAR* argv[])
{
  string line,cell;
  vector<vector<string>> m;
  ifstream in ("B-small-attempt0.in");
  //ifstream in ("B-large-attempt0.in");
  //ifstream in ("sample.in");
  if (in.is_open())
  {
    while ( getline (in ,line) )
    {
        stringstream lineStream(line);
		vector<string> tmp;
        while( getline( lineStream, cell, ' ' ) ) {
			tmp.push_back(cell);
		}
		m.push_back(tmp);
    }
    in.close();
  }

  ofstream out;
  out.open("codejam.out");
  out.precision(7);

  int no_cases;
  from_string<int>(no_cases, m[0][0], std::dec);

  for (int c=0;c<no_cases;c++) {
	  out << "Case #" << c+1 << ": ";
	  double farm_cost, farm_cps, goal;
	  from_string<double>(farm_cost, m[c+1][0], std::dec);
	  from_string<double>(farm_cps, m[c+1][1], std::dec);
	  from_string<double>(goal, m[c+1][2], std::dec);
	  //out << "C: " << farm_cost << " F: " << farm_cps << " X: " << goal << "\n";
	  double cps=2;
	  double elapsed_time=0;
	  int buys=0;
	  bool buy=true;
	  while (buy) {
		double time_left = goal / cps;
		double time_left_buy = (goal + farm_cost) / (cps + farm_cps);
		if (time_left<time_left_buy) {
			buy=false;
			if (buys>0) {
				cps-=farm_cps;
				elapsed_time -= farm_cost / cps;
				time_left = goal / cps;
			}
			elapsed_time += time_left;
		} else {
			elapsed_time += farm_cost / cps;
			cps+=farm_cps;
			buys++;
		}
	  }
	  out << fixed << elapsed_time << "\n";
  }

  out.close();
  return 0;
}

