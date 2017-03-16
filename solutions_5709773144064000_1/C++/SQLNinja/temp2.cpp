#include<iostream>
#include<cstdio>
#include<cmath>
#include<sstream>
#include<ctime>
#include<cstring>
#define mp make_pair
#define pb push_back
#define max(a,b)a>b?a:b
#define min(a,b)a<b?a:b
using namespace std;
int t ;
double c , x , f;
double solve (double r);

int main (){
    freopen("in.txt","r",stdin);
    freopen("tmp.txt","w",stdout);

    int c = 1;
    scanf("%d",&t);
    while (t--) {
        scanf("%lf %lf %lf",&c,&f,&x);
        printf("Case #%d: %.7lf\n",c,solve(2));
        c++;
    }
    return 0;
}
double solve (double r){
    double s = c/r;
    double cont = (x-c)/r;
    if(cont<(x/(r+f))){
        return s+cont;
    }
    return s+ solve(r+f);
}
