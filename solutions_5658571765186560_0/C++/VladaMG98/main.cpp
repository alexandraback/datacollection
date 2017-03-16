#include <bits/stdc++.h>
#define mid (lo+hi)/2
#define win1 printf("Case #%d: GABRIEL\n",test)
#define win2 printf("Case #%d: RICHARD\n",test)
using namespace std;
const bool SUBMIT=true;
const int MAXN=1010;
int arr[MAXN];
int main()
{
    if(SUBMIT)
    {
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    }
    int t;
    scanf("%d",&t);
    for(int test=1;test<=t;test++)
    {
        int x,r,c;
        scanf("%d%d%d",&x,&r,&c);
        if(r<c) swap(r,c);
        if(x==1) win1;
        else if(x==2)
        {
            if(r*c%2==0) win1;
            else win2;
        }
        else if(x==3)
        {
            if((r*c)%3==0&&r>2&&(c>1)) win1;
            else win2;
        }
        else if(x==4)
        {
            if(c>2&&r>3&&(r*c)%4==0) win1;
            else win2;
        }
        else if(x==5)
        {
            if(c>3&&r>4&&(r*c)%5==0) win1;
            else win2;
        }
        else if(x==6)
        {
            if(c>3&&r>5&&(r*c)%6==0) win1;
            else win2;
        }
        else win2;
    }
    return 0;
}
