#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main(){
    ifstream inp("Bt.txt");
    ofstream outp("Bo.txt");
    int T, l, ans;
    string S;
    inp>>T;
    for(int i=1;i<=T;i++){
        outp<<"Case #"<<i<<": ";
        inp>>S;
        ans=0;
        l=S.length();
        S+="+";
        for(int j=0;j<=l-1;j++){
            ans+=(S[j]!=S[j+1]);
        }
        outp<<ans<<endl;
    }
    return 0;
}
        
    
