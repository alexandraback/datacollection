//In The Name Of GOD
//MME

#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<fstream>

using namespace std;
typedef long long ll;
ofstream fout ("1.out");
ifstream fin ("B-small-attempt0.in");

int main()
{
   ll a, b, k, ans=0;
   int tt;
   fin >> tt;
   for (int hh=0; hh<tt; hh++)
   {
      fin >> a >> b >> k;
      ans=0;
      for (int i=0; i<a; i++)
      {
         for (int j=0; j<b; j++)
         {
            if ((i & j)<k)
            {
               //cout << i << " " << j << " " << ( i & j ) << endl;
               ans++;
            }
         }
      }
      fout << "Case #" << hh+1 << ": " << ans << endl;
   }
}
