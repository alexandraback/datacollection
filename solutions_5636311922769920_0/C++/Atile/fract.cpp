#include <cstdio>
#include <vector>

using namespace std;

long long int rec(long long int k, long long int c){
    if( c == 1 )
        return 1;

    return k * rec(k, c-1) - (k - c);
}

vector<long long int> solve(int k, int c){
    vector<long long int> ret;

    c = (c > k ? k : c);
    long long int limInf = rec(k, c);
    for(int i=c;i<=k;i++)
        ret.push_back(limInf++);

    return ret;
}

int main(){
    int T, K, C, S;
    vector<long long int> res;

    scanf("%d", &T);
    for(int caso=1;caso<=T;caso++){
        scanf("%d %d %d", &K, &C, &S);

        res = solve(K, C);
        if( res.size() <= S ){
            printf("Case #%d:", caso);
            for(int i=0;i<res.size();i++)
                printf(" %lld", res[i]);
            printf("\n");
        }
        else
            printf("Case #%d: IMPOSSIBLE\n", caso);
    }

    return 0;
}
