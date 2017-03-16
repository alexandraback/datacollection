#include <stdio.h>
#include <sstream>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <list>
#include <iomanip>
#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <cassert>
#include <string.h>
#include "windows.h"
using namespace std;
#pragma comment(linker, "/STACK:20000000")

typedef vector<int> vi; 
#define sz(a) int((a).size()) 
#define all(c) (c).begin(),(c).end() 

string problem_name = "A-small-attempt0(4)";

void init(){
  freopen((problem_name+".in").c_str(),"rt",stdin);
  freopen((problem_name+".out").c_str(),"wt",stdout);
}




int main()
{
   init();


	
	
   int tst;
   //scanf("%d",&tst);
   cin >> tst;

   for (int cas = 1; cas<=tst;cas++)
   {
	   int res = 0;

	   int r,c,w;

	   cin >> r >> c >> w;

	   int t = c;

	   while (t>2*w-1)
	   {
			t-=w;
			res++;
	   }
	   
	   res+=(res+1)*(r-1);

	   if (t>w) res+=w+1; else
		   res+=w;
   
	   printf("Case #%d: %d\n",cas,res);	
   }
	





	
  return 0;
}

