#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<functional>
#include<algorithm>
#include<limits>
#include<utility>
#define PB push_back
#define MP make_pair
#define _F first
#define _S second
#define PP system("PAUSE");

using namespace std;

int N;
char line[2000000];

bool cons(char A){
    if(A=='a') return false;
    if(A=='e') return false;
    if(A=='i') return false;
    if(A=='o') return false;
    if(A=='u') return false;
    return true;
}

void solve(void){
    for(int i = 0; i <= 1000000; i++) line[i] = 0;
    scanf("%s", line);
    scanf("%d", &N);
    int len = strlen(line);
    int con = 0;
    int last = -1;
    bool flag = false;
    long long int ans = 0;
    for(int i = 0; i < len; i++){
        if(cons(line[i])) con++;
        else con = 0;
        //printf("==%d:%d\n", i, con);
        if(flag && con<N) ans += (last+1);
        else if(con == N){
            last = (i-N+1);
            ans += (last+1);
            flag = true;
        }
        else if(con > N){
            last++;
            con--;
            ans += (last+1);
        }
        //printf("%d %I64d\n", i, ans);
    }
    printf("%I64d\n", ans);
    return;
}

int main(void){
    int T;
    scanf("%d", &T);
    for(int i = 1; i <= T; i++){
        printf("Case #%d: ", i);
        solve();
    }
    return 0;
}
