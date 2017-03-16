#include <iostream> 
#include <fstream> 
#include <math.h> 
#include <stdlib.h> 
#include <stdio.h> 
#include <vector> 
#include <string> 
#include <iterator> 
#include <algorithm> 
#include <numeric> 
#include <utility> 
#include <map> 
#include <queue> 
#include <set> 
#include <stack> 
#include <sstream> 
#include <cctype> 
#include <assert.h> 
#include <list> 
#include <ext/hash_set> 
#include <ext/hash_map> 

using namespace __gnu_cxx; 
using namespace std; 

#define MP(a,b) make_pair(a,b) 
#define i64 long long 
#define pb push_back 
#define For(i,a,b) for(typeof(a) i=(a);i<(b);i++) 
#define Rev(i,a,b) for(typeof(a) i=(a);i>=(b);i--) 
#define FOREACH(V,it) for(typeof(V.begin()) it=V.begin();it!=V.end();it++) 
#define CLR(a,x) memset(a,x,sizeof(a)) 
#define ALL(x) x.begin(),x.end() 

/**********************************************************************************/ 
const int maxn = 100002;
double a[maxn];
int test,n,m;
int main(){
	scanf("%d",&test);
	FILE *f = fopen("output.txt","w");
	For(cas,1,test+1){
		scanf("%d%d",&n,&m);
		For(i,0,n)
			scanf("%lf",&a[i]);
		double ret = m+1;
		double cur =1;
		For(i,0,n+1){
			//printf("Current value at %d is %.6lf and val is %.lf\n",(i,cur,cur*((n-i)+(m-i)) + (1-cur)*(1+(n-i)+m));
			ret = min(ret, cur*((n-i)+(m-i)) + (1-cur)*(1+(n-i)+m+m-i) );
			cur = cur*a[i];
		}
		fprintf(f,"Case #%d: %.6lf\n", cas, ret+1);
	}
	return 0;
}
