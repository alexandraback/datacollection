#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <map>
#include <set>
#include <vector>

const int N = 1e2+10;
const int inf = 1e9;

typedef long long ll;

using namespace std;

bool us[N];
int mp1[N][N],mp2[N][N],mp3[N][N];
vector<pair<int, pair<int,int>>> v;
int a,b,c,S,n;
bool rec(int s, int t)
{
    if (!t) {
//        for (int i = 0; i < n;++i)
//            printf("%d", us[i]);
//        puts("");
        bool f=1;
        for (int i = 0; i < n;++i)
            if (!us[i]) {
                int &x = ++mp1[v[i].first][v[i].second.first];
                int &y = ++mp2[v[i].second.second][v[i].second.first];
                int &z = ++mp3[v[i].second.second][v[i].first];
                if (x>S || y>S || z>S){
                    f = 0;
                    break;
                }
            }
        for (int i = 0; i < n;++i)
            if (!us[i]) {
                mp1[v[i].first][v[i].second.first]=mp2[v[i].second.second][v[i].second.first]=0;
                mp3[v[i].second.second][v[i].first]=0;
            }
//        puts("ok");
        return f;
    }
    if (s >= n)
        return false;
    for (int i = s; i < n; ++i) {
        us[i] = 1;
        bool r = rec(i+1, t-1);
        if (r)
            return 1;
        us[i] = 0;
    }
    return 0;
}

bool solve()
{
    scanf("%d%d%d%d",&a,&b,&c,&S);
    //printf("%d %d %d %d\n", a,b,c,S);
    n = a*b*c;
    v.clear();
    for (int i = 0; i < a; ++i)
        for (int j = 0; j < b; ++j)
            for (int k = 0; k < c; ++k)
                v.push_back({i+1,{j+1,k+1}});
    
    int l = 0, r = n;
    while (l<r) {
        int mid = (l+r)/2;
        memset(us,0,sizeof(us));
        
//        printf("%d %d %d\n", l,r,mid);
//        fflush(stdout);
        bool f = rec(0, mid);
        if (f)
            r = mid;
        else
            l = mid + 1;
    }
    memset(us,0,sizeof(us));
    rec(0,l);
    printf("%d\n",n - l);
    for (int i = 0; i < n; ++i)
        if (!us[i])
            printf("%d %d %d\n", v[i].first, v[i].second.first, v[i].second.second);
    fflush(stdout);
    return false;
}

int main()
{
        freopen("input.txt","r", stdin);
        freopen("output.txt", "w", stdout);
    int countTests;
    scanf("%d", &countTests);
    for (int curTest = 1; curTest <= countTests; ++curTest) {
        printf("Case #%d: ", curTest);
        solve();
    }
    
    return 0;
}
