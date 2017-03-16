#include<stdio.h>
#include<algorithm>
using namespace std;
bool solve(int x,int r,int c)
{
    if (x>=9) return true;
    if ((r*c)%x!=0) return true;
    if (x<=2) return false;
    if(r>c) swap(r,c);
    int p,q;
    for(int i = 0;i<=x-1;i++){
        p = i+1;
        q = x-1-i+1;
        if(p>q) swap(p,q);
        if(p>r||q>c){
            return true;
        }
    }
    if(x==4&&r==2&&c==4)
        return true;
    return false;
}
int main ()
{
    int T,x,r,c;
    scanf("%d",&T);
    for(int _=1;_<=T;_++){
        scanf("%d%d%d",&x,&r,&c);
        printf("Case #%d: %s\n",_,solve(x,r,c)?"RICHARD":"GABRIEL");
    }
    return 0;
}