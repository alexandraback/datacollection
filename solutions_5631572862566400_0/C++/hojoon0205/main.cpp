#include<stdio.h>
int n, arr[1010], ans, x[1010];
bool chk[1010], c;
void back(int num)
{
    int i, xx, yy;
    if(num==ans)
    {
        for(i=1; i<=ans; ++i)
        {
            if(i==ans) xx=1;
            else xx=i+1;

            if(i==1) yy=ans;
            else yy=i-1;

            if(arr[x[i]]==x[xx] || arr[x[i]]==x[yy]) continue;
            else break;
        }
        if(i<=ans) return;
        c=true;
        return;
    }
    ++num;
    if(c==true) return;
    for(i=1; i<=n; ++i)
    {
        if(chk[i]) continue;
        chk[i]=true;
        x[num]=i;
        back(num);
        chk[i]=false;
        x[num]=0;
    }
    return;
}
int main()
{
    freopen("input.txt","r", stdin);
    freopen("output.txt","w", stdout);
    int i, j, T, tt;
    scanf("%d", &T);
    for(tt=1; tt<=T; ++tt)
    {
        scanf("%d", &n);
        for(i=1; i<=n; ++i)
        {
            scanf("%d", &arr[i]);
        }
        c=false;
        for(ans=n; ans>=1; --ans)
        {
            back(0);
            if(c==true) break;
        }
        printf("Case #%d: %d\n", tt, ans);
    }
}
