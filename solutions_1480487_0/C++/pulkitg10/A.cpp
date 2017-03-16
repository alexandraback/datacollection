#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<string>
#include<string.h>
#include<cstring>
#include<stack>
#include<queue>
#include<cassert>
#include<cmath>

using namespace std;

#define LL long long int 
#define PII pair<int,int> 
#define PB push_back
#define MP make_pair
#define INF 1000000000


int j[600],sum=0;
double cmax;
double getans(int x,int n){
       double lb=0,ub=1,mid,csum,cscr;int loop=800,i;
       lb=max(0.0,((cscr-j[x])/(double)sum));
       while(loop-- && lb<ub){
               mid=((lb+ub)/2.0);
               cscr=(double)j[x]+(double)sum*mid;
               csum=mid;
               for(i=1;i<=n;i++){
                       if(i==x)continue;
                       csum+=max(0.0,((cscr-(double)j[i])/(double)sum));
               }
               if(csum>1.0)
                       ub=mid;
               else        
                       lb=mid;
       }
       return mid*100.0;
}
int main(){
       int i,n,t,ts=1;
       scanf("%d",&t);
       while(t--){
               scanf("%d",&n);
               sum=0;
               cmax=0;
               for(i=1;i<=n;i++){
                       scanf("%d",&j[i]);
                       cmax=max(cmax,(double)j[i]);
                       sum+=j[i];
               }
               printf("Case #%d: ",ts++);
	       double x=0,sm=0;
               for(i=1;i<=n;i++){
                       printf("%.6lf ",(x=getans(i,n)));
		       sm+=x;
               }
//	       assert(fabs(sm-100)<0.1);
               printf("\n");
       }
       return 0;
}
