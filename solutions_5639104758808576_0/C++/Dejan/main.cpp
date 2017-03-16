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
bool a[10000001];

int b[1000000];
int mnozi;
int main()
{
ios::sync_with_stdio(false);

  freopen("input.txt","r",stdin);

bool ok=true,final=false;
int i,j,k,n,m,z; int t,pamti;
int pom,mom,g,f;
int odgovor,br;

   freopen("output.txt","w",stdout);
 cin>>t;



 for(int z=1;z<=t;z++)
 {
    string s;
    cin>>n;
    cin>>s;
    br=0; odgovor=0;
    fro(i,s.sz)
    {
        if (s[i]>'0')
        {
            if (br<i)
            {
                odgovor+=(i-br);
                br=i;
            }
        }

        br+=(s[i]-'0');
    }


cout<<"Case #"<<z<<": "<<odgovor<<endl;


 }



   return 0;
}
