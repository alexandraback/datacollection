#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;
int mark[10000005];
int t,r,a,b,nub,digit;
long long temp,ans;
void go(int h) 
{
        if(mark[h]==r) return;
        if(h>=digit && h>=a && h<=b) {
                //printf("%d %d %d\n",h,digit,h/10+(h%10)*digit);
                nub++;
        }
        mark[h]=r;
        int newnum = h/10+(h%10)*digit;
        go(newnum);
}
int main()
{
        freopen("in-small-C.txt","r",stdin);
        freopen("out-small-C.txt","w",stdout);
        scanf("%d",&t);
        for(r=1;r<=t;r++)
        {
                scanf("%d %d",&a,&b);
                ans=0;
                for(int i=a;i<=b;i++)
                {
                        if(mark[i]!=r)
                        {
                                nub=0;
                                for(digit=1;digit<=i;digit*=10);
                                digit/=10;
                                go(i);
                                temp = nub;
                                temp *= (temp-1);
                                temp/=2;
                                ans+=temp;
                                //system("pause");
                        }
                }
                printf("Case #%d: %I64d\n",r,ans);
        }
}
