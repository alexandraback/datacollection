#include <iostream>
#include <vector>
#include <deque>
using namespace std;

struct tr_t
{
    int day0;
    int nums;
    int left;
    int right;
    int power;
    int interval;
    int move;
    int inc_power;
    int next_day;
    tr_t(){}
    bool operator < (const tr_t& that) const{
        return this->next_day < that.next_day;
    }
};


#define MAX 10000000
int wall[MAX];
int new_wall[MAX];

int main()
{
    int T;
    scanf("%d", &T);
    for(int tcase=1; tcase <= T; ++tcase){
        int num_t;
        scanf("%d", &num_t);
        memset(wall, 0, sizeof(wall));
        memset(new_wall, 0, sizeof(new_wall));
        deque<tr_t> q;
        for(int i=0; i < num_t; ++i){
            tr_t t;
            scanf("%d %d %d %d %d %d %d %d",
                    &t.day0,
                    &t.nums,
                    &t.left,
                    &t.right,
                    &t.power,
                    &t.interval,
                    &t.move,
                    &t.inc_power);
            t.left = (t.left*2) + MAX/2;
            t.right = (t.right*2) + MAX/2;
            t.move *= 2;
            t.next_day = t.day0;
            q.push_back(t);
        }

        sort(q.begin(), q.end());
        long long ans = 0ll;
        while(!q.empty()){
            vector<tr_t> ts;
            while(!q.empty()){
                if(ts.empty())
                    ts.push_back(q.front());
                else if(q.front().next_day == ts[0].next_day)
                    ts.push_back(q.front());
                else
                    break;
                q.pop_front();
            }
            memcpy(new_wall, wall, sizeof(int)*MAX);
            for(int i=0; i < (int)ts.size(); ++i){
                tr_t t = ts[i];
                bool ok=false;
                for(int j=t.left; j <= t.right; ++j){
                    if(t.power > wall[j])
                        ok = true;
                    new_wall[j] = max(new_wall[j], t.power);
                }
                if(ok){
                    ans += 1;
                    fprintf(stderr, "%d ~ %d[", t.left, t.right);
                    for(int j=t.left; j<=t.right; ++j)
                        fprintf(stderr, "%d,", wall[j]);
                    fprintf(stderr, "], p:%d ok\n", t.left, t.right, t.power);
                }else{
                    fprintf(stderr, "%d ~ %d[", t.left, t.right);
                    for(int j=t.left; j<=t.right; ++j)
                        fprintf(stderr, "%d,", wall[j]);
                    fprintf(stderr, "], p:%d fail\n", t.power);
                }
                t.next_day += t.interval;
                t.left += t.move;
                t.right += t.move;
                t.power += t.inc_power;
                t.nums -= 1;
                if(t.nums > 0)
                    q.push_back(t);
            }
            sort(q.begin(), q.end());
            memcpy(wall, new_wall, sizeof(int)*MAX);
        }
        printf("Case #%d: %lld\n", tcase, ans);
    }
    return 0;
}

