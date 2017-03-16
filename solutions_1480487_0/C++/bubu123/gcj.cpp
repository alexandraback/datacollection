#include <algorithm>
#include <vector>
#include <limits>
#include <sstream>
#include <iostream>
#include <map>
#include <stdio.h>

int main()
{
    int N;
    scanf("%d", &N);
    for(int i=0;i<N;i++)
    {
        int num;
        scanf("%d", &num);
        int sum = 0;
        std::vector<int> v;
        for(int k=0;k<num;k++)
        {
            int val;
            scanf("%d", &val);
            sum+=val;
            v.push_back(val);
        }
        int howmanyinneed = 0;
        double sumhowmanyinneed = 0.0;
        for(int k=0;k<num;k++)
        {
            if(v[k] < (double)2*sum/num)
            {
                howmanyinneed++;
                sumhowmanyinneed += (double)v[k];
            }
        }
        printf("Case #%d: ", i+1);
        for(int k=0;k<num;k++)
        {
            double res = 100*((((double)(sum+sumhowmanyinneed))/howmanyinneed)-v[k])/sum;
            if (res <0)
                res = 0.0;
            printf("%f ", res);
        }
        printf("\n");
    }
	return 0;
}

