#include <iostream>
#include <vector>
#include <set>
#include <cmath>
#include <iomanip>

using namespace std;

int T;
vector<int> res;

int main(){
    cin>>T;
    res.resize(T+1);
    for(int t=1;t<=T;t++){
        int N,M,K;
        cin>>N>>M>>K;
        int r=N*M;
        for(int a=0;a<=N-2;a++){
            for(int b=0;b<=M-2;b++){
                for(int k=0;k<=4;k++){
                    if(a*b+2*(a+b)+k>=K){
                        r = min(r,2*(a+b)+k);
                    }
                }
            }
        }
        res[t]=r;
    }
    for(int t=1;t<=T;t++){

        cout<<"Case #"<<t<<": "<<res[t]<<endl;
    }
    return 0;
}