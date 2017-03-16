/*
 * =====================================================================================
 *
 *       Filename:  password.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2012/4/28 9:11:33
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *        Company:  
 *
 * =====================================================================================
 */
#include <stdio.h>

int main()
{
    int n;
    int i,j,c;
    int a,b;
    double corr[100000];
    double min=1000000,pos=-1,pro;
    scanf("%d",&n);
    for(c=1;c<=n;c++)
    {
        scanf("%d%d",&a,&b);
        for(i=0;i<a;i++)
        {
            scanf("%lf",&corr[i]);
            if(i!=0)
            {
                corr[i]*=corr[i-1];
            }
        }
        min = b+2;
        for(i=1;i<=a;i++)
        {
            pro = (a-i)*2+b-a+1 + (1-corr[i-1])*(b+1);
            if(pro<min)
            {
                min=pro;
                pos = i;
            }
        }
        printf("Case #%d: %.6f\n",c,min);
    }
    return 1;
}
