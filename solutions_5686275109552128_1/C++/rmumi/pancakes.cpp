#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    int t,n;
    vector<int> ve;
    freopen("in","r",stdin);
    freopen("out","w",stdout);
    scanf("%d",&t);
    for(int CASE=1;CASE<=t;CASE++)
    {
        scanf("%d",&n);
        ve.resize(n);
        for(int i=0;i<n;i++)scanf("%d",&ve[i]);
        int k=*max_element(ve.begin(),ve.end());
        int min_br_k=100000000;
        auto f([&](int j){
                int br_k(0);
                for(int i=0;i<n;i++)
                    br_k+=(ve[i]-1)/j;
                br_k+=j;
              //  printf("%d %d\n",j,br_k);
                return br_k;
            }
            );
        int tren=0;
        for(int j=1;j<=k/* && tren<=min_br_k*/;j++)
            min_br_k=min(tren=f(j),min_br_k);

//        int donja=1,gornja=k;
//        while(donja<gornja)
//        {
//            if(donja==gornja-1)
//            {
//                if(f(donja)>f(gornja))
//                    donja=gornja;
//                break;
//            }
//            int mid1=(donja+gornja)/2;
//            int mid2=mid1+1;
//            if(f(mid1)<f(mid2))
//            {
//
//            }
//        }
        printf("Case #%d: %d\n",CASE,min_br_k);
        cerr<<CASE<<endl;
    }
    return 0;
}
