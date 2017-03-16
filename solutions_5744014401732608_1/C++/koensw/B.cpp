#include <bits/stdc++.h>

int mat[51][51];

int dpt[51];

void test(int k){
    for(int i=0; i<51; ++i) 
        for(int j=0; j<51; ++j) mat[i][j] = 0;
    
    unsigned long long N, M;
    std::cin >> N >> M;
    unsigned long long MX = (1ull << (N-2));
    
    for(int i=1; i<N; ++i){
        for(int j=i+1; j<N; ++j){
            mat[i][j] = 1;
        }
    }
    
    std::cout << "Case #" << k << ": ";
    if(M > MX){
        std::cout << "IMPOSSIBLE" << std::endl;
        return;
    }else{
        std::cout << "POSSIBLE" << std::endl;
    }
    
    if(M == MX) {
        mat[0][N-1] = 1;
        M--;
    }
    
    for(unsigned long long i=0; i<N-2; ++i){
        if(M & (1ull << i)){
            mat[0][N-i-2] = 1;
        }
    }
    
    dpt[N-1] = 1;
    for(int i=N-2; i>=0; --i){
        dpt[i] = 0;
        for(int j=i+1; j<N; ++j){
            if(mat[i][j]) dpt[i] += dpt[j];
        }
    }
    
    for(int i=0; i<N; ++i){
        for(int j=0; j<N; ++j){
            std::cout << mat[i][j];
        }
        std::cout << std::endl;
    }
}

int main(){
    int T;
    std::cin >> T;
    for(int i=1; i<=T; ++i){
        test(i);
    }
}
