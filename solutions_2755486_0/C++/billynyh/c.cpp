#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <vector>
#include <string>
#include <queue>
#include <iostream>
using namespace std;
#define N 1000
#define OFFSET 500

bool fless(double a,double b){ return b-a>1e-6; }
bool fequal(double a,double b){ return fabs(b-a)<=1e-6; }

struct Attack {
    int day, strength, w, e;

    bool operator<(const Attack &b) const {
        return day < b.day;
    }
};

struct Tribe{
    int d, n, w, e, s, delta_d, delta_p, delta_s;
    
    int read(){
        scanf("%d%d%d%d%d%d%d%d", &d, &n, &w, &e, &s, &delta_d, &delta_p, &delta_s);
        return 0;
    }

    Attack attack(int i) {
        Attack a = Attack();
        a.day = d + delta_d * i;
        a.strength = s + delta_s * i;
        a.w = w + delta_p * i + OFFSET;
        a.e = e + delta_p * i + OFFSET;
        return a;
    }
};

long long wall[N];


int main(){
    int tt; scanf("%d",&tt);
    for (int ti=1;ti<=tt;ti++){
        int n;
        scanf("%d", &n);
        vector<Attack> A;
        Tribe tribe[n];
        for (int i=0;i<n;i++) tribe[i].read();

        memset(wall, 0, sizeof(wall));

        for (int i=0;i<n;i++){
            for (int j=0;j<tribe[i].n; j++){
                A.push_back(tribe[i].attack(j));
            }
        }
        sort(A.begin(), A.end());

        int m = A.size();
        for (int i=0;i<m;i++){
        }

        long long ans = 0;
        for (int i=0;i<m;) {
            int day = A[i].day;
            int j = i+1;
            while (j<m && A[j].day == day) j++;
            // first step, sim all attacks on that day, count success
            for (int k=i;k<j;k++) {
                bool success = false;
                for (int pos = A[k].w; pos < A[k].e && !success; pos++) {
                    if (wall[pos] < A[k].strength) success = true;
                }
                if (success) ans ++;
                //printf("%d %d (%d %d): %d\n", A[k].day, A[k].strength, A[k].w, A[k].e,  success);
            }
            
            // second step, loop attacks and update wall
            for (int k=i;k<j;k++){
                for (int pos = A[k].w; pos < A[k].e; pos++) {
                    if (wall[pos] < A[k].strength) wall[pos] = A[k].strength;
                }
            }
            i = j;
        }


        printf("Case #%d: %lld\n",ti,ans);
    }
    return 0;
}

