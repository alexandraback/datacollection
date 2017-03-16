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
  fin.open("A-small-attempt2.in");
  fin>>test_cases;
  ofstream fout;
  fout.open("output.txt");
  int num=1;
  while(test_cases>0)
  {
    char a[105];
    int n;
    fin>>a;
    fin>>n;
    
    int run_cons=0;
    int start = 0;
    int end=0;

    int k=strlen(a);
    int result = k*(k+1)/2;

    for(int i=n-1;i>0;i--)
    {
      result-= (k-i+1);
    }

    for(int i=0;i<strlen(a);i++)
    {
      if(a[i]!='a'&&a[i]!='e'&&a[i]!='i'&&a[i]!='u'&&a[i]!='o')
        run_cons++;
      else
      {
        if(run_cons>=n)
        if(i>n-1)
        {
          start = i -n+1;
        }
        run_cons=0;
      }
      if(run_cons==n)
      {
        end = i-1;
        for(int j=n;j<=end-start+1;j++)
        {
          result-=end-start +1 - j+1;
        }
      }
      else if(run_cons>n)
      {
      }
      else if(i==strlen(a)-1)
      {
        end = i;
        for(int j=n;j<=end-start+1;j++)
        {
          result-=end-start +1 - j+1;
        }
      }
    }
    fout<<"Case #"<<num<<": "<<result;
    fout<<endl;
    num++;
    test_cases--;
  }
  return 0;
}