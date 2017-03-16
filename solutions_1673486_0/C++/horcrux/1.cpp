//author : Parag Gupta
//accepted in : 
// contest :
/* algo: 
*/

#include<cstdio>
#include<stdlib.h>
#include<limits.h>
#include<iostream>
#include<cstdlib>
#include<string>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<map>
#include<queue>
#include<vector>
#include<list>
#include<stack>
#include<queue>


using namespace std;
#define ll long long int
inline ll power(int base,int n);

#define MX 100005
#define f(x,y,z) for((x)=(y);(x)<(z);(x)++)
#define fe(x,y,z) for((x)=(y);(x)<=(z);(x)++)
#define fm(x,y,z) for((x)=(y) ; (x)>(z) ; (x)--)
#define FLUSH fflush(stdout)
#define copy(dest,src,size) memcpy(dest,src,size)
#define NL {printf("\n");}

int main(){
  double pc[MX];
  double pic[MX];
  int t,i,j,k,n;
  int a,b;
  double prob[MX] = {0};
  double ex[MX] = {0};
  scanf("%d",&t);
  for( j = 1; j<=t ;j++){
	scanf("%d %d",&a,&b);
	for( i=1;i<=a;i++){
	  scanf("%lf",&prob[i]);
	}
	pc[1] = prob[1];
	pic[1] = 1.0 - prob[1];
	for( i=2;i<=a;i++){
		pc[i] = pc[i-1]*prob[i];
		pic[i] = 1.0 - pc[i]; 
	}
	for(i=1;i<a;i++){
		ex[i] = pc[a-i]*( i + b-(a-i) + 1) + pic[a-i]* ( i + b-(a-i)+1 + b + 1);
	}
	ex[a] = a + b + 1;
	
	double keep = pc[a]*(b-a+1) + pic[a]*( b-a+1 + b +1 );
	double enter;
	if( a == b){
		enter = pc[a]*(1) + pic[a]*(1+b+1);
	}
	else{
		enter = 1+b+1;
	}

	double min = INT_MAX;
	min = min*1.0;
	for( i=1;i<=a;i++){
		if(ex[i] < min ) min = ex[i];
	}
	printf("Case #%d: ",j);
	if( min < enter && min < keep ){
	 	printf("%lf\n",min);
	}
	else if( enter < keep ){
	 	printf("%lf\n",enter);
	}
	else {
	 	printf("%lf\n",keep);
		
	}
  }


  return 0;
}
/* problem:
*/
inline ll power(int base,int n){
  ll ans=1;
  while(n){
    if(n&1==1) ans*=base;
    base*=base;
    n=(n>>1);
  }
  return ans;
}

