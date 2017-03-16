#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

#define rep(i,n) for (int i=1;i<=(n);++i)
#define rep2(i,x,y) for (int i=(x);i<=(y);++i)
#define pb push_back
#define mp make_pair
typedef long long LL;
typedef vector<int> VI;
typedef pair<int,int> PII;
typedef vector<PII> VII;
LL power[200][200];
void MAIN()
{
    int k,c,s;
    scanf("%d%d%d",&k,&c,&s);
    power[k][0]=1;
    rep(i,k) power[k][i]=power[k][i-1]*k;
    if (k>c*s) {cout << " IMPOSSIBLE" << endl; return; }
    int tmp=k%c==0?k/c:k/c+1;
    rep(i,tmp)
    {
        LL cur=0;
        int p=0;
        rep2(j,(i-1)*c,i*c-1)
        {
            if (j>=k) continue;
            cur=cur+power[k][p]*j;
            ++p;
        }
        cur++;
        cout << " " << cur;
    }
    //rep2(i,tmp+1,s) cout << " 1";
    cout << endl;
};

int main() {
    freopen("C:\\Users\\Administrator\\ClionProjects\\gcj\\D-large.in","r",stdin);
    freopen("C:\\Users\\Administrator\\ClionProjects\\gcj\\D-large.out","w",stdout);
    int tt;
    scanf("%d",&tt);
    rep(i,tt)
    {
        printf("Case #%d:",i);
        MAIN();
    }
    return 0;
}