#include <stdio.h>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<cstdlib>
#include<stack>
#include<queue>
#include<string>
#include<cstring>
#define PR(x) printf(#x"=%d\n",x)
#define READ2(x,y) scanf("%d %d",&x,&y)
#define REP(i,a) for(int i=0;i<a;i++)
#define READ(x) scanf("%d",&x)
#define PRARR(x,n) for(int i=0;i<n;i++)printf(#x"[%d]=\t%d\n",i,x[i])
using namespace std;
int main()
	{
        double t,n,a[200];
        int j=0;
        scanf("%lf", &t);
        while(t--)
                {
                printf("Case #%d:", j+1);j++;
                double sm=0;
                scanf("%lf",&n);
                for(int i=0;i<(int)n;i++)
                	{
                	scanf("%lf", &a[i]);
                        sm += a[i];
                        }
                for(int i=0;i<(int)n;i++)
                {       
                        double ans=(2.00*(double)sm-a[i]*n)*100.00/(sm*n);
                        if(ans<0.00)
                                ans=0;
                        
                                printf(" %.6lf ",ans);              
                }       
                puts("");
        }
    	}
