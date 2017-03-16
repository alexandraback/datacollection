#include<iostream>
#include<string>
#include<cmath>
using namespace std;
int ar[10000001];

int ispali(long long int i )
{
 string s="";
 while( i ) s += char( 48 + i%10 ), i /= 10;
 return s == string( s.rbegin(), s.rend() );
}
int main()
{
    ar[0] = 0;

    for( long long int i = 1; i < 10000001; ++i )
         ar[i] = ( ispali( i ) && ispali( i*i ) ) + ar[i-1];

        
    int t, tt=1;
    cin>>t;
    while( tt <= t )
    {
           long long int a, b;
           cin>>a>>b;
           int aa = ceil(sqrt(a));
           int bb = floor(sqrt(b));
           cout<<"Case #" << tt << ": " << ar[bb] - ar[aa-1]<<endl;
           ++tt;
    }
    return 0;
}
