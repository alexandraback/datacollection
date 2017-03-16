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
#include<list>
#include<sstream>
using namespace std;


int a[1004],b[1004];
int v[1004];
int n;

int main()
{
    freopen("B.in","rt",stdin);
    freopen("B.out","wt",stdout);
    int tst,cas;
    scanf("%d",&tst);
    for(cas=1;cas<=tst;cas++) {
        scanf("%d",&n);
        int cmt=0;

        for(int i=0;i<n;i++) {
            scanf("%d%d",&a[i],&b[i]);v[i]=0;
        }
        int cur=0;
        int ans=0;

        while(1)
        {
            int to=-1;
            int mnn=-1;

            for(int i=0;i<n;i++) {
                if(v[i]!=2&&b[i]<=cur) {
                    to=i;
                    break;
                }
                else if(v[i]==0&&a[i]<=cur) {
                    if(b[i]>mnn) mnn=b[i],to=i;
                }
            }
            if(to==-1) break;
            if(b[to]<=cur) {


                if(v[to]==1) cur++;
                else cur+=2;
               // cout<<to<<" 2st "<<cur<<endl;
                v[to]=2,ans++,cmt++;
            }
            else if(a[to]<=cur) {
                v[to]=1,ans++,cur++;
               // cout<<to<<" 1st"<<" "<<cur<<endl;
            }
            if(cmt==n) break;

        }
        if(cmt==n) printf("Case #%d: %d\n",cas,ans);
        else printf("Case #%d: Too Bad\n",cas);


    }

    return 0;
}
