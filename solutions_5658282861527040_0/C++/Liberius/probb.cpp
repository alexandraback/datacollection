#include <fstream>
#include <iostream>

using namespace std;

typedef unsigned long long data_t;
/*
data_t bitcut(data_t data, const data_t& standard){
    data_t mask=0, detect=1, oppomask=-1;
    for (size_t i = 0; i < 32; ++i){
        if (standard&detect){
            oppomask <<= 1;
            data=(data&oppomask)>>1 | (data&mask);
            oppomask >>=1;
        }else{
            mask <<=1;
            ++mask;
            oppomask <<=1;
        }
        detect <<=1;
    }
    return data;
}

data_t bitmax(size_t bit){
    return ((static_cast<data_t>(1))<<bit) -1;
}

data_t opposite(const data_t& opponent, const data_t& standard){
    return (~opponent) | standard;
}

data_t& part_increment(data_t& data, const data_t& standard){
    ++data;
    data|=standard;
    return data;
}

data_t real_max(data_t a, const data_t& standard){
    while( a && ((a&standard) != standard)){a--;}
    return a;
}
size_t mani_bit(data_t a){
    size_t result = 0;
    while (a>=256){
        a>>=8;
        result+=8;
    }
    while (a){
        a>>=1;
        ++result;
    }
    return result;
}

data_t test(const data_t& A, const data_t& B, const data_t& K){
    data_t result=0;
    for (data_t k = 0; k <= K; ++k){
        data_t a=0;
        while (opposite(a,k) > B){
            part_increment(a,k);
            if (a > A) break;
        }
        if (a > A) continue;
        result +=bitcut(real_max(A,k),k)-bitcut(a,k);
    }
    return result;
}
*/
data_t test(const data_t& A, const data_t& B, const data_t& K){
    data_t result=0;
    for (data_t a = 0; a < A; ++a)
        for(data_t b=0; b<B; ++b)
            if ((a&b) < K) ++result;
    return result;
}

int main(){
    size_t T;
    data_t a,b,k;
    ifstream ifp("input.txt");
    ofstream ofp("output.txt");
    ifp >> T;
    for (size_t i = 0; i < T; ++i){
        ifp >> a>>b>>k;
        ofp << "Case #" << i+1 << ": " << test(a,b,k) << endl;
    }
    ofp.close();
    ifp.close();
    return 0;
}