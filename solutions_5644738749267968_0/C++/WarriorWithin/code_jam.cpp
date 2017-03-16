#include <iostream>
#include <stdio.h>
#include <vector>
#include <stack>
#include <queue>
#include <string.h>
#include <math.h>
#include <algorithm>

using namespace std;

int main()
{
    FILE *ptr = fopen("D-small-attempt0.in", "r");
   // FILE *ptr = fopen("input.txt", "r");
    int i, j, n, t;
    double weight;
    fscanf(ptr, "%d", &t);

    for(i=1; i<=t; i++)
    {
        fscanf(ptr, "%d", &n);
        vector <double> a, b;
        for(j=0; j<n; j++)
        {
            fscanf(ptr, "%lf", &weight);
            a.push_back(weight);
        }
        for(j=0; j<n; j++)
        {
            fscanf(ptr, "%lf", &weight);
            b.push_back(weight);
        }

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        int first = 0, second = 0;

        int startf = 0, starts = 0, endf = n-1, ends = n-1;
        for(j=0; j<n; j++)
        {
            if(a[startf]<b[starts])
            {
                startf++;
                starts++;
            }
            else
            {
                endf--;
                starts++;
                second++;
            }
        }

        startf = 0, starts = 0, endf = n-1, ends = n-1;
        for(j=0; j<n; j++)
        {
            if(a[startf]<b[starts])
            {
                startf++;
                endf--;
            }
            else
            {
                startf++;
                starts++;
                first++;
            }
        }



        cout<<"Case #"<<i<<": ";
        cout<<first<<" "<<second<<endl;

    }
    fclose(ptr);
    return 0;
}
