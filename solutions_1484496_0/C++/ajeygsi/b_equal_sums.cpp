#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cctype>
#include <cfloat>
#include <climits>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <map>
#include <set>


#define INF 1000000007
#define EPS (1e-8)
#define pb(a) push_back(a)
#define pf(a) push_front(a)
typedef long long LL;

int D[25];


using namespace std;


main()
{
  D[0] = 1<<0;
  D[1] = 1<<1;
  D[2] =  1<<2;
  D[3] =  1<<3;
  D[4] =  1<<4;
  D[5] =  1<<5;
  D[6] =  1<<6;
  D[7] =  1<<7;
  D[8] =  1<<8;
  D[9] =  1<<9;
  D[10]= 1<<10;
  D[11]= 1<<11;
  D[12]= 1<<12;
  D[13]= 1<<13;
  D[14]= 1<<14;
  D[15]= 1<<15;
  D[16]= 1<<16;
  D[17]= 1<<17;
  D[18]= 1<<18;
  D[19]= 1<<19;
  D[20]= 1<<20;
  
  int tests;
  scanf("%d",&tests);
  
  int num_ele = 20;
  for( int tc = 1 ; tc <= tests ; tc++ )
    {
      scanf("%d",&num_ele);
      vector<int> elements(20);
      for(int i = 0 ;i < num_ele; i++ )
	{
	  scanf("%d",&elements[i]);
	}
      
      map<int,int> sum_to_pos;
      bool impossible = true;
      int pos1,pos2;
      
      int last = 0;
      for( int i = 0;i < num_ele;i++)
	{
	  last = last + D[i];
	}
      
      for(int i = 1;i <= last;i++)
	{
	  int tsum = 0;
	  for(int j = 0;j < num_ele;j++)
	    {
	      if( ( i & D[j] ) )
		{
		  tsum = tsum + elements[j];
		}
	      
	    }
	  
	  if( sum_to_pos.count( tsum ) >  0 ) // found a match.
	    {
	      impossible = false;
	      pos1 = i;
	      pos2 = sum_to_pos[tsum];
	      break;
	    }
	  else
	    {
	      sum_to_pos[tsum] = i;
	    }
	}

      printf("Case #%d:\n",tc);
      if( impossible )
	{
	  printf("Impossible\n");
	}
      else
	{
	  
	  vector<int> sub1,sub2;
	  for(int i = 0;i < num_ele;i++)
	    {
	      if( pos1 & D[i] )
		{
		  sub1.pb( elements[i]);
		}
	    }

	  for(int i = 0;i < num_ele;i++)
	    {
	      if( pos2 & D[i] )
		{
		  sub2.pb( elements[i]);
		}
	    }
	  
	  for(int i = 0;i  < sub1.size();i++)
	    {
	      printf("%d",sub1[i]);
	      
	      if( i != ( sub1.size() - 1) )
		{
		  printf(" ");
		}
	      else
		{
		  printf("\n");
		}
	    }

	  for(int i = 0;i  < sub2.size();i++)
	    {
	      printf("%d",sub2[i]);
	      
	      if( i != ( sub2.size() - 1) )
		{
		  printf(" ");
		}
	      else
		{
		  printf("\n");
		}
	    }
	}
    }
}
