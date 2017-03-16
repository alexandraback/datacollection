#include<map>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int n,a[21];

map<int,int> h;

int main(){
    int _,cas=0;
    for(scanf("%d",&_);_--;){
        scanf("%d",&n);
        for(int i=0;i<n;++i)
            scanf("%d",a+i);
        h.clear();
        int ok1=0,ok2=0;
        for(int i=0;i<(1<<20);++i){
            int tmp=0;
            for(int j=0;j<n;++j)
                if(i&(1<<j))
                    tmp+=a[j];
            if(h.find(tmp)!=h.end()){
                ok1=h[tmp];
                ok2=i;
                break;
            }
            else h[tmp]=i;
        }
        if(!ok1&&!ok2)puts("Impossible");
        else{
            printf("Case #%d:\n",++cas);
            for(int i=0,j=0;i<n;++i)
                if(ok1&(1<<i)){
                    if(j)putchar(' ');
                    else ++j;
                    printf("%d",a[i]);
                }
            puts("");
            for(int i=0,j=0;i<n;++i)
                if(ok2&(1<<i)){
                    if(j)putchar(' ');
                    else ++j;
                    printf("%d",a[i]);
                }
            puts("");
        }
    }
    return 0;
}
