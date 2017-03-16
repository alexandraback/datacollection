#include <iostream>
#include <bitset>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <sstream>
#include <fstream>
#include <cmath>
#include <iomanip>

using namespace std;

typedef vector<double> vd;
typedef vector<int> vi;
typedef vector<string> vs;
typedef long long int lli;

#define pb push_back
#define ins insert
#define s size
#define be begin()
#define en end()
#define rb rbegin()
#define re rend()

/// For sort ( algoritm ) class comparison
struct myclass {
  bool operator() (int i,int j) { return (i<j);}
} myobject;

/// For container class comparison
struct classcomp {
  bool operator() (const char& lhs, const char& rhs) const
  {return lhs<rhs;}
};

int main()
{
      ifstream in("A-small.in");
      int T;
      in>>T;
      for(int p=1;p<=T;p++)
      {
            int A,B;


            in>>A>>B;
            vector<double> tab(A,0.0);

            for(int j=0;j<A;j++){
            double tmp;
            in>>tmp;
            tab[j]=tmp;
            }

            double best=0.0;
            /// Giving up by pressing enter
            best=2+B;

            /// I keep typing

            double pr=1;
            for(int j=0;j<A;j++)
            pr*=tab[j];

            double tmp=pr*(B-A+1)+(1-pr)*(B-A+1+B+1);
            if(tmp<best)
            best=tmp;

            /// Third way by backspacing letting k remaining characters

            for(int k=0;k<A;k++)
            {
                  pr=1;
                  tmp=0;
                  if(k==0){
                        tmp=A+B+1;
                        if(tmp<best)
                        best=tmp;

                  }
                  for(int j=0;j<k;j++)
                  pr*=tab[j];
                  tmp=((A-k)+(B-k)+1)*pr+(1-pr)*(A-k+B-k+1+B+1);
                  if(tmp<best)
                  best=tmp;

            }


            cout<<"Case #"<<p<<": "<<setprecision(7)<<best<<endl;


      }



    return 0;
}
