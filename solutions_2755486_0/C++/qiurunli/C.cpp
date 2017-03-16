#include <stdio.h>
#include <string>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

const int MAXN = 100000;

int n;

struct Node{
    int s, t, d, day;
    bool operator < (const Node &b) const{
        if(day != b.day)  return day < b.day;
        return d < b.d;
    }
}att[MAXN];

void readin(){
    scanf("%d", &n);
    int m(0);
    for(int i = 0; i < n; ++i){
        int di, ni, wi, ei, si, ddi, dpi, dsi;
        scanf("%d%d%d%d%d%d%d%d", &di, &ni, &wi, &ei, &si, &ddi, &dpi, &dsi);
        wi += 200;
        ei += 200;
        wi *= 2;
        ei = ei * 2 - 1;
        dpi *= 2;

        for(int j = 0; j < ni; ++j){
            att[m].d = si;
            att[m].day = di;
            att[m].s = wi;
            att[m].t = ei;

            wi += dpi;
            ei += dpi;
            si += dsi;
            di += ddi;
            ++m;
        }
    }
    sort(att, att + m);
    n = m;
}

int hig[2][100000];
int inq[100000];
queue<int> q;

int main(){

    freopen("C-small-attempt1.in", "r", stdin);
    freopen("small.out", "w", stdout);

    int test, cas(1);
    scanf("%d", &test);
    while(test--){
        readin();
        memset(hig, 0, sizeof(hig));
        memset(inq, 0, sizeof(inq));
        while(!q.empty())  q.pop();

        int last(-1), now(0), res(0);
        for(int i = 0; i < n; ++i){

//            if(att[i].s < 0) ("%d  %d  %d  %d\n", att[i].day, att[i].s, att[i].t, att[i].d);

            if(att[i].day != last){
                last = att[i].day;
                while(!q.empty()){
                    int u = q.front();  q.pop();  inq[u] = 0;
                    hig[now][u] = max(hig[now][u], hig[!now][u]);
                }
                //now = !now;
            }

            int fg(0);
            for(int j = att[i].s; j <= att[i].t; ++j){
                if(hig[now][j] < att[i].d){
//                    printf("%d  %d\n", att[i].d, hig[now][j]);
                    hig[!now][j] = max(hig[!now][j], att[i].d);
                    fg = 1;
                    if(!inq[j]) {
                        q.push(j);
                        inq[j] = 1;
                    }
                }
            }
            if(fg)   ++res;
        }
        printf("Case #%d: %d\n", cas++, res);
    }


    return 0;
}
