//
//  main.cpp
//  Deceitful_War
//
//  Created by Yue Wang on 4/11/14.
//  Copyright (c) 2014 Yue Wang. All rights reserved.
//

#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
using namespace std;

int sol_w(vector<double> naomi, vector<double> ken)
{
    int point = 0;
    while(!naomi.empty())
    {
        auto last = naomi.end();
        last--;
        auto ken_it = lower_bound(ken.begin(), ken.end(), *last);
        if(ken_it == ken.end())
        {
            point += 1;
            ken_it = ken.begin();
        }
        ken.erase(ken_it);
        naomi.erase(last);
    }
    return point;
}

int sol_d(vector<double> naomi, vector<double> ken)
{
    int point = 0;
    while(!naomi.empty())
    {
        auto last_naomi = naomi.end();
        last_naomi--;
        auto last_ken = ken.end();
        last_ken--;
        if(*last_naomi < *last_ken)
        {
            naomi.erase(naomi.begin());
        }
        else
        {
            point += 1;
            naomi.erase(last_naomi);
        }
        ken.erase(last_ken);
    }
    return point;
}

int main(int argc, const char * argv[])
{
//    freopen("test.txt","r",stdin);
    // insert code here...
    int T,N,i;
    scanf("%d",&T);
    int cn = 1;
    while(T--)
    {
        scanf("%d",&N);
        vector<double> naomi;
        vector<double> ken;
        double tmp;
        for(i = 0;i < N;i++)
        {
            scanf("%lf",&tmp);
            naomi.push_back(tmp);
        }
        for(i = 0;i < N;i++)
        {
            scanf("%lf",&tmp);
            ken.push_back(tmp);
        }
        sort(naomi.begin(),naomi.end());
        sort(ken.begin(),ken.end());
        int y = sol_d(naomi, ken);
        int z = sol_w(naomi, ken);
        printf("Case #%d: %d %d\n",cn, y, z);
        cn += 1;
    }
    return 0;
}

