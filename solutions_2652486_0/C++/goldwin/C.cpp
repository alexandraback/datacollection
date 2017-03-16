#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define FOR(a,b,c) for(int (a) = (b), _n = (c); (a) <= _n ; (a)++)
#define FORD(a,b,c) for(int (a) = (b), _n = (c) ; (a) >= _n ; (a)--)
#define FOR_N(a,b,c,n) for(int (a) = (b), _m = (n), _n = (c) ; (a) <= _n ; (a)+= _m )
#define FORD_N(a,b,c,n) for(int (a) = (b), _m = (n), _n = (c) ; (a) >= _n ; (a)-= _m)
#define EACH(v,it) for(__typeof(v.begin()) it = v.begin(); it != v.end() ; it++)
#define INF 200000000
#define MAX 1

using namespace std;

int r,n,m,k;
int res[100];
int arr[100];
bool flags[100];

int findProduct(int bits)
{
    int ret = 1;
    FOR(i,0,n-1)
    {
        if((bits & (1 << i))) ret *= res[i];
    }
    return ret;
}

bool test()
{
    //cerr << "=============================================" << endl;
    //FOR(i,0,n-1)cerr << res[i] << " ";
    //cerr << endl;
    int cnt = (1 << n)-1;
    memset(flags,false,sizeof(flags));
    FOR(bits,0,cnt)
    {
        int x = findProduct(bits);
        //cerr << x << endl;
        FOR(i,0,k-1)
        {
            if(arr[i] / x == 1 && arr[i] % x == 0) 
            {
                flags[i] = true;
                //cerr << arr[i] << " / " << x << endl;
            }
        }
    }
    //FOR(i,0,k-1) cerr << flags[i] << " ";
    //cerr << endl;
    FOR(i,0,k-1) if(!flags[i]) return false;    
    return true;
}

bool bt(int ind)
{
    if(ind == n)
    {            
        bool b = test();
        //cerr << " " << b << endl;
        if(b) return true;
        return false;
    }
    FOR(i,2,m)
    {
        res[ind] = i;
        if(bt(ind+1)) return true;
    }
    return false;
}

int main()
{
    freopen("C-small-1-attempt0.in","r",stdin);
    freopen("C-small-1.out","w",stdout);
    int t;
    scanf("%d",&t);
    FOR(ca,1,t)
    {
        scanf("%d %d %d %d",&r,&n,&m,&k);
        printf("Case #%d:\n",ca);
        while(r--)
        {
            FOR(i,0,k-1) scanf("%d",&arr[i]);
            bt(0);
            FOR(i,0,n-1) printf("%d",res[i]);
            puts("");
        }
    }
    return 0;
}
