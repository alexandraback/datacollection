#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#define LL long long
#define eps 1e-8
#define mem(a,b) memset(a,b,sizeof(a))
#define zero(x) ((x > +eps) - (x < -eps))
#define MAX 110
using namespace std;

char str[MAX];

int main()
{
    freopen("B-large.in","r",stdin);
    freopen("B-large.out","w",stdout);
    int t, Case = 0;
    scanf("%d",&t);
    while(t --)
    {
        Case ++;
        printf("Case #%d: ",Case);
        scanf("%s",str);
        int len = strlen(str);
        int cnt = 1;
        for(int i = 1; i < len; i ++)
        {
            if(str[i] != str[i-1])
            {
                cnt ++;
            }
        }
        if(str[len - 1] == '+')
        {
            cnt --;
        }
        printf("%d\n",cnt);
    }
    return 0;
}
