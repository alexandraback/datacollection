#include <iostream>
#include <cstdio>
#include <limits.h>
#include <string.h>
#include <algorithm>
#include <math.h>
using namespace std;



int main()
{
    freopen("myfile.txt","r",stdin);
    freopen("myfile2.txt","w",stdout);

    int t, number =1;
    scanf("%d",&t);
    while(number<=t)
    {
        int x,y;
        scanf("%d/%d",&x,&y);
        double fraction = (float)x/(float)y;
        int counter=0;
        while (fraction<1)
        {
            counter++;
            fraction*=2;

        }
        double check = log2((double)y);
        int tx = check;
        if(check-tx!=0)
            printf("Case #%d: impossible\n",number);
        else
            printf("Case #%d: %d\n",number,counter);
        number++;
    }
}
