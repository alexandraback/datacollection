#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <iomanip>
#include <mkl_vsl.h>

using namespace std;

int main()
{
  int T;

  //ifstream in("test.in");
  //ofstream out("test.out");

  ifstream in("B-small-attempt0.in");
  ofstream out("B-small-attempt0.out");

  //ifstream in("B-large.in");
  //ofstream out("B-large.out");

  in >> T;

  for(int testCase=0; testCase<T; ++testCase)
  {
    double solve = 0.; 

    int K, L, S;

    in >> K >> L >> S;

    string keys, target;

    in >> keys >> target;


    map<char,double> p;

    for(int i=0 ;i<K; i++)
    {
      int count = 0;

      if(p.find(keys[i]) == p.end())
      {
        for(int j=0; j<K; j++)
         if(keys[i]==keys[j])
            count++;

        p[keys[i]] = count / (double)K;
      }
      
    }

    double P=1.;

    for(int i=0; i<L; i++)
      P*=p[target[i]];

    int max = 0, count = 0;

    vector<int> rep(L);

    for(int i=1; i<L; i++)
    {
      bool isOk = true;

      for(int j=0; j<L-i; j++)
        if(target[i+j] != target[j])
        {
          isOk=false;
          break;
        }

      if(isOk)
        rep[i]=1;
    }

    vector<char> str(S);

    for(int i=0; i<S-L+1; i++)
    {
      for(int j=0; j<L; j++)
        str[i+j] = target[j];

      max++;

      int offset = 0;

      for(int j=0; j<L; j++)
      {
        if(rep[j]==1)
          break;
        offset++;
      }

      i+=offset-1;
    }
    

    //for(int k=0; k<S-L+1; k++)
    //{
    //  int c = 0;
    //  for(int i=k; i<S-L+1; i++)
    //  {
    //    for(int j=0; j<L; j++)
    //      str[i+j] = target[j];

    //    c++;

    //    int offset = L;

    //    //for(int j=0; j<L; j++)
    //    //{
    //    //  if(rep[j]==1)
    //    //    break;
    //    //  offset++;
    //    //}

    //    i+=offset-1;
    //  }

    //  if(c > max)
    //    max = c;
    //  count += c;
    //}
    

    count = S-L+1;

    if(P == 0)
      solve = 0;
    else
      solve = max - count * P;

    out << "Case #"<<testCase+1<<": ";

    out.precision(7);
    out << solve << endl;
  }

  return 0;
}