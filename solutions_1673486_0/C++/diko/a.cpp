#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cctype>

#include<cmath>
#include<iostream>
#include<fstream>

#include<string>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
#include<set>
#include<sstream>
#include<stack>
using namespace std;
#define MX 100008
int n,a,b;
double pb[MX];

int main()
{
    freopen("a2.in","r",stdin);
    freopen("a.out","w",stdout);
    cin>>n;

for(int run=1;run<=n;run++){
    cin>>a>>b;
    pb[0]= 1.00;
    for(int i=1;i<=a;i++) cin>>pb[i];
    for(int i=1;i<=a;i++) pb[i]= pb[i-1]*pb[i];


    double ret= b+2;

    double da,db,dc;
    for(int i=0;i<=a;i++){
        da= pb[a-i]*(b-a+1+i+i);
        db= (1-pb[a-i])*(b-a+1+i+i+b+1);
        dc=da+db;
        ret=min(ret,dc);
    }


    printf("Case #%d: %0.6lf\n",run,ret);
}
    return 0;
}
// END CUT HERE
