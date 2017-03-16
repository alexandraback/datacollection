#include<cstdio>
using namespace std;
int main()
{
     freopen("C:\\Users\\Utkarsh\\Desktop\\input.in","r",stdin);
     freopen("C:\\Users\\Utkarsh\\Desktop\\out.txt","w",stdout);
    int t,r,l,c,i,j,k,ans;
    scanf("%d",&t);
    for(k=1;k<=t;k++)
    {
        scanf("%d %d",&r,&l);
        c=0;
        ans=0;
        while(1)
        {
            ans=(r+1)*(r+1)-(r*r);
            if(ans>l)
            break;
            l=l-ans;
            r=r+2;
            c++;
        }
        printf("Case #%d: %d\n",k,c);
    }
    return 0;
}
