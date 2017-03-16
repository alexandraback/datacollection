#include <iostream>
#include <fstream>
using namespace std;
int main(){
    ifstream in;
    in.open("B-large.in");
    ofstream out;
    out.open("large.out");
    int n;
    in>>n;
    for(int i=0;i<n;i++){
        int k,s,p,t,m(0);
        in>>k>>s>>p;
        for(int j=0;j<k;j++){
            in>>t;
            if(t>3*p-3&&t>=p)m++;
            else if(t>3*p-5&&s&&t>=p){m++;s--;};
            }
        out<<"Case #"<<i+1<<": "<<m<<endl;
        }
    }
