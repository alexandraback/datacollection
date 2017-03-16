#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;

int Rev(int x) {
    int dig[20] , n = 0 ;
    while(x) dig[n++] = x % 10 , x /= 10 ;
    int ret = 0 ;
    for(int i=0; i<n; i++) ret = ret * 10 + dig[i] ;
    return ret ;
}


int main()
{
    freopen("A-small-attempt1.in", "r", stdin);
    freopen("out.txt", "w", stdout) ;

    int T , cas = 1;
    scanf("%d", &T) ;
    while(T--){
        int N ;
        scanf("%d", &N)  ;
        map<int , int >step ;
        queue<int> Q ;
        Q.push(1) , step[1] = 1 ;
        int ans  ;
        while(!Q.empty()) {
            int u = Q.front() ; Q.pop() ;
            if(u == N) {
                ans = step[u] ;
                break ;
            }
            int v = u + 1 , ns = step[u] + 1 ;
            if((!step.count(v) || ns < step[v]) && v<=N ) {
                step[v] = ns  ;
                Q.push(v) ;
            }

            v = Rev(u) ;
            if((!step.count(v) || ns < step[v]) && v<=N ) {
                step[v] = ns  ;
                Q.push(v) ;
            }
        }

        printf("Case #%d: %d\n" , cas++ , ans) ;
    }
    return 0;
}
