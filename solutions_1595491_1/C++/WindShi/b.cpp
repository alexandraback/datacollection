#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

using namespace std;

int test,n,cnt,S,now,p;

int min(int i,int j){
    if (i<j) return(i);
    return(j);
}

int main(){
    freopen("1.txt","r",stdin);
    freopen("2.txt","w",stdout);
    scanf("%d",&test);
    for (int Q=1;Q<=test;Q++)
    {
        printf("Case #%d: ",Q); 
        scanf("%d%d%d",&n,&S,&p);
        int cnt=0,now=0;
        for (int i=1;i<=n;i++)
        {
            int x;
            scanf("%d",&x);
            if (x>=(p-1)*3+1) ++cnt;
            else if (x!=0 && x!=1 && x==(p-1)*3 || x==(p-1)*3-1) ++now;
        }
        printf("%d\n",cnt+min(S,now));
    }
}
