#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cmath>

using namespace std;

int speed[2];
int start[2];

struct cross {
    double time;
    double dist1;
    double dist2;
};

cross getCross(int which) {
    double dist = start[1-which] + 360 - start[which];
    double speed1 = 360.0 / speed[which];
    double speed2 = 360.0 / speed[1-which];
    double shrink = max(speed1, speed2) - min(speed1, speed2);
    cross ans;
    ans.time = dist / shrink;
    ans.dist1 = speed1 * ans.time;
    ans.dist2 = speed2 * ans.time;
    return ans;
}

int main() {
    int TT, T;
    scanf("%d", &TT);
    for (T = 1; T <= TT; T++) {
        printf("Case #%d: ", T);
        int groups;
        scanf("%d", &groups);
        int i, j;
        int k = 0;
        for (i = 0; i < groups; i++) {
            int start2, num, speed2;
            scanf("%d%d%d", &start2, &num, &speed2);
            for (j = 0; j < num; j++) {
                start[k] = start2;
                speed[k] = speed2+j;
                k++;
            }
        }
        if (speed[0] == speed[1]) {
            printf("0\n");
            continue;
        }
        
        int behind = 0;
        if (start[1] > start[0])
            behind = 1;
        
        cross ret = getCross(behind);
        if (start[behind] + ret.dist1 > 720.0)
            printf("0\n");
        else
            printf("1\n");
        
    }
}
        