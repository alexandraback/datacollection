
#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int t;

int main()
{
    freopen("input2.txt","r",stdin);
    freopen("res2.txt","w",stdout);
    cin>>t;
    for(int no = 1 ; no <= t ; no++ )
    {
        int n, chk[2511] = {0};
        cin>>n;
        for(int i = 0, t ; i < 2*n-1 ; i++ )
        {
            for(int j = 0 ; j < n ; j++ )
            {
                scanf("%d", &t);
                chk[t]++;
            }
        }

        printf("Case #%d: ", no);
        for(int i = 0 ; i < 2501 ; i++ )
            if( chk[i]%2 ) printf("%d ", i);
        puts("");
    }
    return 0;
}
