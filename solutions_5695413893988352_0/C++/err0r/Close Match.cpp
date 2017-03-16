#include<iostream>
#include <algorithm>
#include <vector>
#include<string>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<set>
#include <utility>

using namespace std;

#define inf         freopen("in.txt", "r", stdin);
#define outf        freopen("out.txt", "w", stdout);
#define pf          printf
#define sf(n)       scanf("%d", &n)
#define sff(a,b)    scanf("%d %d", &a, &b)
#define mn          (long long)-9223372036854775807
#define mx          (long long) 9223372036854775807
#define mod          1000000009
#define LL           long long


//set<int>::iterator ii;

string cod, bal;

LL maxx = mx, an, bn;


void rec( int ind, LL x, LL y )
{
    if( ind == cod.size() )
    {
       // cout << x << ' ' << y << endl;
        LL chk = max( x-y, y-x );

       if( maxx > chk )
       {
           maxx = chk;
           an = x;
           bn = y;

       }
       else if( maxx == chk && an > x )
       {
           maxx = chk;
           an = x;
           bn = y;
       }
       else if( maxx == chk && an == x && bn > y )
       {
           maxx = chk;
           an = x;
           bn = y;
       }

    }

    else
    {
        LL a, b;

            if( cod[ind] == '?' && bal[ind] == '?' )
            {
               for( int i=0; i<=9; i++ )
                 {
                     if( x == 0 )
                        a = i;
                     else
                        a = x*10 + i;

                     for( int j=0; j<=9; j++ )
                 {
                     if( y == 0 )
                        b = j;
                     else
                        b = y*10 + j;
                      rec( ind+1, a, b );
                 }

                 }
             }
             else if( cod[ind] == '?' )
            {
               for( int i=0; i<=9; i++ )
                 {
                     if( x == 0 )
                        a = i;
                     else
                        a = x*10 + i;

                     if( y == 0 )
                        b = bal[ind] - 48;
                     else
                        b = y*10 + ( bal[ind] - 48 );
                      rec( ind+1, a, b );
                 }
             }
             else if( bal[ind] == '?' )
            {
               for( int i=0; i<=9; i++ )
                 {
                      if( x == 0 )
                        a = ( cod[ind] - 48 );
                      else
                        a = x * 10 + ( cod[ind] - 48 );

                        if( y == 0 )
                            b = i;
                        else
                            b = y * 10 + i;

                      rec( ind+1, a, b );
                 }

             }

             else
             {
                 if( x == 0 )
                    a = ( cod[ind] - 48 );
                else
                    a = x * 10 + ( cod[ind] - 48 );

                 if( y == 0 )
                    b = bal[ind] - 48;
                else
                    b = y*10 + ( bal[ind] - 48 );

                 rec( ind+1, a, b );
             }


    }
}




int main()
{
    ios::sync_with_stdio(false);

    inf;
    outf;
     int t, ca = 1;

     cin >> t;

     while( t-- )
     {

       maxx = mx, an = mx, bn = mx;
    LL i, j, x, y, n, m;


     cin >> cod;
     cin >> bal;

     rec( 0, 0, 0);

     string ans = "000" , bns = "000";

     x = cod.size()-1;

     while( x >= 0 )
     {

         y = an % 10;
         ans[x] = y+48;
         an /= 10;
         x--;
     }
     x = cod.size()-1;

     while( x >= 0 )
     {
         y = bn % 10;
         bns[x] = y+48;
         bn /= 10;
         x--;
     }
      cout << "Case #" << ca++ << ": ";
     for( i=0; i < cod.size(); i++ )
          cout << ans[i];
        cout << ' ';
     for( i=0; i < cod.size(); i++ )
          cout << bns[i];
      cout << endl;

     }


    return 0;

}


