#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <map>
#include <vector>
using namespace std;
int A,B,C,Cases,T,i,j,ans;
int main()
{
    scanf("%d",&Cases);
    for (T=1; T<=Cases; T++)
    {
        scanf("%d%d%d",&A,&B,&C);
        for (i=0; i<A; i++)
          for (j=0; j<B; j++)
            if ((i&j)<C) ans++;
        printf("Case #%d: %d\n",T,ans);
        ans=0;
    }
    return 0;
}
