#include<iostream>
#include<fstream>
#include<cstdio>
#include<vector>
using namespace std;

bool pos(double fra, vector<int> v, int i, int sum)
{
    double lim = v[i] + fra*sum;
    double f = 0.;
    for(int j = 0; j < v.size(); j++)
    {
       if(j != i)
       {
            if(v[j] < lim)
            {
                f += (lim - v[j])/double(sum);
            }
       } 
    }
    return f >= (1.-fra);
    
}
int main()
{
 ifstream in("in.txt");
 ofstream out("out.txt");
 int t,n;
 in >> t;
 for(int i = 1; i <= t; i++)
 {
   in >> n;
   vector<int> v(n);
   int sum = 0;
   for(int j  =0; j < n; j++)
   {
     int cur;
     in >> cur;
     v[j] = cur;
     sum += cur;
   }
   vector<double> ret(n);
   for(int j = 0; j < n; j++)
   {
      double low = 0, hi = 1, mid;
      mid = (hi + low)/2;
      while(hi - low >= 1e-9)
      {
            if(pos(mid,v,j, sum))
                hi = mid;
            else 
                low = mid;
            mid = (hi + low)/2;  
      }
      ret[j] = mid;
   }     
   out.precision(9);
   out<<"Case #"<<i<<": ";     
   for(int j = 0; j < n - 1; j++)
   if(ret[j] <= 1e-8) out<<0<<" ";
     else
     out<<ret[j]*100<<" ";
   if(ret[n-1] <= 1e-8) out<<0<<" "<<endl;
     else
     out<<ret[n-1]*100<<" "<<endl;
 } 
}
