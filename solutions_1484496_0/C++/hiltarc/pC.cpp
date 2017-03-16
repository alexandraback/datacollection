#include<cstdio>
#include<cstdlib>
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
int P[1000];
int sum1, sum2, ans;
deque<int> s1, s2, sv1, sv2;
bool used[1000];
bool flag;

void DFS(int now){
    if(!flag) return;
    if(now == N+1) return;
    if(sum1!=0 && sum2!=0 && sum1==sum2){
        for(int j = 0; s1.size(); j++){
            sv1.push_back(s1.front());
            s1.pop_front();
            }
        for(int j = 0; s2.size(); j++){
            sv2.push_back(s2.front());
            s2.pop_front();
            }
        flag = false;
        return;
        }
    sum1 += P[now];
    s1.push_back(P[now]);
    DFS(now+1);
    sum1 -= P[now];
    if(s1.size()) s1.pop_back();
    sum2 += P[now];
    s2.push_back(P[now]);
    DFS(now+1);
    sum2 -= P[now];
    if(s1.size()) s2.pop_back();
    DFS(now+1);
    return;
    }

int main(void){
    freopen("C-small-attempt0.in", "r", stdin);
    freopen("C-small-attempt0.out", "w", stdout);

    int T;
    scanf("%d", &T);

    for(int i = 1; i <= T; i++){
        while(s1.size()) s1.pop_back();
        while(s2.size()) s2.pop_back();
        while(sv1.size()) sv1.pop_back();
        while(sv2.size()) sv2.pop_back();
        scanf("%d", &N);
        for(int j = 0; j < N; j++) scanf("%d", &P[j]);
        sort(P, P+N);
        for(int j = 0; j < N; j++) used[j] = false;
        flag = true;
        sum1 = sum2 = 0;
        for(int j = 0; j<N&&flag; j++) DFS(j);
        printf("Case #%d:\n", i);
        for(int j = 0; sv1.size(); j++){
            if(j) printf(" ");
            printf("%d", sv1.front());
            sv1.pop_front();
            }
        puts("");
        for(int j = 0; sv2.size(); j++){
            if(j) printf(" ");
            printf("%d", sv2.front());
            sv2.pop_front();
            }
        puts("");
        }

    return 0;
    }
