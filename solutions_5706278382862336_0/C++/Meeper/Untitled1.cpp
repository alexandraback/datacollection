#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
using namespace std;
long long gcd(long long a, long long b){
    if (a==0) return b;
    else if (b==0) return a;
    else if (a>b) return gcd(a%b,b);
    else return gcd(a,b%a);
}
string asdf;
ifstream inp;
ofstream oup;
int main(){
    inp.open("input.txt");
    oup.open("output.txt");
    int T;
    inp>>T;
    getline(inp,asdf);
    for (int t=1; t<=T; t++){
    string poverq;
    getline(inp,poverq);
    int dummy;
    for (int i=0; i<poverq.length();i++){
        if (poverq[i]=='/'){
            dummy=i;
            break;   
        }
    }
    string uno;
    string duas;
    for (int i=0; i<dummy; i++){
        uno+=poverq[i];   
    }
    for (int i=dummy+1; i<poverq.length(); i++){
        duas+=poverq[i];
    }
    long long P=0;
    long long Q=0;
    for (int i=0; i<=dummy-1; i++){
        P+=-48+int(uno[i]);
        P*=10;   
    }
    for (int i=dummy+1; i<=poverq.length()-1; i++){
        Q+=-48+int(poverq[i]);
        Q*=10;
    }
    P/=10;
    Q/=10;

    long long gcdpq;    
    gcdpq=gcd(P,Q);
    P/=gcdpq;
    Q/=gcdpq;
    int pwrQ=-1;        //if error -1
    long long blah=2;
    for (int i=1; i<41; i++){
        if (Q==blah) pwrQ=i;
        blah*=2;
    }
    int ans=0;
    if (Q==P) ans=1;
    else{
        while(Q>P){
            ans++;
            Q/=2;   
        } 
        
    }
    if (pwrQ!=-1){
        oup<<"Case #"<<t<<": "<<ans<<endl;   
    }
    else{
        oup<<"Case #"<<t<<": impossible"<<endl;
    }
}
    
    
    
 system ("pause");   
}
