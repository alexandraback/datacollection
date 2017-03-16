#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <fstream>

#define ALL(c) (c).begin(), (c).end()
#define SORT(c) sort(ALL(c))

typedef long long LL;

bool aFactorOf(int num, vector<int>& vect)
{
  for(int i = 0; i < vect.size(); i++)
  {
    if(vect[i] > 1 && (vect[i] % num == 0))
    {
      return true;
    }
  }
  return false;
}

void reduce(int num, vector<int>& vect)
{
  for(int i = 0; i < vect.size(); i++)
  {
    if(vect[i] > 1 && (vect[i] % num == 0))
    {
      vect[i] /= num;
    }
  }
  return;
}

bool done(vector<int>& vect)
{
  for(int i = 0; i < vect.size(); i++)
  {
    if(vect[i] != 1)
    {
      return false;
    }
  }
  return true;
}
using namespace std;

int main()
{
  ifstream in;
  in.open("C-small-1-attempt0.in");
  ofstream out;
  out.open("output.txt");
  // Number of Test cases
  int T;
  int R, N, M, K, temp;
  vector<int> v, possibles, test;
  // Set test cases (first input)
  in >> T;


  // cycle through the test cases
  for(int t = 1; t <= T; t++)
  {
    in >> R >> N >> M >> K;
    out << "Case #" << t << ":" << endl;
    for(int i = 0; i < R; i++)
    {
      for(int j = 0; j < K; j++)
      {
        in >> temp;
        v.push_back(temp);
      }

      for(int j = 2; j <= M; j++)
      {
        if(aFactorOf(j, v))
        {
          possibles.push_back(j);
        }
      }
      if(possibles.size() == 0)
      {
        out << "222" << endl;
      }
      else
      {
        for(int j = 0; j < possibles.size(); j++)
        {
          for(int k = 0; k < possibles.size(); k++)
          {
            for(int l = 0; l < possibles.size(); l++)
            {
              test = v;
              reduce(possibles[j], test);
              reduce(possibles[k], test);
              reduce(possibles[l], test);
              if(done(test))
              {
                cout << "Here" << endl;
                
                out << possibles[l] << possibles[k] << possibles[j] << endl;
                l = 10000;
                k = 10000;
                j = 10000;
              }
              test.clear();
            }
          }
        }
      possibles.clear();
      v.clear();
      }


      
    }
  }


  return 0;
}