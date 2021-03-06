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

  int n;

  double tol = 0.0000001;

  for (int tt=0; tt<TT; tt++)
  {
     //double sco[201];
	 double curval[201];
     //memset(sco, 0, sizeof(sco);
	 memset(curval, 0, sizeof(curval));
	 vector <pair <int, int> > vsco;
	 vector <int> intval;
	 map <int, int> M;
	 fin >> n;
	 double tot=0;
	 for (int i=0; i<n; i++)
	 {
		 int t;
		 fin >> t;
		 //sco[i]=t;
		 tot += t;
		 pair<int, int> p;
		 p.first = t;
		 p.second = i;
		 vsco.push_back(p);
		 intval.push_back(t);
		 M[t]++;
	 }

	 sort(vsco.begin(), vsco.end());
     sort(intval.begin(), intval.end());
	 vector <int> perm;
	 for (int i=0; i<n; i++)
	 {
        pair <int, int> p = vsco[i];
		perm.push_back(p.second);
	 }

	 bool done = false;
	 int curnum = M[intval[0]];
     double totrem = tot;
	 int curind = 0;
	 int curlev = intval[0]; 
	 while (!done)
	 {
        double dcurnum = curnum;
        if (curnum == n)
		{
           double del = totrem/dcurnum;
           for (int i=0; i<n; i++)
			   curval[i] += del;

		   done = true;
		}
		else
		{
           int nextind = curind;
		   while (intval[nextind] == intval[curind])
			   nextind++;
		   double nextlev = intval[nextind];
           double diff = nextlev - curlev;
		   double gaparea  = diff*dcurnum;
		   if (totrem > gaparea + tol)
		   {
              for (int i=0; i<curnum; i++)
				  curval[perm[i]] += diff;

			  totrem -= gaparea;
			  curind = nextind;
			  curnum += M[intval[curind]];
			  curlev = intval[curind];
		   }
		   else
		   {
              double del = totrem/dcurnum;
              for (int i=0; i<curnum; i++)
				  curval[perm[i]] += del;

              done = true;
		   }
		}
	 }

	 for (int i=0; i<n ; i++)
	 {
		 curval[i] = curval[i]/tot;
		 curval[i] = 100*curval[i]; 
	 }

	 fout.precision(9);
	 fout.setf(ios::fixed, ios::floatfield);
     //fout << "Case #" << tt+1 << ": " << res << endl;
	 fout << "Case #" << tt+1 << ": ";
	 for (int i=0; i<n-1; i++)
		 fout << curval[i] << " ";
	 fout << curval[n-1] << endl;
  }

   return 0;
}
