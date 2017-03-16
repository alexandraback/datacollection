#include <cstdio>
#include <set>
#include <algorithm>
#include <random>
#include <ctime>
#include <iostream>
using namespace std;

int main(){
    int TC;
    scanf("%d", &TC);
    for(int tc = 1; tc <= TC; ++tc){
        int K, C, S;
        scanf("%d %d %d", &K, &C, &S);
        if(K > C*S) printf("Case #%d: IMPOSSIBLE\n", tc);
        else{
            printf("Case #%d:", tc);
            set<long long> s;
            for(int i = 0; i < K; i += C){
                long long t = 0, l = 1;
                for(int j = i; j < i+C && j < K; ++j, l *= K) t += l*j;
                s.insert(t);
            }/*
            for(long long i = 0; i < S; ++i){
                if(s.size() >= S) break;
                s.insert(i);
            }*/
            for(auto i : s) printf(" %lld", i+1);
            printf("\n");
        }
    }
}
    
    
