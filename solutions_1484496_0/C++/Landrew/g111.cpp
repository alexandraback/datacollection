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
ifstream fin ("INP111.txt");

//FILE* pFile;
//int c;
//pFile = fopen("ou.txt","w");
//pFile=fopen ("beads.txt","r");

int main() {

//FILE* pFile;
//pFile = fopen("ou.txt","w");

// string na;
// if (tt == 0)
//  getline(fin,na);

// getline(fin,na);

// istringstream sin(na); 
// string v; 
// while (sin>>v) 
//   names.push_back(v); 

//fprintf(pFile, "Case #%d: ", t+1);
//fprintf(pFile,"%d\n",res);

  int TT;
  fin >> TT;

  for (int tt=0; tt<TT; tt++)
  {
     int vals[21];
	 memset(vals, 0, sizeof(vals));

	 int n;
	 fin >> n;
	 for (int i=0; i<n; i++)
	 {
        fin >> vals[i];
	 }

	 map <int, long long> M;
	 M.clear();

	 bool found = false;
	 long long a, b;
	 long long up = 1 << 20;
	 for (long long t=0; t < up && !found; t++)
	 {
        int cursum = 0; 
        int ind = 0;
		long long curm = 1;
        while (ind < 20)
		{
           if ( (t & curm) > 0)
			   cursum += vals[ind];
		   ind++;
		   curm = 2*curm;
		}

		if (M.find(cursum) != M.end())
		{
           found = true;
		   a=t;
		   b=M[cursum];
		}
		else
		{
           M[cursum]=t;
		}
	 }

     double res=0;
	 fout.precision(9);
	 fout.setf(ios::fixed, ios::floatfield);
	 //fout << "Case #" << tt+1 << ": " << res << endl;
	 if (!found)
        fout << "Case #" << tt+1 << ": " << "Impossible" << endl;
	 else
	 {
        fout << "Case #" << tt+1 << ":" << endl;

		int ind = 0;
		long long curm = 1; 
        while (ind < 20)
		{
			if ( (a & curm) > 0)
		    {
			   fout << vals[ind];
			   if (ind != 19)
				   fout << " ";
			}
		   ind++;
		   curm = 2*curm;
		}
		fout << endl;

		ind = 0;
		curm = 1; 
        while (ind < 20)
		{
			if ( (b & curm) > 0)
		    {
			   fout << vals[ind];
			   if (ind != 19)
				   fout << " ";
			}
		   ind++;
		   curm = 2*curm;
		}
		fout << endl;
         
        // fout << "Case #" << tt+1 << ": " << res << endl;
	 }
  }

   return 0;
}
