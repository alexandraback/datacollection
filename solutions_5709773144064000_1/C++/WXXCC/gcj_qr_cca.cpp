#include<iostream>
#include<string>
#include<cstdio>
#include<cstring>
#include<fstream>
#include<algorithm>
#include<map>
#include<stdlib.h>
#include <iomanip>
#include<vector>
#include<stack>
#include<queue>
#include<set>
using namespace std;
const double eps = 1e-12;
const double dinf = 99999999999.99;
int main()
{
    freopen("B1.in","r",stdin);
    freopen("B1.txt","w",stdout);
    int T;
    scanf("%d",&T);
    int cas = 1;
    while(T--){
        printf("Case #%d: ",cas);
        double c, f, x;
        double ans = dinf;
        scanf("%lf%lf%lf",&c,&f,&x);
        double numcok = 2, lastcoktime = 0;
        double tottime = 0;
        tottime = x/numcok;
        if(tottime < ans)
            ans = tottime;
        lastcoktime = 0;
        while(true){
            double tmptime = 0;
            tmptime = lastcoktime + c/numcok + x/(numcok + f);
            if(tmptime > ans)
                break;
            ans = tmptime;
            lastcoktime += c/numcok;
            numcok += f;
        }
        printf("%.10lf\n", ans);
        cas++;
    }
    return 0;
}
