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

#define maxn (10000001)

int ulta[maxn];

inline void rever( int in)
{
   int ans =0;
   int save= in;

   while(in!=0)
   {
      ans = ans * 10;
      ans = ans + in%10;
      in = in/10;
   }

   ulta[save]=ans;
}

int dist[maxn];

queue<int> Q;
void process()
{
   fill(dist,-1);

   dist[1]=1;
   Q.push(1);

   while(!Q.empty())
   {
       int curr= Q.front(); Q.pop();

       if( curr >= maxn)
         continue;

       //add 1
       if( dist[curr+1]==-1)
       {
         dist[curr+1]=dist[curr]+1;
         Q.push(curr+1);
       }

       if( dist[ ulta[curr] ]==-1)
       {
           dist[ ulta[curr] ] = dist[curr+1];
           Q.push( ulta[curr] );
       }
   }


}

void solve(int test)
{
   int ans=0;

   int in;

   cin>>in;

   printf("Case #%d: %d\n",test,dist[in]);

}


int main()
{

    for(int i=1;i<maxn;i++)
      rever(i);

     process();

    int test;

    cin>>test;

    for(int i=1;i<=test;i++)
    {
        solve(i);
    }

    return 0;
}
