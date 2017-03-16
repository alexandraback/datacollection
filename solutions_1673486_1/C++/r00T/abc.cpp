#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cctype>
#include<cstring>
#include<string>
#include<algorithm>
#include<stack>
#include<vector>
using namespace std;

int main()
{
    int tc;
    cin>>tc;
    for(int x = 1; x<= tc;x++)
    {
            int a,b;
            double e = 500000;
            scanf("%d %d",&a, &b);
            double arr[a],prob[a];
            scanf("%lf", &arr[0]);
            prob[0] = arr[0];
            for(int i = 1;i<a;i++)
            {
                  scanf("%lf", &arr[i]);
                  prob[i] = prob[i-1]*arr[i];
            }
            for(int i = 0; i<a;i++)
            {
                    double temp = prob[a-1-i]*(b-a+2*i+1) + (1-prob[a-1-i])*(2*b+2*i-a+2);
                    if(temp<e)
                        e = temp;
            }
            if(b+2 < e)
                   e = b+2;
            printf("Case #%d: %.6lf\n",x,e);
    }
    return 0;
}
    
              
