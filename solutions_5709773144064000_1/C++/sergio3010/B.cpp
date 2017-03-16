#include <bits/stdc++.h>




using namespace std;







#define fr(i,a,b) for(int i=a;i<b;++i)



double tf,c,x,f;
int t;


int main(){
	scanf("%d",&t);
	fr(cas,1,t+1){
		scanf("%lf %lf %lf",&c,&f,&x);
		tf = 0;
		double ans = x/2.0;
		int men = 0;
		fr(i,1,1000100){
			tf = tf + c/(2.0+(i-1)*f);
			if(tf + x/(2.0 + i*f) < ans){ 
				ans = tf + x/(2.0 + i*f);
				men = i;
			}
		}
		printf("Case #%d: %.7lf\n",cas,ans);
	}
	return 0;
}