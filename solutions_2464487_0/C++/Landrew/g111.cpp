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
     long long r, t;
	 fin >> r >> t;
     long long a = 2*r+1; 

	 if (2*r + 1 + 2*r + 5 > t)
	 {
	    fout << "Case #" << tt+1 << ": " << "1" << endl;
		continue;
	 }

	 long long lob = 1;
	 long long upb = 1;
	 while (2*upb*upb <= t && (2*r+1)*(upb+1) <= t)
        upb = upb*2;

	 while (upb - lob > 5)
	 {
        long long med = (lob + upb)/2;
		if (a*(med+1) + 2*med*(1+med) > t)
			upb = med;
		else
			lob = med;
	 }

	 bool ok = true;
	 long long best = lob;
	 for (long long ii=lob; ii<=upb && ok; ii++)
	 {
         if (a*(ii+1) + 2*ii*(1+ii) <= t)
			 best = ii;
		 else
			 ok = false;
	 }

	 //long long res = a*(best+1)+2*best*(1+best);
     fout << "Case #" << tt+1 << ": " << (best+1) << endl;
  }

   return 0;
}

