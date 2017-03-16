#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <vector>
#include <string>
#include <queue>
#include <iostream>
using namespace std;
#define N 2000000
#define OFFSET 500

bool fless(double a,double b){ return b-a>1e-6; }
bool fequal(double a,double b){ return fabs(b-a)<=1e-6; }

struct Attack {
    long long day, strength, w, e;

    bool operator<(const Attack &b) const {
        return day < b.day;
    }
};

struct Tribe{
    long long d, n, w, e, s, delta_d, delta_p, delta_s;
    
    int read(){
        scanf("%lld%lld%lld%lld%lld%lld%lld%lld", &d, &n, &w, &e, &s, &delta_d, &delta_p, &delta_s);
        return 0;
    }

    Attack attack(int i) {
        Attack a = Attack();
        a.day = d + delta_d * i;
        a.strength = s + delta_s * i;
        a.w = w + delta_p * i;
        a.e = e + delta_p * i;
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
        vector<long long> co;

        Tribe tribe[n];
        for (int i=0;i<n;i++) tribe[i].read();

        memset(wall, 0, sizeof(wall));

        for (int i=0;i<n;i++){
            for (int j=0;j<tribe[i].n; j++){
                Attack a = tribe[i].attack(j);
                A.push_back(a);
                co.push_back(a.w);
                co.push_back(a.e);
            }
        }

        sort(A.begin(), A.end());
        sort(co.begin(), co.end());
        co.erase(unique(co.begin(), co.end()) , co.end());

        int CN = co.size();
        //printf("CN %d\n", CN);

        /*
        for (int i=0;i<CN;i++) {
            printf("%lld ", co[i]);
        }
        puts("");
        */

        int m = A.size();

        long long ans = 0;
        for (int i=0;i<m;) {
            long long day = A[i].day;
            int j = i+1;
            while (j<m && A[j].day == day) j++;
            // first step, sim all attacks on that day, count success
            for (int k=i;k<j;k++) {
                bool success = false;
                int p1 = lower_bound(co.begin(), co.end(), A[k].w) - co.begin();
                int p2 = lower_bound(co.begin(), co.end(), A[k].e) - co.begin();

                for (int pos = p1; pos < p2 && !success; pos++) {
                    if (wall[pos] < A[k].strength) success = true;
                }
                if (success) ans ++;
                //printf("%d %d (%d %d): %d\n", A[k].day, A[k].strength, A[k].w, A[k].e,  success);
            }
            
            // second step, loop attacks and update wall
            for (int k=i;k<j;k++){
                int p1 = lower_bound(co.begin(), co.end(), A[k].w) - co.begin();
                int p2 = lower_bound(co.begin(), co.end(), A[k].e) - co.begin();
                for (int pos = p1; pos < p2 ; pos++) {
                    if (wall[pos] < A[k].strength) wall[pos] = A[k].strength;
                }
            }
            i = j;
        }
        
        /*
        for (int i=0;i<CN;i++) {
            printf("%lld ", wall[i]);
        }
        puts("");
        */



        printf("Case #%d: %lld\n",ti,ans);
    }
    return 0;
}

