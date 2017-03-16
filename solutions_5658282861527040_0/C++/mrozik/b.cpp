#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;


int main() {
       
    int T; cin>>T;
    for (int t=1; t<=T; t++) {
        cout<<"Case #"<<t<<": ";
        
        int A, B, K; cin>>A>>B>>K;
        int result = 0;
        for (int a=0; a<A; a++)
            for (int b=0; b<B; b++)
                if ((a&b)<K)
                    result++;
        
        cout<<result<<endl;
    }

    return 0;
}
