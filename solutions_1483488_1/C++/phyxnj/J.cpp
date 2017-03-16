#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int pw[20];
int flag[2001000];
int idx;
int main()
{
    freopen("5.in","r",stdin);
    freopen("1.out","w",stdout);
    pw[0]=1;
    for(int i=1;i<10;i++) pw[i]=pw[i-1]*10;
    int T,ca=0;
    scanf("%d",&T);
    while(T--){
        int A,B;
        scanf("%d%d",&A,&B);
        idx++;
        int len=0;
        int x=A;
        while(x) { len++ ; x/=10;}
        int ans=0;
        for(int i=A;i<=B;i++){
            if(flag[i]==idx) continue;
            int t=i;
            int cnt=0;
            do {
                if(t>=A&&t<=B&&flag[t]<idx) {
                    flag[t]=idx;
                    cnt++;
                }
                t=t%pw[len-1]*10+t/pw[len-1];
            }while(t!=i);
            ans+=cnt*(cnt-1)/2;
        }
        printf("Case #%d: %d\n",++ca,ans);
    }
}
