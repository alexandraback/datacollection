#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<queue>
#include<complex>
#include<set>
#include<map>
#include<sstream>
#include<string>
#include<deque>
#include<sys/time.h>
#include<fstream>
#include<bitset>

using namespace std;

#define mp make_pair
#define pb push_back
#define forn(i,n) for(int i=0;i<(int)(n);i++)
#define dforn(i,n) for(int i=(int)(n)-1;i>=0;i--)
#define all(v) v.begin(),v.end()
#define sq(x) ((x)*(x))
#define pi (4*atan(1))

double s;

bool sirve(vector<int>v,double r,int p)
{
    double x=v[p]+s*r;
    double tot=r;
    forn(i,v.size())if(v[i]<x and i!=p)
    {
        tot+=(x-v[i])/s;
    }
    if(tot>1+1e-10)return false;
    return true;
}

int main()
{
    int T;
    cin>>T;
    forn(t,T)
    {
        int n;
        cin>>n;
        s=0;
        vector<int>v(n);
        vector<double>res;
        forn(i,n)
        {
            cin>>v[i];
            s+=v[i];
        }
        forn(i,n)
        {
            double a=0,b=1,c;
            while(b-a>1e-10)
            {
                c=(a+b)/2;
                if(!sirve(v,c,i))b=c;else a=c;
            }
            res.pb(100*a);
        }
        cout<<"Case #"<<t+1<<":";
        forn(i,res.size())printf(" %.8f",res[i]);
        cout<<endl;
    }
}
