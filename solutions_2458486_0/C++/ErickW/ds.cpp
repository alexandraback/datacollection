#include <algorithm>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned long ul;
typedef unsigned short us;
typedef unsigned char uc;

typedef map<int,int> chain;

int k,n,t[200]; chain c0,o[200];

chain net(int mask)
{
  chain out=c0;
  for(int i=0;i<n;i++) if((~mask) & (1<<i))
  {
    out[t[i]]--;
    for(chain::iterator it = o[i].begin(); it != o[i].end(); it++) { out[it->first] += it->second; }
  }
  return out;
}

void dump(const chain &c)
{
cout<<"[";
    for(chain::const_iterator it = c.begin(); it != c.end(); it++) { printf("%d (x%d), ",it->first,it->second); } puts("]");
}

bool valid(const chain &c)
{
    for(chain::const_iterator it = c.begin(); it != c.end(); it++) { if(it->second<0) return false; } return true;
}

char H[1<<20];

int main()
{
  int cases;
  cin >> cases;
  for(int loop=1; loop<=cases; loop++)
  {
    c0.clear(); cin >> k >> n;
    for(int i=0;i<n;i++) o[i].clear();

    int x; for(int i=0;i<k;i++) { cin >> x; c0[x]++; }
    for(int i=0;i<n;i++)
    {
      int ki; cin >> t[i] >> ki;
      int x; for(int j=0;j<ki;j++) { cin >> x; o[i][x]++; }
    }

    printf("Case #%d:",loop);
    if (!valid(net(0))) { puts(" IMPOSSIBLE"); continue; }
    H[0] = 0;

    for(int bb=1; bb < (1<<n); bb++)
    {
      H[bb]=-1;
      chain c = net(bb);
//printf("%d: ",bb); dump(c);
if (!valid(c)) continue;
      for(int b=0;b<n;b++) if ((1<<b) & bb)
      {
        int b2 = bb & ~(1<<b); if (H[b2]>=0 && c[t[b]]>0) { H[bb] = b; break; }
      }
    }

    if (H[(1<<n)-1] < 0) { puts(" IMPOSSIBLE"); continue; }
int bb=(1<<n)-1;
while(bb)
{
  printf(" %d",1+H[bb]); bb &= ~(1<<(H[bb]));
}
puts("");
    // puts("");
  }
}
