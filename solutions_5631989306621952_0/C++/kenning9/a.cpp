#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cassert>
#include <deque>
using namespace std;
int TC;
char str[10000], ret[10000];
int N;
int main(){
    scanf("%d", &TC);
    for(int tc = 1; tc <= TC; ++tc){
        scanf("%s", str);
        N = strlen(str);
        deque<char> res;
        for(int i = 0; i < N; ++i){
            if(res.empty()) res.push_back(str[i]);
            else{
                if(res.front() <= str[i]) res.push_front(str[i]);
                else res.push_back(str[i]);
            }
        }
        assert(res.size() == N);
        for(int i = 0; i < N; ++i) ret[i] = res[i];
        ret[N] = 0;
        printf("Case #%d: %s\n", tc, ret);
    }
}
        
