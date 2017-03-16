
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

int vis[11] ; 
void apply(int num){
    while(num){
        vis[num%10] = true ; 
        num /= 10 ; 
    }
}

bool done(){
    for(int i = 0 ; i != 10 ; i++)
        if(!vis[i])
            return false ; 
    return true ; 
}

void sol(){
    int N ; 
    scanf("%d", &N) ; 
    if(!N){
        puts("INSOMNIA") ; 
        return ; 
    }
    memset(vis, 0, sizeof(vis)) ; 
    for(int i = 1 ; ; i++){
        apply(i*N) ; 
        if(done()){
            printf("%d\n", i*N) ; 
            return ; 
        }
    }
}

int main()
{
    int T ; 
    scanf("%d", &T) ; 
    for(int time = 1 ; time <= T ; time++){
        fprintf(stderr, "solving case (%d / %d)...\n", time, T) ; 
        printf("Case #%d: ", time) ; 
        sol() ; 
    }
    return 0 ; 
}


