#include <iostream>
#include <stdio.h>
#include <vector>
#include <stack>
#include <queue>
#include <string.h>
#include <math.h>

using namespace std;

int main()
{
    FILE *ptr = fopen("B-small-attempt0.in", "r");
    //FILE *ptr = fopen("input.txt", "r");
    int i, t;
    fscanf(ptr, "%d", &t);
    double cost, f, x;
    for(i=1; i<=t; i++)
    {
        fscanf(ptr, "%lf %lf %lf", &cost, &f, &x);
        double time = 100000000, temp = x/2, rate, invest;
        rate = 2;
        invest = 0;
        while(temp<time)
        {
            time = temp;
            invest += cost/rate;
            rate += f;
            temp = invest + (x/rate);
        }
        printf("Case #%d: %0.6lf\n", i, time);
    }
    fclose(ptr);
    return 0;
}
