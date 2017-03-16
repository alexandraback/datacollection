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

int A[100][100];
int m0[100],m1[100];

int main()
{
  int cases;
  cin >> cases;
  for(int loop=1; loop<=cases; loop++)
  {
    int m,n; cin >> n >> m;
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) cin >> A[i][j];
    for(int i=0;i<n;i++) { m0[i]=0; for(int j=0;j<m;j++) m0[i]=max(m0[i],A[i][j]); }
    for(int j=0;j<m;j++) { m1[j]=0; for(int i=0;i<n;i++) m1[j]=max(m1[j],A[i][j]); }

    bool ok=true;
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) if (A[i][j] != min(m0[i],m1[j])) ok=false;
    printf("Case #%d: ",loop);
    puts(ok?"YES":"NO");
    // puts("");
  }
}
