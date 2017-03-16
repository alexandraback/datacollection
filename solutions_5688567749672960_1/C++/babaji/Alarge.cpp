#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define bg begin()
#define en end()
#define Y second
#define X first
typedef long long ll;

#define fi freopen("input.txt","r",stdin)
#define fo freopen("output.txt","w",stdout)

const double pi     =   acos(-1.0);
const double eps    =   1e-8;

#define print(a) cout<<(#a)<<" = "<<a<<"\n";
#define fill(a,val) memset(a ,val, sizeof(a) );
#define sz(s) ((int)(s.size()))

vector <string> parse(string s, string c)
{
  int len = c.length(), p = -len, np;
  vector <string> ans;

  do
    {
      np = s.find(c, p+len);
      ans.push_back(s.substr(p+len, np - p - len));
      p = np;
    }
  while (p != string::npos);

  return ans;
}


/*Solution code starts here */


inline  ll rever( ll in)
{
   ll ans =0;
   ll save= in;

   while(in!=0)
   {
      ans = ans * 10;
      ans = ans + in%10;
      in = in/10;
   }

   return ans;

}


int go(ll in)
{

    if( in < 10)
      return in;


    int cn = 0 ;

    while( (in%10) !=1 )
    {
        in--;
        cn++;
    }

    ll rv = rever(in);

    if( rv>=in )
       return cn+1+go(in-1);

    return cn+go(rv)+1;//eke reverse ka

}

void solve(int test)
{


   int in;

   cin>>in;

   printf("Case #%d: %d\n",test,go(in));


}


int main()
{

    int test;

    cin>>test;

    for(int i=1;i<=test;i++)
    {
        solve(i);
    }

    return 0;
}
