#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cctype>
#include<ctime>
#include<assert.h>

#include<cmath>
#include<iostream>
#include<fstream>

#include<string>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
#include<set>
#include<sstream>
#include<stack>
#include<limits.h>

using namespace std;

#define MAX(a,b) ((a)>(b) ? (a) : (b))
#define MIN(a,b) ((a)<(b) ? (a) : (b))
#define EPS 1e-9
#define asdf exit(0);
#define AB(a) ((a)<(0) ? (-(a)) : (a))
#define EQ(a,b) ( (fabs((a)-(b))<EPS) ? (1) : (0))





typedef long long LL;
//typedef __int64 LL;





int get(int n,int len)
{
  int ret=(n/len);
  if(n%len==0)
     ret+=(len-1);
  else ret+=len;
  return ret;
}

int main()
{
    freopen("A-small-attempt1.in","r",stdin);
    freopen("A-small-attempt1.out","w",stdout);
    int i,j,k,T,cs,n,m,len;
    scanf("%d",&T);

    for(cs=1;cs<=T;cs++)
    {
      printf("Case #%d: ",cs);
      scanf("%d %d %d",&n,&m,&len);


      int ans=(n-1)*(m/len);
      if(m%len) ans+=(n-1);

      printf("%d\n",ans+get(m,len));
    }


    return 0;
}
