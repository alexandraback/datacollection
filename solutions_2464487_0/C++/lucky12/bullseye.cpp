#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;
int main()
{
    FILE *fp;
    fp=fopen("out1.txt","w");
    int x=0;
    int n;
    scanf("%d",&n);
    while(n--)
    {
        x++;
        long long int r,t;
        scanf("%lld%lld",&r,&t);
        long long int i=0,j=-1;
        while(t>=0)
        {
            j++;
            t=t-((2*i)+(2*r)+1);
            i=i+2;
        }
        fprintf(fp,"Case #%d: %lld\n",x,j);
    }
    return 0;
}
