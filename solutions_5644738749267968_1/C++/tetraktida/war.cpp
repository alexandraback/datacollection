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
  //cout<<endl;
  int blocks;
  cin>>blocks;
  vector<double> naomi(blocks),kein(blocks);
  for(int i=0;i<blocks;i++) cin>>naomi[i];
  for(int i=0;i<blocks;i++) cin>>kein[i];
  sort(naomi.begin(),naomi.end());
  sort(kein.begin(),kein.end());
  //for(int i=0;i<blocks;i++) cout<<naomi[i]<<" ";  cout<<endl;
  //for(int i=0;i<blocks;i++) cout<<kein[i]<<" ";  cout<<endl;
  int war,dwar,i,j;
  int endkein=blocks-1;
  dwar = blocks;
  while(naomi[blocks-1]<kein[endkein])
  {
    dwar--;
    endkein--;
    if(endkein<0) break;
  }

  i = blocks -1 - endkein;
  j = 0;
  while(j<=endkein)
  {
    if(naomi[i]>kein[j]) j++;
    else  dwar--;
    i++;
    if(i==blocks) break;
  }

  printf("%d ",dwar);
  war=i=j=0;
  // i naomi | j kein
  while(j<blocks)
  {
    if(naomi[i]>kein[j]) war++;
    else i++;
    j++;
  }
  printf("%d\n",war);
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
