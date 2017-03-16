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

typedef pair<int,int> pii;

vector<pii> v;
int n;
int data[30];

void masuk(int bit)
{
    int sums = 0;
    FOR(i,0,n-1)
    {
        if((1 << i) & bit)
        {
            sums += data[i];
        }
    }
    v.push_back(pii(sums,bit));
}

void printSet(int bit)
{
    bool _b = false;
    FOR(i,0,n-1)
    {
        if((1 << i) & bit)
        {
            if(_b) printf(" ");
            else _b = true;
            printf("%d",data[i]);
        }
    }
    puts("");
}

int main()
{
    freopen("C-small-attempt0.in","r",stdin);
    freopen("C-small.out","w",stdout);
    int t;
    scanf("%d",&t);
    FOR(ca,1,t)
    {
        v.clear();
        scanf("%d",&n);
        FOR(i,0,n-1) scanf("%d",&data[i]);
        FOR(i,1,(1<<n)-1) masuk(i);
        sort(v.begin(),v.end());
        int ans = -1;
        FOR(i,0,v.size()-2)
        {
            if(v[i].first == v[i+1].first) 
            {
                ans = i;
                break;
            }
        }
        printf("Case #%d:\n",ca);
        if(ans != -1) 
        {
            printSet(v[ans].second);
            printSet(v[ans+1].second);
        }
        else puts("Impossible");
    }
    return 0;
}
