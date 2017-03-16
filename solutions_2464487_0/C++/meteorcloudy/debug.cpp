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
#define maxn
#define oo 1000000000
#define clearAll(a) memset(a,0,sizeof(a))
#define sq(a) ((a)*(a))

using namespace std;

typedef long long ll;

ll r , t;

int main()
{
    freopen("C:\\Users\\py\\Desktop\\input.txt","r",stdin);
    freopen("C:\\Users\\py\\Desktop\\output.txt","w",stdout);

   	int tt;
   	scanf("%d",&tt);

   	for (int id=1;id<=tt;id++)
   	{
   		cin >> r >> t;
   		ll ans = 0;
   		ll tot = 0;
   		ll R = r+1;
   		ll rr = r;
   		while (true)
   		{
   			tot += sq(R) - sq(rr);
   			rr+=2;
   			R+=2;
   			if (tot<=t)
                ans++;
            else break;
   		}
   		printf("Case #%d: ",id);
   		cout << ans <<endl;
   	}

    return 0;
}
