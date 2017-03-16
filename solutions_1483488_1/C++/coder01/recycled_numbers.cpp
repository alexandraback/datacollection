#include <iostream>
#include <fstream>
#include <set>
using namespace std;
int main(){
    ifstream in("cl.in");
    ofstream out("cl.out");
    int t,a,b,sum,num,dig;
    set<int> s;
    int c[6]={10,100,1000,10000,100000,1000000};
    
    in>>t;
    for(register int i=1;i<=t;i++){
                 in>>a>>b;
                 sum=0;
                 for(register int j=a;j<=b;j++){
                              dig=0; num=j;
                              if (num/1000>0) {num/=1000; dig+=3;}
                              if (num/100>0) {num/=100; dig+=2;}
                              if (num/10>0) dig+=2; else dig++;
                              num=j; s.clear();
                              for(register int k=1;k<dig;k++){
                                           num=c[dig-2]*(num%10)+num/10;
                                           if (num>j && num<=b) s.insert(num);
                              }
                              sum+=s.size();
                 }
                 out<<"Case #"<<i<<": "<<sum<<endl;
    }
    return 0;
}
