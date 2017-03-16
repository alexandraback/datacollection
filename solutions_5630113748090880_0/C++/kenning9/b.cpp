#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cassert>
#include <deque>
#include <vector>
using namespace std;
int TC;
int N, P[3000];
int main(){
    scanf("%d", &TC);
    for(int tc = 1; tc <= TC; ++tc){
        scanf("%d", &N);
        for(int i = 0; i < 3000; ++i) P[i] = 0;
        for(int i = 0, t; i < 2*N-1; ++i){
            for(int j = 0; j < N; ++j){
                scanf("%d", &t);
                P[t]++;
            }
        }
        vector<int> v;
        for(int i = 0; i < 3000; ++i){
            if(P[i]&1) v.push_back(i);
        }
        assert(v.size() == N);
        printf("Case #%d:", tc);
        for(int i = 0; i < v.size(); ++i){
            printf(" %d", v[i]);
        }
        printf("\n");
    }
}
        
