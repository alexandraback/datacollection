#include <iostream>
#include <sstream>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
struct Date {
    int d;
    int s;
    int w;
    int e;
};
bool cmp(const Date& t1, const Date& t2)
{
    return t1.d < t2.d;
}
int pos[1000], comb[1000];
bool succ(int w, int e, int s)
{
    for (int i=w; i<=e; i++) {
        if (pos[i] < s) return true;
        if (i != e) {
            if (comb[i] < s) return true;
        }
    }
    return false;
}
void build(int w, int e, int s)
{
    for (int i=w; i<=e; i++) {
        pos[i] = max(pos[i], s);
        if (i != e) comb[i] = max(comb[i], s);
    }
}
void display()
{
    int Case;
    scanf("%d", &Case);
    for (int ca=1;ca<=Case;ca++) {
        printf("Case #%d: ", ca);
        memset(pos, 0, sizeof(pos));
        memset(comb, 0, sizeof(comb));
        int N;
        scanf("%d", &N);
        vector<Date> a;
        for (int i = 0; i < N; i++) {
            int di, ni, wi, ei, si, delta_di, delta_pi, delta_si;
            scanf("%d%d%d%d%d%d%d%d", &di, &ni, &wi, &ei, &si, &delta_di, &delta_pi, &delta_si);
            for (int j = 0; j < ni; j++) {
                Date p;
                p.d = di;
                p.s = si;
                p.w = wi;
                p.e = ei;
                di += delta_di;
                si += delta_si;
                wi += delta_pi;
                ei += delta_pi;
                a.push_back(p);
            }
        }
        sort(a.begin(), a.end(), cmp);
        int day = -1, ans = 0;
        vector<Date> oneday;
        for (size_t i = 0; i < a.size(); i++) {
            if (a[i].d != day) {
                if (day != -1) {
                    for (size_t j = 0; j < oneday.size(); j++) {
                        ans+=succ(oneday[j].w+500, oneday[j].e+500, oneday[j].s);
                    }
                    for (size_t j = 0; j < oneday.size(); j++)
                        build(oneday[j].w+500, oneday[j].e+500, oneday[j].s);
                }
                day = a[i].d;
                oneday.clear();
                oneday.push_back(a[i]);
            }
            else {
                oneday.push_back(a[i]);
            }
        }
        for (size_t j = 0; j < oneday.size(); j++) {
            ans+=succ(oneday[j].w+500, oneday[j].e+500, oneday[j].s);
        }
        printf("%d\n", ans);
    }
}
int main()
{
    freopen("C-small-attempt2.in", "r", stdin);
    //freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
    display();
    return 0;
}
