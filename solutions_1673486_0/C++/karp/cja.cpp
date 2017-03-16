#include <iostream>
#include <cstdio>
using namespace std;

int main(int argc, char** argv) {
	int tc,i;
    int a,b,c;
    double pi[1000],min,t;
	scanf("%d",&tc);
	for(int l=1; l <= tc;l++) {
	    scanf("%d %d\n",&a,&b);
        pi[a] = 1;
        scanf("%lf",&pi[a-1]);
        min = b+2;
        for(i = a-2; i>=0; i--) {
            scanf("%lf",&pi[i]);
            pi[i] = pi[i]*pi[i+1];
        }
        c = b-a+1;
        for(i = 0;i <=a; i++) {                     
            t = c*pi[i]+(c+b+1)*(1-pi[i]);
            if(min > t) min = t;
            c = c+2;                        
        }
        printf("Case #%d: %0.6lf\n",l,min);
	}
	return 0;
} 
