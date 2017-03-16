#include<iostream>
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
#include<string>
#include<set>
#include<map>
using namespace std;

long long C,D,V,p[110];

int main()
{
    freopen("C-small-attempt1.in","rb",stdin);
    freopen("test.out","wb",stdout);
    int T;scanf("%d",&T);
    for(int cas = 1 ; cas <= T; ++ cas){
        scanf("%lld%lld%lld",&C,&D,&V);
        for(int i=0;i<D;++i) scanf("%lld",&p[i]);
        sort(p,p+D);
        long long res = C, ans = 0;int ret = 0;
        if(p[ret] != 1) ++ans;
        else ++ret;
        while(res < V){
            while(p[ret] <= res + 1 && ret <D){
                //cout<<res<<' '<<ret<<endl;
                res += p[ret] * C;
                ++ret;
            }
            if(res >= V) break;

            ++ans;
            //cout<<"add::"<<res + 1<<' '<<ret<<endl;
            res += (res + 1) * C;
        }
        printf("Case #%d: %lld\n",cas,ans);
    }
    return 0;
}
/*
1 2 21
4 7
*/
