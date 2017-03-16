#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<vector>
#include<algorithm>
#include<iostream>
#include<set>
#include<map>
#include<list>
#include<string>
#include<stack>
#include<queue>
#include<sstream>
using namespace std;


#define ri(N) scanf("%d",&N)


int main()
{
    freopen("B-small-attempt1.in","r",stdin);
    freopen("B-small-attempt1.out","w",stdout);
    int i,j,k,l,m,n,t,kase=1;
    ri(t);
    while(t--)
    {
        double C,F,X;
        cin>>C>>F>>X;
        double total=0,cur_produc=2.0;
        while(1)
        {
            double t1=X/cur_produc;
            double t2=C/cur_produc+X/(cur_produc+F);
            if(t1-t2>1e-9)
            {
                total+=C/cur_produc;
                cur_produc+=F;
            }
            else
            {
                total+=t1;
                break;
            }
        }
        printf("Case #%d: %.7lf\n",kase++,total);
    }
return 0;
}

