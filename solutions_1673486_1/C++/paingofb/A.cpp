#include<iostream>
#define MIN(a,b) ((a)>(b)?(b):(a))
using namespace std;
double pr[199999];
double mul[199999];
int main(){
  int cas;
  cin>>cas;
  for(int ca=1;ca<=cas;++ca){
    int a,b;
    cin>>a>>b;
    for(int i=1; i<=a; ++i){
      cin>>pr[i];
    }
    mul[a] = 1;
    for(int i=a-1; i>=0; --i){
      mul[i] = mul[i+1]*pr[a-i];
    }
    double rtn = b+2;
    for(int i=0; i<a; ++i){
      rtn = MIN(rtn,(b-a+1+2*i)*mul[i]+(2*b-a+2+2*i)*(1-mul[i]));
    }
    cout<<"Case #"<<ca<<": ";
    printf("%.6f\n", rtn);
  }
}
