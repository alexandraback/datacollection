#include<iostream>

using namespace std;

int solve(){
    int N,S,p;
    int nosurp=0,surp=0,val;
    cin >> N >> S >> p;
    for(int i=0;i<N;i++){
        cin >> val;
        if (val>=3*p-2) nosurp++;
        else if (val>=3*p-4 && val>=2) surp++;
    }
    return nosurp+min(surp,S);
}

int main(){
    int T;
    cin >> T;
    for(int i=1;i<=T;i++){
        cout << "Case #" << i << ": " << solve() << "\n";
    }
    return 0;
}
