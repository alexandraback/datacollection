#include <iostream>
#include <fstream>
using namespace std;
int main(){
    ifstream in;
    in.open("C-large.in");
    ofstream out;
    out.open("large.out");
    int n;
    in>>n;
    for(int i=0;i<n;i++){
        int A,B;
        in>>A>>B;
        int s(0),c(1);
        while(c*10<=A)c*=10;
        for(int j=A;j<B+1;j++){
            int k=j/10+c*(j%10);
            while(k!=j){
                if(A<=k&&B>=k)s++;
                k=k/10+c*(k%10);
                
                }
            }
        out<<"Case #"<<i+1<<": "<<s/2<<endl;
        }
    }
