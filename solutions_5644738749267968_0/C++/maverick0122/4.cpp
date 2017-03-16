#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<string>
#include<iostream>
using namespace std;

const int N = 1010;
double a[N],b[N];

int cmp(const void *x, const void *y)
{
    return *(double*)x<*(double*)y?-1:1;
}

int main()
{
	freopen("D-small-attempt0.in","r",stdin);
	freopen("D-small-attempt0.out","w",stdout);
	
	int t;
	scanf("%d",&t);
	for(int cnt=1;cnt<=t;cnt++)
	{
		int n;
		scanf("%d",&n);
		for(int i=0; i<n; i++)
            scanf("%lf",a+i);
        for(int i=0; i<n; i++)
            scanf("%lf",b+i);
        
        qsort(a,n,sizeof(double),cmp);
        qsort(b,n,sizeof(double),cmp);
        
        int ans1 = 0, ans2 = 0;
        
        for(int i=0,j=0; i<n; i++)
        {
            for(; j<n && a[i]>b[j]; j++) ;
            if(j<n) {ans1++;j++;}
            else break;
        }
        ans1 = n-ans1;
        for(int i=0,j=0; i<n; i++)
        {
            if(a[i]>b[j]) 
            {
                ans2++;
                j++;
            }
        }
        
		printf("Case #%d: %d %d\n",cnt,ans2,ans1);
	} 
} 
