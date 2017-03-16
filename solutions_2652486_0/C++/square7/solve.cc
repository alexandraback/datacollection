#include <cmath>
#include <bitset>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>
#include <iomanip>
#include <ctime>

using namespace std;

bool okay(vector<int>& trail, vector<int>& num)
{
  for(int i = 0; i < num.size(); ++i)
    {
      int curr = num[i];
      if(curr == 1)
	{continue;}
      if(curr == trail[0])
	{continue;}
      if(curr == trail[1])
	{continue;}
      if(curr == trail[2])
	{continue;}
      if(curr == trail[0]*trail[1])
	{continue;}
      if(curr == trail[0]*trail[2])
	{continue;}
      if(curr == trail[1]*trail[2])
	{continue;}
      if(curr == trail[1]*trail[2]*trail[0])
	{continue;}
      return false;
    }
  return true;
}

int main()
{
  srand(time(0));
  int cnt;
  cin >> cnt;
  int R, N, M, K;
  cin >> R >> N >> M >> K;
  cout << "Case #1:" << endl;
  for(int i = 0; i < R; ++i)
    {
      vector<int> num;
      for(int j = 0; j < K; ++j)
	{
	  int temp;
	  cin >> temp;
	  num.push_back(temp);
	}     
      while(1)	
	{
	  vector<int> trail;
	  for(int j = 0; j < N; ++j)
	    {
	      trail.push_back(2+rand()%(M-1));
	    }
	  //for(int j = 0; j < N; ++j)
	    //	    {cout << trail[j] << " ";}
	    //cout << endl;
	  if(okay(trail, num))
	    {
	      for(int j = 0; j < trail.size(); ++j)
		{
		  cout << trail[j];
		}
	      cout << endl;
	      break;
	    }
	}

    }
}
