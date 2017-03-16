#include<stdio.h>
#include<string>
#include<string.h>
#include<algorithm>
#include<math.h>
#include<vector>
#include<queue>
#include<map>
using namespace std;

char x[100000000];
int arr[1005000];
string s;
int n;
int getVal()
{
    int m=0,ret=0,incr=0,hl=0;
    //printf("%s %d\n",s.c_str(),n);
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='a' || s[i]=='o' || s[i]=='e' || s[i]=='i' || s[i]=='u')
            m=0;
        else
        {
            m++;
        }
        //printf("m=%d\n",m);
//        if(hl)
//            ret+=incr;
        if(m>=n)
        {
            incr=i+1-n+1;
        }
        ret+=incr;

    }
    return ret;
}

int main()
{
    freopen("A-small-attempt0 (1).in","r",stdin);
    freopen("out.txt","w",stdout);
    int T;
    scanf("%d",&T);
    for(int t=1;t<=T;t++)
    {
        scanf("%s",x);
        s=x;
        scanf("%d",&n);
        printf("Case #%d: %d\n",t,getVal());
    }
}
