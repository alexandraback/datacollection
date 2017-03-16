#include <iostream>

using namespace std;

int ceil(int k, int c){
    if((k % c) == 0) return k / c;
    else return (k/c) + 1;
}

int64_t locate(int id, int64_t b, int c, int K, bool& done){
    if(id == K) {
        done = true;
        return b + (id-1);
    }
    if(c == 1) return b + (id-1);
    int64_t prod = 1;
    //k^c
    for(int i = 0; i < (c-1); i++){
        prod *= K;
    }
    b += (id-1)*prod;
    return locate(id+1,b,c-1,K,done);
}

int main()
{
    int T, cas = 0;
    cin >> T;
    while(T--){
        cas++;
        int K, C, S;
        cin >> K >> C >> S;
        if(ceil(K,C) > S){
            cout << "Case #" << cas << ": IMPOSSIBLE" << endl;
        } else {
            cout << "Case #" << cas << ":";
            bool done = false;
            for(int i = 1; i <= K && !done; i += max(1,C-1)){
                cout << " " << locate(i,1,C,K,done);
            }
            cout << endl;
        }
    }
    return 0;
}
