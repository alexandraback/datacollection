#include <cstdio>
#include <string>
#include <iostream>
#define FOR(i,x,y) for(int i=x;i<=y;++i)
using namespace std;
int t,len;
char use[1010];
string s,ch;
int main()
{
    scanf("%d",&t);
    getchar();
    FOR(i,1,t)
    {
        printf("Case #%d: ",i);
        s.clear();
        scanf("%s",use);
        len=0;
        while(use[len]!='\0') ++len;
        s=use[0];
        FOR(j,1,len-1)
        {
            if(s[0]>use[j]) s=s+use[j];
            else s=use[j]+s;
        }
        cout<<s<<endl;
    }
    return 0;
}
