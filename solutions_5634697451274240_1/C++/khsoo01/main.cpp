#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int tc,len;
char ipt[105];

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int i, cur, k;
    scanf("%d",&tc);
    for(k=1;k<=tc;k++) {
        scanf("%s",&ipt);
        cur = 0;
        len = strlen(ipt);
        for(i=1;i<len;i++) {
            if(ipt[i]!=ipt[i-1]) cur++;
        }
        printf("Case #%d: %d\n",k,cur+(ipt[len-1]=='-'?1:0));
    }
}
