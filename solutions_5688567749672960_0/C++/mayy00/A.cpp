#include <iostream>
#define N 1000002
using namespace std;

int dyn[N];

int reverse(int num){
    int x = 0;
    while(num){
        x=x*10 + num%10;
        num/=10;
    }
    return x;
}

int main(){
    int T;
    cin >> T;
    dyn[1] = 1;
    for(int i=2;i<=N;++i){
        if(i%10!=0){
            int r = reverse(i);
            if(r<i)
                dyn[i] = dyn[r]+1;
        }
        
        int m = dyn[i-1] + 1;
        if(m < dyn[i] || dyn[i] == 0)
            dyn[i] = m;
    }
        
    
    for(int t=1;t<=T;++t){
        int n;
        cin >> n;
        cout <<"Case #" << t << ": "<< dyn[n] << endl;
    }
    return 0;
}