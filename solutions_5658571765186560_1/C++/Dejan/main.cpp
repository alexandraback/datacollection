#include<queue>
#include<stack>
#include<string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <numeric>
#include <sstream>
#include<map>
#include<set>
#include<cstring>
#include <ctime>
#include<iostream>
#include<fstream>
using namespace std;
#define sz     size()
#define pb push_back
#define mp make_pair
#define fo(i, n) for ( i = 1; i <= (int)(n); i++)
#define fr(i, k, n) for ( i = k; i <= (int)(n); i++)
#define sortvektor(s)   sort((s).begin(),(s).end())
#define reversevektor(s)   reverse((s).begin(),(s).end())
#define fro(i, n) for ( i = 0; i < (int)(n); i++)
#define meset(x,y) memset((x),(y),sizeof((x)))
long long stoll (string target) { stringstream s; s << target; long long w; s >> w; return w;}
int stoi (string target) { stringstream s; s << target; int w; s >> w; return w;}
string itos (int i) {stringstream s; s << i; return s.str();}
string lltos (long long i) {stringstream s; s << i; return s.str();}






int mnozi;
int main()
{
ios::sync_with_stdio(false);

  freopen("input.txt","r",stdin);

bool ok=true,final=false;
int i,j,k,n,z; int t,pamti;
int m;
int pom,mom,g,f;
int odgovor,br;
int x,y;
 freopen("output.txt","w",stdout);
 cin>>t;




 for(int z=1;z<=t;z++)
 {

    cin>>k>>n>>m;
 if (n>m) { int p=n; n=m;m=p;}
    ok=true;
    if (k==1)
    {
          cout<<"Case #"<<z<<": GABRIEL"<<endl;

    }
    if (k==2)
    {
        if (n%2==1 &&m%2==1)
            cout<<"Case #"<<z<<": RICHARD"<<endl; else
         cout<<"Case #"<<z<<": GABRIEL"<<endl;

    }
    if (k==3)
    {
        if (n==1 || m==1)
        {
              cout<<"Case #"<<z<<": RICHARD"<<endl;
              continue;
        }
        if (n*m%3==0)
          cout<<"Case #"<<z<<": GABRIEL"<<endl; else
           cout<<"Case #"<<z<<": RICHARD"<<endl;
    }
    if (k==4)
    {
          if (n>m) { int p=n; n=m;m=p;}
         if (n<3)
        {
              cout<<"Case #"<<z<<": RICHARD"<<endl;
              continue;
        }
        if (n*m%4!=0 )
        {
             cout<<"Case #"<<z<<": RICHARD"<<endl;
              continue;
        }

 cout<<"Case #"<<z<<": GABRIEL"<<endl;

    }

    if (k==5)
    {
         if (n>m) { int p=n; n=m;m=p;}
        if (n*m%5!=0 ||n<4)
        {
             cout<<"Case #"<<z<<": RICHARD"<<endl;
              continue;
        }
 cout<<"Case #"<<z<<": GABRIEL"<<endl;
    }
    if (k==6)
    {
         if (n>m) { int p=n; n=m;m=p;}
        if (n*m%6!=0 ||n<5)
        {
             cout<<"Case #"<<z<<": RICHARD"<<endl;
              continue;
        }
 cout<<"Case #"<<z<<": GABRIEL"<<endl;
    }

    if (k>6)
    {
         cout<<"Case #"<<z<<": RICHARD"<<endl;
    }


 }



   return 0;
}
