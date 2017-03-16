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

int b[3000000];

int main()
{
    int T;
    cin>>T;
    forn(t,T)
    {
        int n;
        cin>>n;
        vector<int>s(n);
        forn(i,n)cin>>s[i];
        bool ans=false;
        int ax,ay;
        forn(i,3000000)b[i]=-1;
        forn(i,1<<n)
        {
            int res=0;
            int a=i;
            forn(j,n)
            {
                if(a%2)res+=s[j];
                a/=2;
            }
            if(b[res]!=-1)
            {
                ax=b[res];
                ay=i;
                ans=true;
                break;
            }else
            {
                b[res]=i;
            }
        }
        cout<<"Case #"<<t+1<<":"<<endl;
        if(ans)
        {
            int a=ax;
            forn(i,n)
            {
                if(a%2)cout<<s[i];
                if(a/2 and a%2)cout<<" ";
                a/=2;
            }
            cout<<endl;
            a=ay;
            forn(i,n)
            {
                if(a%2)cout<<s[i];
                if(a/2 and a%2)cout<<" ";
                a/=2;
            }
            cout<<endl;
        }else
        {
            cout<<"Impossible"<<endl;
        }
        
    }
}
