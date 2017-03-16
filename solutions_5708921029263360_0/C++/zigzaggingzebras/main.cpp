#include<stdio.h>
#include<vector>

int SP[11][11], PJ[11][11], SJ[11][11];
int s,p,j;

struct STATE
{
    int s;
    int p;
    int j;
    STATE(int _s = 1, int _p = 1, int _j = 1)
    {
        s = _s; p = _p; j = _j;
    }
};

bool operator++ (STATE &a)
{
    a.j++;
    if(a.j > j) {a.j = 1; a.p++;}
    if(a.p > p) {a.p = 1; a.s++;}
    if(a.s > s) return false;
    else return true;
}

int main()
{
    freopen("C-small-attempt0.in", "r", stdin);
    freopen("c_small_0.txt", "w", stdout);

    int t;
    scanf("%d", &t);
    for(int _t = 1; _t <= t; _t++)
    {
        //init
        int lim;
        scanf("%d %d %d %d", &j, &p, &s, &lim);
        std::vector<STATE> vS;
        for(int i = 0; i <= 10; i++) for(int j = 0; j <= 10; j++) {SP[i][j] = 0; PJ[i][j] = 0; SJ[i][j] = 0;}

        //calculate
        STATE s = STATE();
        do{
            if(SP[s.s][s.p] >= lim || PJ[s.p][s.j] >= lim || SJ[s.s][s.j] >= lim) continue;

            SP[s.s][s.p]++;
            PJ[s.p][s.j]++;
            SJ[s.s][s.j]++;
            vS.push_back(s);
        }while(++s);

        //print
        printf("Case #%d: %d\n", _t, vS.size());
        for(int i = 0; i < vS.size(); i++)
            printf("%d %d %d\n", vS[i].j, vS[i].p, vS[i].s);
    }

}
