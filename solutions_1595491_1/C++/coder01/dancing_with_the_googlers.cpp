#include <iostream>
#include <fstream>
using namespace std;
int main(){
    ifstream in("bl.in");
    ofstream out("bl.out");
    int t,n,s,p,num,sum;
    int m1,m2;
    in>>t;
    for(register int i=1;i<=t;i++){
                 in>>n>>s>>p;
                 m1=3*p-2; m2=m1-2;
                 if (p==1) m2=1;
                 if (p==0) {m1=0; m2=0;}
                 sum=0;
                 for(register int j=0;j<n;j++){
                              in>>num;
                              if (num>=m1) sum++;
                              else if (num>=m2 && s>0) { sum++; s--;}
                 }
                out<<"Case #"<<i<<": "<<sum<<endl; 
    }
    return 0;
}
