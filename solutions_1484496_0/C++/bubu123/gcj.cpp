#include <algorithm>
#include <vector>
#include <limits>
#include <sstream>
#include <iostream>
#include <map>
#include <stdio.h>

typedef unsigned long long ull;


int main()
{
    int N;
    scanf("%d", &N);
    for(int i=0;i<N;i++)
    {
       int num;
       scanf("%d", &num); 
       std::map<ull, ull > m;
       printf("Case #%d:\n", i+1);
       int k=0;
       bool found = false;
       for(k=0;k<num;k++)
       {
           int val;
           scanf("%d", &val);
           if(found)
               continue;
           if(m.find(val) != m.end())
           {
                ull g = val;
                found = true;
                while(true)
                {
                    if(g == 0)
                        break;
                    //found = true;
                    printf("%ld ", g - m[g]);
                    g = m[g];
                }
                printf("\n");
                printf("%ld\n", val);
           }
           else
           {
               m.insert(std::make_pair(val, 0));
           }
           for(std::map<ull, ull >::iterator it = m.begin(); it != m.end(); ++it)
           {
               if(it->first == val)
                   break;
               if(m.find(it->first+val) != m.end())
               {
                   found = true;
                   ull g = it->first+val;
                   while(true)
                   {
                       if(g == 0)
                           break;
                       printf("%ld ", g - m[g]);
                       g = m[g];
                   }
                   printf("\n");
                   m[it->first+val] = it->first;
                   g = it->first+val;
                   while(true)
                   {
                       if(g == 0)
                           break;
                       printf("%ld ", g - m[g]);
                       g = m[g];
                   }
                   printf("\n");
                   break;
               }
               else
               {
                   m.insert(std::make_pair(it->first+val, it->first));
               }
           }
       }

       if(!found)
       {
           printf("Impossible\n");
       }
    }
   /*     int num;
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
    }*/
	return 0;
}

