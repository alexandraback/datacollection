#include<cstdio>
#include<string>
#include<vector>
using namespace std;

typedef unsigned long long int ull;

ull N, J, nj = 0;
vector<ull> factors;

string next(string prev){
    int i = prev.size() - 2;
    while(prev[i] == '1' && 0 < i){
        prev[i] = '0'; --i;
    }
    if(i == 0) return "DONE";
    prev[i] = '1';
    return prev;
}

bool isPrime(ull n){
    for(ull i = 2; i*i <= n; ++i){
        if((n % i) == 0){
            factors.push_back(i);
            return false;
        }
    }
    return true;
}

ull mstrtoi(const string& s, ull b){
    ull acc = 0;
    for(int i = 0; i < s.size(); ++i){
        acc = b*acc + (s[i] == '1' ? 1 : 0);
    }
    return acc;
}

int main(){
    scanf("%*d %llu %llu", &N, &J);
    printf("Case #1:\n");
    string p = "1";
    for(int i = 0; i < N-2; ++i) p = p + "0";
    p = p + "1";

    // REMOVE THIS
    /*
    p = "100011";
    factors.clear();
    for(ull b = 2; b <= 10; ++b){
        if(isPrime(mstrtoi(p, b))){
            goto next_p;
        }
    }
    printf("%s", p.c_str());
    for(int i = 0; i < factors.size(); ++i) printf(" %llu", factors[i]);
    printf("\n");
    next_p:;
    printf("Finished!\n");
    */

    for(; p != "DONE"; p = next(p)){
        factors.clear();
        for(ull b = 2; b <= 10; ++b){
            if(isPrime(mstrtoi(p, b))){
                goto next_p;
            }
        }
        printf("%s", p.c_str());
        for(int i = 0; i < factors.size(); ++i) printf(" %llu", factors[i]);
        printf("\n");
        if(++nj == J) break;
        next_p:;
    }
}
