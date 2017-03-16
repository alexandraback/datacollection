#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
using namespace std;
int MAXN = 100100;
int CAS,cas,aSize,n;
int sizeArray[110];
int main()
{
    freopen("A-small-attempt0.in","r",stdin);
    freopen("out.txt","w",stdout);
    scanf("%d",&CAS);
    while(CAS--)
    {
        scanf("%d%d",&aSize,&n);
        for(int i = 0;i < n;i++)
            scanf("%d",&sizeArray[i]);
        sort(sizeArray,sizeArray+n);
        int ans = 110;
        int op = 0;
        for(int i = 0;i < n;i++)
        {
            if(aSize == 1)
            {
                ans = n - i;
                break;
            }
            if(ans > op + n - i)
                ans = op + n - i;
            if(aSize <= sizeArray[i])
            {
                    while(aSize <= sizeArray[i])
                    {
                        aSize += (aSize - 1);
                        op++;
                    }
            }
            aSize += sizeArray[i];
            if(ans > op + n - i - 1)
                ans = op + n - i - 1;

        }
        printf("Case #%d: %d\n",++cas,ans);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
