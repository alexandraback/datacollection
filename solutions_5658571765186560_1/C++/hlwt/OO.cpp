#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("D-large.in","r",stdin);
    freopen("D-large.out","w",stdout);
    int T,cas=0;
    scanf("%d",&T);
    while(T--) {
        int x,r,c;
        scanf("%d%d%d",&x,&r,&c);
        if(r>c)
            swap(r,c);
        printf("Case #%d: ",++cas);
        if((r*c)%x) {
            printf("RICHARD\n");
            continue;
        }
        if(x<=r) {
            printf("GABRIEL\n");
            continue;
        }
        if((x+1)/2>r) {
            printf("RICHARD\n");
            continue;
        }
        if(x>c) {
            printf("RICHARD\n");
            continue;
        }
        int tot=x-r,fuck=0;
        for(int i=0;i<=tot;i++) {
            int j=tot-i,flag=0;
            for(int pos=1;pos<=c;pos++) {
                int left=(pos-1)*r-i;
                int righ=(c-pos)*r-j;
                if(left>=0&&righ>=0&&(left%x==0)&&(righ%x==0)) {
                    flag=1;
                    break;
                }
            }
            if(flag==1)
                continue;
            else {
                fuck=1;
                break;
            }
        }
        if(fuck==1)
            printf("RICHARD\n");
        else
            printf("GABRIEL\n");
    }
    return 0;
}
