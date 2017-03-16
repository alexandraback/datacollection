#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <string>
#define MAXN 2000
#define eps 1e-7
using namespace std;
double d,a,x[MAXN],t[MAXN],v,tt,cnt;
int N,As;
double SQ(double in){
	return in*in;	
}
int main()
{
	freopen("B-large.in","r",stdin);
	freopen("Bg.out","w",stdout);
    int T,ca,n,i,j,m;
    scanf("%d",&T);
    for(ca=1;ca<=T;++ca)
    {
        scanf("%lf%d%d",&d,&N,&As);
        for(i=0;i<N;++i)
        {
            scanf("%lf%lf",&t[i],&x[i]);
            if(x[i]>d){
				if(i==0){
					x[i]=d;
					continue;	
				}
				double tmpv =(x[i]-x[i-1])/(t[i]-t[i-1]);
				//d-x[i-1] = tmpv*t;
				t[i] = t[i-1]+(d-x[i-1])/tmpv;	
			}
        }
        printf("Case #%d:\n",ca);
        for(i=0;i<As;++i)
        {
            
			scanf("%lf",&a);
            double nowx = 0;
            double nowt = 0;
			double nowv = 0;
			for(int j=1;j<N;j++){ 
				
				double maxs = nowx + nowv*nowv*(t[j]-t[j-1]) + a*SQ(t[j]-t[j-1])/2;
			//	printf("%lf %lf %lf %lf\n",maxs,nowx,nowv,nowt);
				if(maxs >= x[j])
	            {
	                nowx = x[j];
	                nowt = t[j];
	            	nowv = (x[j]-x[j-1])/(t[j]-t[j-1]);
				}
	            else
	            {
	                nowx = maxs;
	                nowt = t[j];
	                nowv = nowv+(t[j]-t[j-1])*a;
				}
	        }
	        if(d -nowx < eps){
				printf("%lf\n",nowt);	
			}
			else{
				//d-nowx = nowv*t+a*t*t/2
				//(a/2)t*t+nowv*t +nowx-d =0;
				double A = a/2;
				double B = nowv;
				double C = nowx-d;
				double T = ((-1*B) + sqrt( SQ(B)-4*A*C ))/(2*A);
				printf("%f\n",nowt+T);
			}
		}

    }
    return 0;
}
