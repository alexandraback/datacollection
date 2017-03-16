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
unsigned long long int gcd(unsigned long long int a, unsigned long long int b)
{
    if(b==0)
        return a;
    return gcd(b,a%b);
}

void reduce(unsigned long long int& a, unsigned long long int &b)
{
    unsigned long long int k=gcd(a,b);
    a=a/k;
    b=b/k;
}
int main()
{
    freopen("A-large.in", "r", stdin);
    freopen("outlarge1A.txt", "w", stdout);
    unsigned long long int p,q,T,t,c;
    char ch;
    scanf("%llu",&T);
    for(t=1;t<=T;t++)
    {
        scanf("%llu%c%llu",&p,&ch,&q);
        reduce(p,q);
        //cout<<"p:"<<p<<"q:"<<q;
        if(p==1)
        {
            c=0;
            if((q && (!(q&(q-1))))==1){
            while(q>1)
            {
                q/=2;
                c++;
            }
                printf("Case #%llu: %llu\n",t,c);
            }
            else
                printf("Case #%llu: impossible\n",t);
        }
        else
        {
            if((q && (!(q&(q-1))))==0)
                printf("Case #%llu: impossible\n",t);
            else
            {
                c=0;
                while(q>p)
                {
                    q/=2;
                    c++;
                }
                printf("Case #%llu: %llu\n",t,c);
            }
        }
    }

    return 0;
}
