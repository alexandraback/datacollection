#include<iostream>
#include<cstdio>
#include<cmath>
#include<sstream>
#include<ctime>
#include<cstring>
#define mp make_pair
#define pb push_back
#define max(a,b)a>b?a:b
#define min(a,b)a<b?a:b
#include<cstdlib>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>
#include<map>
#include<set>

using namespace std;

int main (){
    freopen("in.txt","r",stdin);
    freopen("tmp.txt","w",stdout);

    int c = 1;
    scanf("%d",&t);
    while (t--) {
        scanf("%lf %lf %lf",&c,&f,&x);
        printf("Case #%d: %.7lf\n",c,solve(2));
        c++;
    }
    return 0;
}
