
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
#include <stack>
#include <set>
#include <map>

using namespace std ; 

typedef long long ll ; 

int stat[11111] ; 

void sol(){
    int N ; 
    scanf("%d", &N) ; 
    memset(stat, 0, sizeof(stat)) ; 
    for(int i = 0 ; i != N*2-1 ; i++){
        for(int j = 0 ; j != N ; j++){
            int now ; 
            scanf("%d", &now) ; 
            stat[now]++ ; 
        }
    }
    vector<int> v ; 
    for(int i = 1 ; i <= 2500 ; i++)
        if(stat[i]&1)
            v.push_back(i) ; 
    sort(v.begin(), v.end()) ; 
    if(v.size() != N)
        fputs("SOMETHING WRONG", stderr) ; 
    for(int i = 0 ; i != v.size() ; i++)
        printf(" %d", v[i]) ; 
    puts("") ; 
}

int main()
{
    int T ; 
    scanf("%d", &T) ; 
    for(int time = 1 ; time <= T ; time++){
        fprintf(stderr, "solving case (%d / %d)...\n", time, T) ; 
        printf("Case #%d:", time) ; 
        sol() ; 
    }
    return 0 ; 
}


