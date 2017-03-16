#include<iostream>
#include<fstream>
using namespace std;

long long pow(long long k, long long int c){
    long long int prod=1;
    while(c--){
        prod*=k;
    }
    return prod;
}

int main(){
    ifstream inp("Dt.txt");
    ofstream outp("Do.txt");
    long long int T, K, C, S, ans;
    inp>>T;
    for(int i=1;i<=T;i++){
        inp>>K>>C>>S;
        outp<<"Case #"<<i<<": ";
        if(((K-1)/C+1)>S){
            outp<<"IMPOSSIBLE"<<endl;
        }
        else{
            for(long long j=0;j<=(K/C)-1;j++){
                ans=0;
                for(long long id=1;id<=C;id++){
                    ans+=(K-j*C-id)*pow(K, id-1);
                    //outp<<(K-j*C-id)<<"x"<<pow(K, id-1)<<"+";
                }
                ans+=1;
                outp<<ans<<" ";
            }
            if(K%C!=0){
                ans=0;
                for(long long id=1;id<=(K%C-1);id++){
                    ans+=(K%C-id)*pow(K, id-1);
                    //outp<<(K%C-id)<<"x"<<pow(K, id-1)<<"+";
                }
                ans+=1;
                outp<<ans;
            }
            outp<<endl;
        }
    }
    return 0;
}
