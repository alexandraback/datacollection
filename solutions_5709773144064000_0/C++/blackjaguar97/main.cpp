#include <iostream>
#include<cstdio>
#include<iomanip>
#include<cstring>
using namespace std;
int T , Tn=0 ;
double timer , C , F , D , X , A;
int main(){
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
    cin>>T;
    while(T--){
        Tn++;
        timer=X=0.0; A=2.0;
        cin>>C>>F>>D;
        while( C/A + D/(F+A) < D/A ){
            timer+=C/A;
            A+=F;
        }
        printf("Case #%d: ",Tn);
        timer+=D/A;
        cout<<fixed<<setprecision(7)<<timer<<endl;
    }
}
