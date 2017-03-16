#include<cstdio>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include<map>
#include<iostream>
#include<cstdlib>
#include<queue>
#include<sstream>
#include<queue>
#include<ctype.h>
#include<cstring>


using namespace std;

#define re return
#define co continue
#define pb push_back
#define br break
#define sz size


#define pf printf
#define sf scanf

bool opt[1000+5];
int bff[1000+5];
int N;
int ans ;

void call(int d) {
    vector<int> orders;
        orders.clear();
        int i;
        for (i=1;i<=N;i++)
            if ( opt[i])
                orders.pb(i);
        sort(orders.begin(), orders.end());
        bool cutout = false;
        if ( orders.size() <= ans )
            cutout = true;
        do {
            for (i=0; i<orders.size();i++)
                if ( bff[  orders[i] ]  != orders[ (i+1)%orders.size() ] )
                    if ( bff[  orders[i] ]  != orders[ (i-1+orders.size())%orders.size() ])
                        br;
            if ( i==orders.size() && orders.size() > ans)
                ans = orders.size();
        }while(next_permutation(orders.begin(), orders.end()) && !cutout );
    if ( d==N+1) {
        return;
    }
    opt[d] =  true;
    call(d+1);
    opt[d] = false;
    call(d+1);
}
int main()
{
   freopen("C-small-attempt0.in","r",stdin);
   freopen("ans.txt","w",stdout);

    int test;
    cin>>test;
    int kase = 1;


    while ( test--) {
        int i;
        cin>>N;
        for (i=1;i<=N;i++)
            cin>>bff[i];
        ans = 0;
        fill(opt, opt+N+1,false);
        call(1);
        pf("Case #%d: %d\n",kase++, ans);
    }
    return 0;
}
