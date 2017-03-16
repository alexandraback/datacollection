/*
 * Author: Lixiang Liu
 * Created Time:  2012/4/28 9:35:24
 * File Name: \TopCoder\gcj2012\R1A\B.cpp
 */
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

typedef struct star_t {
    int id;
    int a, b;
};

bool bcmp(const star_t &a, const star_t &b) {
    if (a.b == b.b) {
        return a.a > b.a;
    }
    return a.b < b.b;
}

bool acmp(const star_t &a, const star_t &b) {
    return a.a < b.a;
}

int main() {
    FILE *fin, *fout;    
    fin = fopen("D:\\TopCoder\\gcj2012\\R1A\\B-small-attempt3.in", "r");
    fout = fopen("D:\\TopCoder\\gcj2012\\R1A\\B.out", "w");
    int T;
    fscanf(fin, "%d\n", &T);
    for (int ca = 1; ca <= T; ca++) {
        int N;
        fscanf(fin, "%d", &N);
        star_t star[N], cs[N];
        for (int i = 0; i < N; i++) {
            fscanf(fin, "%d %d", &star[i].a, &star[i].b);
            star[i].id = i;
            cs[i].a = star[i].a, cs[i].b = star[i].b, cs[i].id = i;
        }
        sort(star, star+N, bcmp);
        sort(cs, cs+N, acmp);
        
        
        int ans = 0, me = 0;
        int vis[N];
        bool yes = true;
        memset(vis, 0, sizeof(vis));
        
        for (int i = 0; i < N; i++) {
            bool flag = true;
            while (me < star[i].b && flag) {
                flag = false;
                for (int j = N-1; j >= 0; j--) {
                    if (star[j].a > me) continue;
                    if (vis[ star[j].id ] < 1) {
                        me += 1;
                        vis[ star[j].id ] = 1;
                        ++ans;
                        flag = true;
                        break;
                        //cout << cs[j].id << " 1 " << me << endl;///
                        if (me >= star[i].b) {
                            break;
                        }
                    }
                }
            }
            if (me < star[i].b) {
                yes = false;
                break;
            }
            ++ans;
            me += 2-vis[ star[i].id ];
            vis[ star[i].id ] = 2;
            //cout << star[i].id << "  2 " << me << endl;///
        }
        if (!yes) {
            fprintf(fout, "Case #%d: Too Bad\n", ca);
        } else {
            fprintf(fout, "Case #%d: %d\n", ca, ans);
        }
    }
    
    fclose(fin);
    fclose(fout);
    return 0;
}

