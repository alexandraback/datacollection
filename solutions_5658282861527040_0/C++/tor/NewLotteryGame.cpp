#define f first
#define s second
#define INF 2000000000
#define LNF 8000000000000000000
#define mp make_pair
#define ll long long int
#define BL for(int K = 1; K <= T; K++)
#define db double

#include <stdio.h>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);

	int T,a,b,i,j,k,res;

	scanf("%d",&T);

	BL
	{
	    scanf("%d%d%d",&a,&b,&k);

        res = 0;

	    for(i = 0; i < a; i++)
        {
            for(j = 0; j < b; j++)
            {
                if((i & j) < k)
                {
                    res++;
                }
            }
        }

        printf("Case #%d: %d\n",K,res);
	}
}
