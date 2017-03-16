#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <utility>
#define inf 2000000000
#define ll long long
#define Max

using namespace std;

char str[10000];
vector <int> v;

int main()
{
    int i,j,k,T,cas,ret=0,s;
    int total,need,extra;

    freopen("/Users/sakibshafayat/Documents/Codes/CodesRunning/Codejam15/Quali/A-large.in","r",stdin);
    freopen("/Users/sakibshafayat/Documents/Codes/CodesRunning/Codejam15/Quali/A-large.txt","w",stdout);

    scanf("%d",&T);

    for(cas=1;cas<=T;cas++)
    {
        scanf("%d %s",&s,str);

        extra=total=0;

        v.clear();

        for(i=0;i<=s;i++){

                k=str[i]-'0';

                while(k--) v.push_back(i);

        }

        for(i=0;i<v.size();i++,total++){

            need=v[i];

            if(need<=total) continue;

            extra+=need-total;
            total=need;
        }

        printf("Case #%d: %d\n",cas,extra);
    }

    return 0;
}

