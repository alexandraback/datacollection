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
    for(int p1=1;p1<=T;p1++)
    {
          int N;
          in>>N;
          vector<int> tab(N,0);
          int X=0;
          for(int i=0;i<N;i++)
          {
                in>>tab[i];
                X+=tab[i];

          }
          vector<double> val(N,0);
          vector<bool> used(N,false);
          double tmp=0;
          int N1=N,p=0;
          double X1=X,s=0;
          bool stop=true;

          while(true)
          {
                for(int i=0;i<N;i++)
                {
                      if( !used[i] && (tab[i]*N1>=X1+X))
                      {
                            used[i]=true;
                            p++;
                            s+=tab[i];
                            stop=false;
                      }
                }
                N1-=p;
                X1-=s;
                if(stop)
                break;
                stop=true;
                p=0;
                s=0;
          }


          if(N1>0)
          {
                for(int i=0;i<N;i++)
          {
                if(!used[i])
                {
                      if(X1>0)
                      //val[i]=(100.0)*((2.0/(double)N1)-(double)tab[i]/(double)X1);
                      val[i]=100.0*(((X1+X-(double)N1*tab[i]))/(X*(double)N1));
                      else
                      val[i]=100.0/(double)N1;

                }

          }

          }

          cout<<"Case #"<<p1<<": "<<setprecision(8)<<val[0];

          for(int i=1;i<N;i++)
          {
                cout<<" "<<setprecision(8)<<val[i];

          }

          cout<<endl;
    }

    in.close();
    return 0;
}
