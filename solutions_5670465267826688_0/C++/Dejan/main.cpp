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


string proizvodi[100001];



int mnozi;
int main()
{
ios::sync_with_stdio(false);

  freopen("input.txt","r",stdin);

bool ok=true,final=false;
int i,j,k,n,m,z; int t,pamti;
int pom,mom,g,f;
int odgovor,br;
int x,y;
 freopen("output.txt","w",stdout);
 cin>>t;
 string s,s2;

map<string,string> a,mapa;
string r[]={"1","i","j","k"};
string u[]={"+","-"};
fro(i,4)
fro(j,4)
{
    string p,znak,sprotivenznak;
    if (i==0||j==0)
    {
         p=r[i];
        if (i==0) p=r[j];
        a["+"+r[i]+"+"+r[j]]="+"+p;
        a["+"+r[i]+"-"+r[j]]="-"+p;
        a["-"+r[i]+"+"+r[j]]="-"+p;
        a["-"+r[i]+"-"+r[j]]="+"+p;
        continue;
    }
    fro(x,2)
    fro(y,2)
    {
        if (x==y) { znak="+"; sprotivenznak="-"; } else
        { znak="-"; sprotivenznak="+"; }
        if (i==j)
        {
            s=u[x] + r[i]+ u[y]+r[j];
            s2=sprotivenznak+"1";
            a[s]=s2;
            continue;
        }
        if (i==1&&j==2)
        {
            s=u[x]+r[i]+u[y]+r[j];
            s2=znak+"k";
        }
        if (i==1&&j==3)
        {
            s=u[x]+r[i]+u[y]+r[j];
            s2=sprotivenznak+"j";
        }
        if (i==2&&j==1)
        {
            s=u[x]+r[i]+u[y]+r[j];
            s2=sprotivenznak+"k";
        }
        if (i==2&&j==3)
        {
            s=u[x]+r[i]+u[y]+r[j];
            s2=znak+"i";
        }
        if (i==3&&j==1)
        {
            s=u[x]+r[i]+u[y]+r[j];
            s2=znak+"j";
        }
        if (i==3&&j==2)
        {
            s=u[x]+r[i]+u[y]+r[j];
            s2=sprotivenznak+"i";
        }
         a[s]=s2;

    }



}





 for(int z=1;z<=t;z++)
 {
    cin>>n>>m;
    cin>>s;
    string b="";
    fo(i,m) b+=s;
   // a[1]="+"+b[0];
   proizvodi[1]="+";
   proizvodi[1]+=b[0];
    fr(i,1,b.sz-1)
    {
        s=proizvodi[i]+"+"; s+=b[i];
        s2=a[s];
        proizvodi[i+1]=s2;
    }
    if (proizvodi[b.sz]!="-1")
    {
        cout<<"Case #"<<z<<": NO"<<endl;
        continue;
    }
    ok=false;
    fo(i,b.sz-2)
    if (proizvodi[i]=="+i")
    fr(j,i+1,b.sz-1)
    if (proizvodi[j]=="+k")
    {
        ok=true;
        goto labela;
    }
    labela:
    if (ok)
    cout<<"Case #"<<z<<": YES"<<endl;
    else
    cout<<"Case #"<<z<<": NO"<<endl;








 }



   return 0;
}
