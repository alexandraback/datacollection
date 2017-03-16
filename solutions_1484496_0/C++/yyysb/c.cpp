#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
using namespace std;

int a[25],f[25][4500000],T,n,g[25][4500000][2],s;
int main(){
    freopen("C-small-attempt1.in","r",stdin);
    freopen("C-small-attempt1.out","w",stdout);
    scanf("%d",&T);
    for(int cs=1;cs<=T; ++cs){
        scanf("%d",&n);
        s=0;
        for(int i=1;i<=n;++i){
            scanf("%d",&a[i]);
            s+=a[i];
        }

        printf("Case #%d:\n",cs);
        memset(f,0,sizeof(f));
        f[0][s]=1;
        for(int i=1;i<=n;++i)
            for(int j=0;j<=s+s;++j)
                for(int k=0;k<i;++k){
                    if(j>=a[i] && f[k][j-a[i]]==1){
                        f[i][j] = 1;
                        g[i][j][0] = k;
                        g[i][j][1] = j-a[i];
                    }
                    if(j+a[i]<=s+s && f[k][j+a[i]]==1){
                        f[i][j] = 1;
                        g[i][j][0] = k;
                        g[i][j][1] = j+a[i];
                    }
                }
        int flag=0;
        for(int i=1;i<=n; ++i)
            if(f[i][s]==1){
                flag = 1;
                vector<int> tmp;
                int j=s;
                while(i!=0){
                    if(g[i][j][1]>j) printf("%d ",a[i]);
                        else tmp.push_back(a[i]);
                    int* p=g[i][j];
                    i=p[0];
                    j=p[1];
                }
                puts("");
                for(int i=0;i<tmp.size();++i)
                    printf("%d ",tmp[i]);
                puts("");
                break;
            }
        if(flag==0)puts("Impossible");
    }
    return 0;
}
