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

int n, m;
int boxtypes[4];
long long boxnum[4];
int toytypes[102];
long long toynum[102];

long long solve3(int ind, long long toyreminp)
{
    if (n!=3)
	  return 0;

	long long curbox = 0;
	for (int i=ind; i<m; i++)
	{
        long long toyrem = toynum[i];
		if (i == ind)
			toyrem = toyreminp;
        if (boxtypes[2] == toytypes[i])
		{       
           curbox = min(boxnum[2], curbox + toyrem);
		}
	}

	return (curbox);
}

long long solve2(int ind, long long toyreminp)
{
    if (n == 1)
	  return 0;

    long long best = 0;

	long long curbox = 0;
	long long rembox = boxnum[1];
    for (int i=ind; i<m; i++)
	{
        long long toyrem = toynum[i];
		if (i == ind)
			toyrem = toyreminp;
		long long add = 0;
        if (boxtypes[1] == toytypes[i])
		{
           add = min(rembox, toyrem);
		}  
        best = max(best, curbox + add + solve3(i, toyrem - add));
        if (boxtypes[1] == toytypes[i])
		{
           curbox = min(boxnum[1], curbox + toyrem);
		   rembox = boxnum[1] - curbox;
		}
	}

	return best;
}

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

	 fin >> n >> m;
	 for (int i=0; i<n; i++)
	 {
		fin >> boxnum[i];
        fin >> boxtypes[i];
	 }

	 for (int i=0; i<m; i++)
	 {
		fin >> toynum[i];
        fin >> toytypes[i];
	 }

     long long curbox = 0;
	 long long rembox = boxnum[0];
	 long long best = 0;
	 for (int i=0; i<m; i++)
	 {
        long long toyrem = toynum[i];
		long long add = 0;
        if (boxtypes[0] == toytypes[i])
		{
           add = min(rembox, toynum[i]);
		}
        best = max(best, curbox + add + solve2(i, toyrem - add));
        if (boxtypes[0] == toytypes[i])
		{
           curbox = min(boxnum[0], curbox + toynum[i]);
		   rembox = boxnum[0] - curbox;
		}
	 }

     //double res=0;
	 //fout.precision(9);
	 //fout.setf(ios::fixed, ios::floatfield);
	 fout << "Case #" << tt+1 << ": " << best << endl;
  }

   return 0;
}
