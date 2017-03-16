#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

int lis[2000001];

int main() {
    freopen("C.in","r",stdin);
    freopen("C.out","w",stdout);
    int testn;
    scanf("%d",&testn);
    for (int loop = 1; loop<=testn; ++loop) {
        int a,b;
        printf("Case #%d: ",loop);
        scanf("%d%d",&a,&b);
        char buf[16],tbuf[16];
        int ans = 0;
        for (int i = a; i<=b; ++i) {
        int co = 0;
            memset(buf,0,sizeof(buf));
            sprintf(buf,"%d",i);
            //printf("%s\n",buf);
            int len = strlen(buf);
            for (int j = 1; j<len; ++j) {
                int tmp = 0;
                for (int k = 0; k<len; ++k)
                    tmp = tmp*10+buf[(j+k)%len]-'0';
                    //printf(" - %d %d\n",i,tmp);
                memset(tbuf,0,sizeof(tbuf));
                sprintf(tbuf,"%d",tmp);
                int tlen = strlen(tbuf);
                if (len==tlen && tmp<i && tmp>=a)
                    lis[co++] = tmp;
            }
        sort(lis,lis+co);
        co = unique(lis,lis+co)-lis;
        ans += co;
        }
        printf("%d\n",ans);
    }
    return 0;
}
