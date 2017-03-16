#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <iomanip>

using namespace std;

char m[][4] = {{1, 2, 3, 4},
               {2,-1, 4,-3},
               {3,-4,-1, 2},
               {4, 3,-2,-1}};

char toNum(char c)
{
  if(c == 'i')
    return 2;
  if(c == 'j')
    return 3;
  if(c == 'k')
    return 4;
}

char mul(char a, char b)
{
  char sgn = 1;
  if(a*b < 0)
    sgn = -1;
  return sgn*m[abs(a)-1][abs(b)-1];
}

int main()
{
  int T;

  //ifstream in("test.in");
  //ofstream out("test.out");

  ifstream in("C-small-attempt0.in");
  ofstream out("C-small-attempt0.out");

  //ifstream in("C-large.in");
  //ofstream out("C-large.out");
  
  in >> T;

  

  for(int i=0; i<T; ++i)
  {
    int solve = 0; 
    __int64 L, X, ost;
    string str, test;

    in >> L >> X;

    in >> str;

    ost = X;

    test = str;

    //if(X <= 8)
    {
      for(int j=1; j<X; j++)
        test += str;

      ost=0;
    }
    /*else
    {
      for(int j=1; j<8; j++)
        test += str;

      ost -= test.size() / str.size();
    }
    */

    vector<int> ipos, kpos;
    int middle = test.size()/2;

    char rez=1;

    int up = test.size();

    if(ost != 0)
      up = middle;

    for(int j=0;j<up; j++)
    {
      char c = toNum(test[j]);

       rez=mul(rez,c);

      if(rez == 2)
        ipos.push_back(j);      
    }


    char rez2=1;
    int down = 0;

    if(ost != 0)
      down = middle;

    for(int j=test.size()-1; j>=down; j--)
    {
      char c = toNum(test[j]);

      rez2 = mul(c,rez2);

      if(rez2 == 4)
        kpos.push_back(j);
    }

    bool isOk = false;

    if(ost == 0)
    {
      if(kpos.size() > 0 && ipos.size() > 0)
        for(int j=0; j<ipos.size(); j++)
        {
          char r=1, left, right;
          int start = ipos[j]+1;
          int end = kpos[0];

          for(int k=start; k<end;k++)
          {
            char c = toNum(test[k]);
            r = mul(r,c);
          }

          if (r == 3)
          {
            isOk = true;
            break;
          }

          for(int k=1; k<kpos.size(); k++)
          {
            int start = kpos[k-1];
            int end = kpos[k];

            for(int k=start; k<end;k++)
            {
              char c = toNum(test[k]);
              r = mul(r,c);
            }

            if (r == 3)
            {
              isOk = true;
              break;
            }

          }

          if(isOk)
            break;
        }
    }
    else
    {
      if(kpos.size() > 0 && ipos.size() > 0)
      {
        vector<char> iost(ipos.size()), kost(kpos.size());

        char r=1;
        int k = ipos.size()-1;

        for(int ii=middle-1; ii>=0; ii--)
        {
          if(ii==ipos[k])
          {
            iost[k]=r;
            k--;

            if(k<0)
              break;
          }

          char c = toNum(test[ii]);
          r = mul(c,r);
        }

        r=1;
        k = 0;

        for(int kk=middle; kk<test.size(); kk++)
        {
          if(kk==kpos[k])
          {
            kost[k]=r;
            k++;

            if(k==kpos.size())
              break;
          }

          char c = toNum(test[kk]);
          r = mul(r,c);
        }

        for(int ii=0; ii<ipos.size(); ii++)
        {
          for(int kk=0; kk<kpos.size(); kk++)
          {
            char l = iost[ii];
            char r = kost[kk];

            char m, v;

            if(ost%4==0)
              m=1;
            if(ost%4==1)
              m=rez;
            if(ost%4==2)
              m=-1;
            if(ost%4==3)
              m=-rez;

            v = mul(l,m);
            v = mul(v,r);

            if(v==3)
            {
              isOk = true;
              break;
            }
          }

          if(isOk)
            break;
        }

      }

    }
    


    out << "Case #"<<i+1<<": ";

    if(isOk)
      out << "Yes" << endl;
    else
      out << "No" << endl;
  }

  return 0;
}