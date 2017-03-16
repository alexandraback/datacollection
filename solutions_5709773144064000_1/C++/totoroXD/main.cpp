#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;
double c, f, x;
int kase=1;
double df(int i){// 0<f(i+1)-f(i)
    //printf("%lf\n",(2+(i+1)*f)*c - f*x);
    return (2+i*f)*c - f*x < 0;
}

void input(){
    scanf("%lf%lf%lf",&c,&f,&x);
}
void solve(){
    double res=1000000, sum=0;
    int d;
    for(d=0; df(d+1); d++){
        sum+= c/(2+d*f);
        //printf("d=%d %lf\n",d,sum);
    }
    //printf("d=%d\n",d);
    printf("Case #%d: ",kase++);
    printf("%lf\n",sum+x/(2+d*f));
}
int main()
{
    int zz;
    scanf("%d",&zz);
    while(zz--){
        input();
        solve();
    }
    return 0;
}
/*

4
30.0 1.0 2.0
30.0 2.0 100.0
30.50000 3.14159 1999.19990
500.0 4.0 2000.0


*/
