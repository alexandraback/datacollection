#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdio>
#include<map>
#include<cstring>

using namespace std;

struct OPList {
    int day;
    int w;
    int e;
    int s;
    bool operator<(const OPList& rhs) const {
        if(day != rhs.day) {
            return day < rhs.day;
        }
        if(s != rhs.s) {
            return s < rhs.s;
        }
    }
};

static const int LEN = 401;
static const int OFF = 200;
int Wall[LEN];

int attack(int w, int e, int s) {
    for(int i = w; i < e; ++i) {
        if(Wall[OFF + i] < s) {
            return 1;
        }
    }
    return 0;
}

void update(int w, int e, int s) {
    for(int i = w; i < e; ++i) {
        if(Wall[OFF + i] < s) {
            Wall[OFF + i] = s;
        }
    }
}

int main() {
    int C;
    cin >> C;
    for(int cases = 1; cases <= C; ++cases) {
        memset(Wall, 0, sizeof(Wall));
        
        int N;
        cin >> N;
        vector<OPList> v_op;
        for(int i=0; i <N; ++i) {
            int d, n, w, e, s, dd, dp, ds;
            cin>>d>>n>>w>>e>>s>>dd>>dp>>ds;
            for(int j=0; j<n;++j) {
                OPList o;
                o.day = d;
                o.w = w;
                o.e = e;
                o.s = s;
                
                d += dd;
                w += dp;
                e += dp;
                s += ds;
                v_op.push_back(o);
            }
        }
        
        sort(v_op.begin(), v_op.end());
        
        int ans = 0;
        int n_op = v_op.size();
        /*
        for(int i = 0; i<n_op;++i) {
            printf("%d [%d, %d] %d\n",
                v_op[i].day,
                v_op[i].w,
                v_op[i].e,
                v_op[i].s);
        } */

        int now = 0;
        while(now < n_op) {
            int d = v_op[now].day;
            int end = now + 1;
            while(end < n_op && v_op[end].day == d) {
                ++ end;
            }

            for(int i =now; i<end; ++i) {
                int s = v_op[i].s;
                int w = v_op[i].w;
                int e = v_op[i].e;
                ans += attack(w, e, s);
            }
            
            for(int i =now; i<end; ++i) {
                int s = v_op[i].s;
                int w = v_op[i].w;
                int e = v_op[i].e;
                update(w, e, s);
            }
            now = end;
        }
        printf("Case #%d: %d\n", cases, ans); 
    }
    return 0;
}

