#include<stdio.h>


void swap(int &a,int &b)
{
    int tm = a;
    a = b;
    b = tm;
}

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int T;
    scanf("%d",&T);
    for(int t = 0; t<T; t++)
    {

        int x,r,c;
        scanf("%d%d%d",&x,&r,&c);
        if(r>c) swap(r,c);

        int win ;
        if((r*c)%x !=0) win = 1;
        else if(x>(r*c)) win = 1;
        else if(r==1&&x>=3) win = 1;
        else if(x>c) win = 1;
        else if(x==4&&r==2&&c==4) win = 1;
        else win = 2;


        printf("Case #%d: %s\n",t+1,(win==1)?"RICHARD":"GABRIEL");
    }
    return 0;
}
