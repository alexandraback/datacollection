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

bool fair(ull n)
{
  static char d[20]; int k=0;
  while(n) { d[k++] = n%10; n/=10; }
  for(int i=0;i<k-1-i;i++) if (d[i]!=d[k-1-i]) return false;
  return true;
}

int main()
{

vector<ull> L;
for(ull i=1;i<1e7;i++) { if (fair(i) && fair(i*i)) L.push_back(i*i); }
//for(int i=0;i<L.size();i++) cout << L[i] <<endl;

/*ull a; while(cin >> a) printf("%d\n",lower_bound(L.begin(),L.end(),a)-L.begin());*/

  int cases;
  cin >> cases;
  for(int loop=1; loop<=cases; loop++)
  {
    ull a,b; cin >> a >> b;
    printf("Case #%d: ",loop);
    // puts("");
    printf("%d\n",int(lower_bound(L.begin(),L.end(),b+1) - lower_bound(L.begin(),L.end(),a)));
  }
}
