#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <utility>
#include <algorithm> // sort, max_element, random_shuffle, remove_if, lower_bound 
#include <functional>
#include <fstream>
#include <iomanip>
using namespace std;
int main()
{
  int test_cases;
  ifstream fin;
  fin.open("B-small-attempt0 (2).in");
  fin>>test_cases;
  ofstream fout;
  fout.open("output.txt");
  int num=1;
  while(test_cases>0)
  {
    int a,b;
    fin>>a>>b;

    fout<<"Case #"<<num<<": ";
    if(a<0)
    {
      while(a!=0)
      {
        fout<<"EW";
        a++;
      }
    }
    else
    {
      while(a!=0)
      {
        fout<<"WE";
        a--;
      }
    }
    if(b<0)
    {
      while(b!=0)
      {
        fout<<"NS";
        b++;
      }
    }
    else
    {
      while(b!=0)
      {
        fout<<"SN";
        b--;
      }
    }
    fout<<endl;
    num++;
    test_cases--;
  }
  return 0;
}