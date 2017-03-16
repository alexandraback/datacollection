#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <algorithm>
#include <stdlib.h>
#include <string>
#include <queue>
#include <vector>
#include <set>
#define maxn 200
#define oo 1000000000
#define clearAll(a) memset(a,0,sizeof(a))
#define sq(a) ((a)*(a))

using namespace std;

typedef long long ll;

int A,B,K;

int main()
{
    freopen("E:\\codejam\\input.txt","r",stdin);
    freopen("E:\\codejam\\output.txt","w",stdout);

    int tt;
    cin >> tt;
    int id = 0;
    while (tt--)
    {
        cin >>A >> B >> K;
        int ans=0;
        for (int i=0;i<A;i++)
            for (int j=0;j<B;j++)
                ans += ((i&j)<K);

        id++;
        printf("Case #%d: %d\n",id,ans);
    }
    return 0;
}
