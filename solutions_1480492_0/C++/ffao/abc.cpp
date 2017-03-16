#include <algorithm>
#include <vector>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;
 
double eps = 1e-7; 
 
int A, B, T, N;
int teste = 0;

struct collision {
    int car1, car2;
    double time;
    bool type;
    
    bool operator<(collision ot) const {
        return time<ot.time;
    }
};

collision events[10000];
int cnt;

struct car {
    char c;
    int s, p;
};

car c[100];

int visited[100][100][100];
double memo[100][100][100];

int coll[100];

double max_time(int event, int state, int blocked) {
    if (visited[event][state][blocked]) return memo[event][state][blocked];
    //printf("%d %d %d\n", event, state, blocked);
    if (event == cnt) return 1e16;
    
    collision c = events[event];
    int a = 1<<c.car1;
    int b = 1<<c.car2;
    
    if (c.type == true) {
        blocked |= a;
        blocked |= b;
        coll[a]++;
        coll[b]++;
    }
    else {
        coll[a]--;
        coll[b]--;
        if (coll[a] == 0) blocked &= ~a;
        if (coll[b] == 0) blocked &= ~b;
    }
    
    /*if (event <= 5) {
        printf("event = %d, blocked = %d, state=%d\n",event,blocked,state);
    }*/
    
    if (c.type == true) {
        if (!(state&a) == !(state&b)) return c.time;
    }
    
    int new_state;
    double ans = -1;
    for (int i = 0; i < (1<<N); i++) {
        if (i & blocked) continue;
        new_state = state ^ i;
        ans = max(ans, max_time(event+1, new_state, blocked));
    }
    
    blocked ^= a;
    blocked ^= b;
    visited[event][state][blocked]=1;
    return memo[event][state][blocked]=ans;
}

int main() {
    events[0].type = false;
    events[0].car1 = 0;
    events[0].car2 = 0;
    events[0].time = 0;
    
    for (scanf("%d", &T); T; --T) {
        cnt = 1;
        memset(visited,0,sizeof(visited));
        memset(coll,0,sizeof(coll));
        coll[1]=2;
        
        printf("Case #%d: ", ++teste);
        
        int state = 0;
        int blocked = 0;
        scanf("%d", &N);
        for (int i = 0; i < N; i++) {
            scanf(" %c %d %d", &c[i].c, &c[i].s, &c[i].p);
            if (c[i].c == 'R') state ^= (1<<i);
        }
        
        for (int i = 0; i < N; i++) {
            for (int j = i+1; j < N; j++) {
                int p = c[j].p-c[i].p;
                double s = c[j].s-c[i].s;
                
                double st = (-5-p) / s;
                double end = (5-p) / s;
                
                //printf("collision between %d and %d %lf %lf\n",i,j,st,end);
                if (st < 0 && end < 0) continue;
                
                st = max(0.0,st);
                end = max(0.0,end);
                
                if (st > end) swap(st,end);
                
                if (st-eps > 0) {
                    events[cnt].car1=i;
                    events[cnt].car2=j;
                    events[cnt].time=st-eps;
                    events[cnt++].type=true;
                }
                else {
                    coll[1<<i]++;
                    coll[1<<j]++;
                    blocked |= 1<<i;
                    blocked |= 1<<j;
                }
                
                events[cnt].car1=i;
                events[cnt].car2=j;
                events[cnt].time=end+eps;
                events[cnt++].type=false;
            }
        }
        
        sort(events+1,events+cnt);
        
        /*for (int i = 0; i < cnt; i++) {
            printf("event %d is collision between %d and %d\n",i,events[i].car1,events[i].car2);
        }*/
        
        double ans = max_time(0, state, blocked);
        if (ans < 1e10) printf("%lf\n", ans);
        else printf("Possible\n");
    }
}
