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

void MAIN()
{
    int n,j;
    scanf("%d%d",&n,&j);
    int a[100];
    int i=(1<<(n/2-1))-1;
    rep(fish,j)
    {
        i+=2;
        rep2(k,1,n/2) a[k]=0;
        LL tmp=i,k=0;
        while(tmp>0) {a[++k]=tmp%2;tmp/=2;}
        for(int k=n/2;k>=1;--k) printf("%d",a[k]);
        for(int k=n/2;k>=1;--k) printf("%d",a[k]);
        rep2(k,2,10)
        {
            tmp=0;
            for(int p=n/2;p>=1;--p) tmp=tmp*k+a[p];
            cout <<" "<<tmp;
        }
        cout << endl;
    }

};

int main() {
    freopen("C:\\Users\\Administrator\\ClionProjects\\gcj\\C-large.in","r",stdin);
    freopen("C:\\Users\\Administrator\\ClionProjects\\gcj\\C-large.out","w",stdout);
    int tt;
    scanf("%d",&tt);
    rep(i,tt)
    {
        printf("Case #%d:\n",i);
        MAIN();
    }
    return 0;
}