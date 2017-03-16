//#define LOCAL
//#define SMALL
#include<bits/stdc++.h>
using namespace std;
const int maxn=50+5;
const int maxc=3000;
int show[maxc];
int main()
{
    #ifndef LOCAL
    #ifdef SMALL
    freopen("smallB.in","r",stdin);
    freopen("smallB.out","w",stdout);
    #else
    freopen("largeB.in","r",stdin);
    freopen("largeB.out","w",stdout);
    #endif
    #endif
    int kase=0,T;
    scanf("%d",&T);
    while(T--)
    {
        memset(show,0,sizeof show);
        vector<int> num;
        int N;
        scanf("%d",&N);
        for(int i=0;i<N*2-1;i++)
            for(int j=0,x;j<N;j++) {scanf("%d",&x);show[x]++;}
        for(int i=0;i<maxc;i++) if(show[i]&1) num.push_back(i);
        sort(num.begin(),num.end());
        printf("Case #%d:",++kase);
        for(int i=0;i<num.size();i++) printf(" %d",num[i]);puts("");
    }
}
