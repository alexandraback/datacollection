#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <cstring>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>
#define BSIZE 1<<15
using namespace std;
char buffer[BSIZE];
long bpos = 0L, bsize = 0L;
long readLong() 
{
	long d = 0L, x = 0L;
	char c;
	while (1)  {
		if (bpos >= bsize) {
			bpos = 0;
			if (feof(stdin)) return x;
			bsize = fread(buffer, 1, BSIZE, stdin);
		}
		c = buffer[bpos++];
		if (c >= '0' && c <= '9') { x = x*10 + (c-'0'); d = 1; }
		else if (d == 1) return x;
	}
	return -1;
}

void solver()
{
  double C,F,X,R,time;
  scanf("%lf %lf %lf",&C,&F,&X);
  time=0;
  R=2.0;
  while( (X/R) > ( (C/R) + (X/(R+F)) ) )
  {
    time+=C/R;
    R+=F;
  }
  time+=X/R;
  printf("%.7lf\n",time);
}

int main()
{
  int testcases;//=readLong();
  cin>>testcases;
  for(int i=0;i<testcases;i++)
  {
    printf("Case #%d: ",i+1);
    solver();
  }
  return 0;
}
