using namespace std;
#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <sstream>
#include <fstream>
#include <cassert>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <map>
#include <set>
typedef long long LL;

int main(){
    freopen("c.in","r",stdin);
    freopen("c.out","w",stdout);
    int t;
    cin>>t;
    for (int time=1;time<=t;time++){
        int a,b,c,k;
        cin>>a>>b>>c>>k;
        cerr<<time<<endl;;
        cout<<"case #"<<time<<": ";
        int res=0;
        k=min(k,c);
        int cntab[20][20]={0};
        int cntbc[20][20]={0};
        int cntac[20][20]={0};
        int used[20][20][20]={0};
        cout<<a*b*min(c,k)<<endl;
        for (int i=1;i<=a;i++)
        for (int j=1;j<=b;j++)
        for (int l=1;l<=k;l++){
            int cur=j+l+i-1;
            cur=1+(cur-1)%c;
            cout<<i<<" "<<j<<" "<<(cur)<<endl;
            res++;

            cntab[i][j]++;
            cntbc[j][cur]++;
            cntac[i][cur]++;
            used[i][j][cur]++;
        }
        //if (res!=a*b*min(c,k)) cerr<<"error"<<endl;
        for (int i=1;i<=a;i++)
            for (int j=1;j<=b;j++)
        for (int l=1;l<=c;l++){
            if (used[i][j][l]>1) {cerr<<"e1"<<endl;cerr<<i<<j<<l<<endl;break;}
            if (cntab[i][j]>k) {cerr<<"e2"<<endl;cerr<<i<<j<<l<<endl;break;}
            if (cntbc[j][l]>k) {cerr<<"e3"<<endl;cerr<<i<<j<<l<<endl;break;}
            if (cntac[i][l]>k) {cerr<<"e4"<<endl;cerr<<i<<j<<l<<endl;break;}
        }
    }
    return 0;
}
