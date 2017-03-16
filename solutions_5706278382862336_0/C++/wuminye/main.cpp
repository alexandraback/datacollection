#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <map>
#include <sstream>
#include <algorithm>
using namespace std;
long long gcd(long long  a,long long b)
{
    if (b==0) return a;
    return gcd(b,a%b);
}
struct fac
{
    long long p,q;
    fac(){}
    fac(long long  a,long long b)
    {
        p=a;q=b;
        long long t=gcd(a,b);
        p/=t;
        q/=t;
        if (p==0) q=1;
    }
    bool operator==(const fac & t)const
    {
        if (p==t.p && q==t.q) return true;
        return false;
    }
    bool operator<(const fac & t)const
    {
        long long t1=(long long)p*t.q;
        long long t2=(long long)t.p*q;
        return t1<t2;
    }
    fac operator*(const fac & t) const
    {
        long long fm=(long long)q*t.q;
        long long t1=(long long)p*t.q;
        long long t2=(long long)t.p*q;
        long long s=(t1+t2);
        fm*=2;
        return fac(s,fm);
    }
    void print()
    {
       cout<<p<<"/"<<q<<" ";
    }
};
int check(fac & t,int g)
{
    if (g>40) return -1;
    if (t==fac(0,1) ) return 0;
    if (t==fac(1,1)) return g;



    return false;
}

int main()
{
   freopen("in.txt","r",stdin);
   freopen("out.txt","w",stdout);
  int T,cas=0;
  long long p,q;
  cin>>T;
  while (T--)
  {
      string tem;
      cin>>tem;
      int z=0;
      while (tem[z]!='/') ++z;
      string ps=string(tem,0,z);
      string qs=string(tem,z+1,tem.length()-1);
    //  cout<<ps<<" "<<qs<<endl;
      stringstream fi(ps);
      fi>>p;
      stringstream ff(qs);
      ff>>q;
      fac girl(p,q);
      printf("Case #%d: ",++cas);
      //if (girl.q%2!=0) {cout<<"impossible"<<endl; continue;}
      int g=0;
      bool fla=false;
      int i;
      long long a=girl.p;
      long long b=girl.q;
      for (i=0;i<40;++i)
      {
          a*=2;
          if (!fla) ++g;
          if (a>=b)
          {
              a-=b;
              fla=true;
          }
          if (a==0) break;
      }
      if (i<40)cout<<g<<endl;
      else cout<<"impossible"<<endl;


  }
}
