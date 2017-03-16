//BISMILLAHIR RAHMANIR RAHIM
// OUM NAMA MA SWARASATI

#include<cmath>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cctype>
#include<fstream>
#include<string>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<sstream>
#include<stack>
#include<stdlib.h>
#include<iostream>
#include<algorithm>

#define AB push_back
#define MB pop_back
#define CL(vctr) vctr.clear()
#define MS(v,ar) memset(ar,v,sizeof(ar))
#define MP make_pair
#define F first
#define S second

#define MX(a,b) a>b?a:b
#define MN(a,b) a<b?a:b
#define ABS(x) x>0?x:-x

#define INF 1<<30
#define PI 2 * acos( 0 )
#define EPS 1E-9
#define SZ 100000+5
#define MOD 1000000000+7

using namespace std;
typedef long long int ll;

int main()
{
    freopen("A.txt","r",stdin);
    freopen("Ao.txt","w",stdout);
    int t,T;
    int r,c,w,a;
    scanf("%d",&t);
    T=t;
    while(t--)
    {
        scanf("%d %d %d",&r,&c,&w);
        int res;
        if(c%w==0)a=c/w+w-1;
        else
        {
//            if((c%w)<w-1)a=c/w+w-1;
//            else
            a=c/w+w;
        }
//        if(c==w||w==1)a=c;
//        else if(2*w>c)a=w+1;
//        else if(c==2*w)a=w+1;
//        else a=w+c/w;
        if(r>1)
        {
            res=(r-1)*(c/w);
            res+=a;
        }
        else
        {
            res=a;
        }
        printf("Case #%d: %d\n",T-t,res);
    }

    return 0;
}
