#include<cstdio>  
#include<cstring>  
#include<cctype>  
#include<cmath>  
#include<cstdlib>  
#include<ctime>  
#include<iostream>  
#include<iomanip>  
#include<sstream>  
#include<vector>  
#include<string>  
#include<queue>  
#include<stack>  
#include<utility>  
#include<algorithm>  
#include<map>  
#include<set>  
#include<bitset>  
#include<sstream>
using namespace std;
typedef long long int ll;

int main(){
    int T;
    double C,F,X;
    scanf("%d",&T);
    for(int caso=1;caso<=T;caso++){
        scanf("%lf%lf%lf",&C,&F,&X);
        int i=0;
        double soma=0.0, den=2.0;
        while(1){
            if(i>(X/C-2.0/F-1.0)){
                soma+=X/den;
                break;
            }
            soma+=C/den;
            den+=F;
            i++;
        }
        printf("Case #%d: %0.7lf\n",caso,soma);
    }
    return 0;
}
