//#define LOCAL
//#define SMALL
#include<bits/stdc++.h>
using namespace std;
const int maxn=1000+5;
char s[maxn];
deque<char> dq;
int main()
{
    #ifndef LOCAL
    #ifdef SMALL
    freopen("smallA.in","r",stdin);
    freopen("smallA.out","w",stdout);
    #else
    freopen("largeA.in","r",stdin);
    freopen("largeA.out","w",stdout);
    #endif
    #endif
    int kase=0,T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%s",s);
        int n=strlen(s);
        dq.clear();dq.push_back(s[0]);
        for(int i=1;i<n;i++)
        {
            bool isfront=1;
            for(int j=0;j<dq.size();j++) if(dq[j]>s[i]) {isfront=0;break;}
            if(isfront) dq.push_front(s[i]);
            else dq.push_back(s[i]);
        }
        printf("Case #%d: ",++kase);
        for(int i=0;i<dq.size();i++) printf("%c",dq[i]);puts("");
    }
}
