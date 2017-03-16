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

struct att{
    int day;
    int t;
    int w, e;
    int S;
    int dda;
    int dmo;
    int dS;
    bool operator <(att A) const{
        if(day != A.day) return day > A.day;
        return w < A.w;
    }
};

att data[100];
priority_queue<att, vector<att> > PQ;
int wall[1000];
pair<int, int> atts[100];
int th[100];

void solve(void){
    for(int i = 0; i < 1000; i++) wall[i] = 0;
    int N;
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
        scanf("%d%d%d%d%d%d%d%d", &data[i].day, &data[i].t, &data[i].w, &data[i].e, &data[i].S, &data[i].dda, &data[i].dmo, &data[i].dS);
    for(int i = 0; i < N; i++) PQ.push(data[i]);
    int now = -1;
    int ans = 0;
    int attsn = 0;
    while(!PQ.empty()){
        att tmp = PQ.top(); PQ.pop();
        if(tmp.day != now){
            for(int i = 0; i < attsn; i++)
                for(int j = atts[i]._F; j < atts[i]._S; j++)
                    wall[j+200] = max(wall[j+200], th[i]);
            attsn = 0;
        }
        bool flag = false;
        for(int i = tmp.w+200; i < tmp.e+200; i++)
            if(wall[i] < tmp.S) flag = true;
        if(flag){
            //printf("succ====%d %d %d %d\n", tmp.day, tmp.e, tmp.w, tmp.S);
            //printf("%d\n", wall[204]);
            ans++;
            atts[attsn]._F = tmp.w;
            atts[attsn]._S = tmp.e;
            th[attsn] = tmp.S;
            attsn++;
        }
        now = tmp.day;
        tmp.day += tmp.dda;
        tmp.t--;
        tmp.w += tmp.dmo;
        tmp.e += tmp.dmo;
        tmp.S += tmp.dS;
        if(tmp.t > 0) PQ.push(tmp);
    }
    printf("%d\n", ans);
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
