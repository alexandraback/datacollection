#include<cmath>
#include<iostream>
#include<fstream>
using namespace std;
#define ull            unsigned long long
int main()
{
freopen("A-small-attempt0.in","r",stdin);
freopen("output.txt","w",stdout);
int test;

cin>>test;
for(int i=1;i<=test;i++)
{
    ull r,t;
    cin>>r>>t;
    ull ft;
    ft= (2*r +1);
    ull a,b,c;
    a=2;
    b=(ft*2 -4)/2;
    c=-t;
    ull d,sq;
    d= b*b +(-4*a*c);
    sq=sqrt(d);
    ull n;
    n= (sq- b)/4 ;

    cout<<"Case #"<<i<<": "<<n<<endl;

}
return 0;
}
