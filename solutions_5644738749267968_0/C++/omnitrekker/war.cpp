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
  ifstream in ("D-small-attempt0.in");
  //ifstream in ("D-large.in");
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
	  int stones;
	  from_string<int>(stones, m[1+c*3][0], std::dec);
	  vector<double> naomi, ken, naomi2, ken2;
	  for (int i=0;i<stones;i++) {
		double tmp_naomi, tmp_ken;
		from_string<double>(tmp_naomi, m[2+c*3][i], std::dec);
		naomi.push_back(tmp_naomi);
		naomi2.push_back(tmp_naomi);
		from_string<double>(tmp_ken, m[3+c*3][i], std::dec);
		ken.push_back(tmp_ken);
		ken2.push_back(tmp_ken);
	  }
	  sort(naomi.begin(), naomi.end());
	  sort(ken.begin(), ken.end());
	  sort(naomi2.begin(), naomi2.end());
	  sort(ken2.begin(), ken2.end());
	  
	  int war_wins=0;
	  //war
	  for (int i=0;i<stones;i++) {
		  
		  /*
		  out << "\nnaomi: ";
		  for (int k=0;k<naomi.size();k++) out << naomi[k] << " ";
		  out << "\nken: ";
		  for (int k=0;k<ken.size();k++) out << ken[k] << " ";
		  */

		  double naomis_stone=naomi.front();
		  naomi.erase(naomi.begin());
		  
		  if (ken.back()>naomis_stone) {
			  //ken can win, find lightest stone that wins
			  int j=0;
			  while (ken[j]<naomis_stone) j++;
			  ken.erase(ken.begin()+j);
		  } else {
			  //ken can't win, remove lightest stone
			  ken.erase(ken.begin());
			  war_wins++;
		  }
	  }
	  int dwar_wins=0;
	  //dwar
	  for (int i=0;i<stones;i++) {
		  
		  /*
		  out << "\nnaomi: ";
		  for (int k=0;k<naomi2.size();k++) out << naomi2[k] << " ";
		  out << "\nken: ";
		  for (int k=0;k<ken2.size();k++) out << ken2[k] << " ";
		  */

		  if (naomi2.back()>ken2.front()) {
			//naomi can win - find a stone that is heavier than ken's lightest
			  int j=0;
			  while (naomi2[j]<ken2.front()) j++;
			  naomi2.erase(naomi2.begin()+j);
			  ken2.erase(ken2.begin());
			  dwar_wins++;
		  } else {
		    //naomi can't win any of the following rounds
		  }
	  }

	  out << dwar_wins << " " << war_wins << "\n";
	  //dwar
  }

  out.close();
  return 0;
}

