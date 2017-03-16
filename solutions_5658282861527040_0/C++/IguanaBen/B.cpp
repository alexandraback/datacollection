#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>

#define type long long

using namespace std;


int main()
{

  cin.tie(NULL);
  std::ios::sync_with_stdio(false);

  int T;
  cin>>T;
  int t=0;
  while(t<T)
  {
  	int a,b,k;
  	cin>>a>>b>>k;
  	int ctr = 0;
  	for(int i=0; i<a; i++)
  		for(int j=0; j<b; j++)
  			if( (i & j) < k ) ctr++;

	cout <<"Case #"<<t+1<<": "<<ctr<<"\n";

	t++;

  }

  return 0;
 
}