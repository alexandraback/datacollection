#include <iostream>
#include <vector>
#include <set>
#include <cmath>
#include <iomanip>
#include <inttypes.h>

using namespace std;

int T;
vector<int> res;
int64_t gcd(int64_t a, int64_t b){
    if(a<b)
        swap(a,b);
    while(b!=0){
        a = a % b;
        swap (a,b);
    }
    return a;
}
int64_t log2 (int64_t a){
    int64_t i=0;
    while(a>0){
        if(a==1){
            return i;
        }
        if(a % 2 !=0){
            return -1;
        }
        a/=2;
        i++;
    }
    return -1;
}

int64_t solve (int64_t P, int64_t Q){
    if(Q==1){
        return 0;
    }
    int i=1;
    while(true){
        if(P*2>=Q)
            return i;

        Q/=2;
        i++;
    }
}

int main(){
    cin>>T;
    res.resize(T+1);
    for(int t=1;t<=T;t++){
        int64_t  P,Q;
        scanf("%" SCNd64 "/%" SCNd64,&P,&Q);
        uint64_t g =gcd(P,Q);
        P /=g;
        Q /=g;
        uint64_t l;
        if(log2(Q)!=-1){
            l = solve(P,Q);
        }
        else{
            l=-1;
        }
        res[t]=l;
    }
    for(int t=1;t<=T;t++){

        cout<<"Case #"<<t<<": ";
        uint64_t r = res[t];
        if(r==-1){
            cout<<"impossible"<<endl;
        }
        else{
            cout<<r<<endl;
        }
    }
    return 0;
}