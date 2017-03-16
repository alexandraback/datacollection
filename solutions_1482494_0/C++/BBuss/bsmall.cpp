#include<cstdio>
#include<cstring>
#include<algorithm>
#include<utility>
#include<vector>
#include<deque>

using namespace std;

typedef struct {
    int v;
    int a1;
    int a2;
} lvl;

lvl v[1024];
int m[12];
int t, n;


int solve(){

    vector< pair<int, int> > tv;
    deque< pair<int, int> > qv;

    for(int i = 0; i < n; ++i){
        if(m[i] == 0){
            tv.push_back( make_pair(v[i].a2, -2));
        }
        else{
            tv.push_back( make_pair(v[i].a1, -1));
            tv.push_back( make_pair(v[i].a2, -1));
        }
    }

    sort(tv.begin(), tv.end());
    qv = deque< pair<int, int> >(tv.begin(), tv.end());

    int es = 0;

    while(!qv.empty()){
        if(qv.front().first <= es){
            es -= qv.front().second;
            qv.pop_front();
        }
        else break;
    }

    if(!qv.empty()) return 1000000;
    else return tv.size();

}

int bt(int i){

    if(i == n){
        return solve();        
    }
    else{
        int r1, r2;
        r1 = bt(i+1);

        m[i] = 1;
        r2 = bt(i+1);
        m[i] = 0;

        return min(r1, r2);
    }

}

int main(void){

    scanf("%d", &t);

    for(int i = 1; i <= t; ++i){

        scanf("%d", &n);
        memset(v, 0, sizeof(v));
        memset(m, 0, sizeof(m));

        for(int j = 0; j < n; ++j) scanf("%d %d", &v[j].a1, &v[j].a2);

        int min = bt(0);       

        if(min != 1000000) printf("Case #%d: %d\n", i, min);
        else printf("Case #%d: Too Bad\n", i);

    }
    
    return 0;
}
