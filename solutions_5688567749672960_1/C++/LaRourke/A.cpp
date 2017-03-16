#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
using namespace std;

long long flip(long long N){
    long long N_out=0;
    while(N){N_out*=10; N_out+=(N%10); N/=10; }
    return N_out;
}

long long steps(long long N){
    //cout<<N<<endl;
    if (N<=19) return N;
    int digits = 0;
    long long N1 = N;
    int rem = 0;
    while(N1){rem = N1%10; digits++; N1/=10;}
    N1 = N;
    for(int i=0;i<(digits+1)/2;i++) N1/=10;
    for(int i=0;i<(digits+1)/2;i++) N1*=10;
    if (N1==N) return 1+steps(N-1);
    N1++;
    if (flip(N1)==N1){
        return (N-N1)+2+steps(N1-2);
    }
    return (N-N1)+1+steps(flip(N1));
    
}

int main() {
    //COunt backwards until second half of number are all 1s
    int T; cin>>T;
    for(int case_id = 1;case_id<=T;case_id++){
        long long N; cin>>N;
        printf("Case #%d: %lld\n", case_id, steps(N));
    }
}
