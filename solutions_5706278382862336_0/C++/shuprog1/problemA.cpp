#include <algorithm>
#include <bitset>
#include <deque>
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <utility>
#include <vector>

using namespace std;

int main()
{
    freopen("A-small-attempt2.in", "r", stdin);
    freopen("outsmall2A.txt", "w", stdout);
    int p,q,T,t,c;
    char ch;
    scanf("%d",&T);
    for(t=1;t<=T;t++)
    {
        scanf("%d%c%d",&p,&ch,&q);
        if(p==1)
        {
            c=0;
            if((q && (!(q&(q-1))))==1){
            while(q>1)
            {
                q/=2;
                c++;
            }
                printf("Case #%d: %d\n",t,c);
            }
            else
                printf("Case #%d: impossible\n",t);
        }
        else
        {
            if((q && (!(q&(q-1))))==0)
                printf("Case #%d: impossible\n",t);
            else
            {
                c=0;
                while(q>p)
                {
                    q/=2;
                    c++;
                }
                printf("Case #%d: %d\n",t,c);
            }
        }
    }

    return 0;
}
