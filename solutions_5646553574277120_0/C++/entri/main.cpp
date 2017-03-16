#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;
#define     FOR(i,s,e)      for(int (i) = (s); (i) <  (e); ++(i))
#define     FORE(i,s,e)     for(int (i) = (s); (i) <= (e); ++(i))
#define     FORD(i,e,s)     for(int (i) = (e); (i) >= (s); --(i))
#define     REP(i,n)        FOR(i,0,n)
#define     REPE(i,n)       FORE(i,1,n)
#define     REPD(i,n)       FORD(i,n,1)


int T, t;
int C,D,V;
const int NMax = 33;
int Deno[NMax];
bool Val[NMax];
int Prev[NMax];

void init(){
    REP(i, NMax) Val[i] = false;
    REP(i, NMax) Prev[i] = -1;
};

void ReCount(){
    init();
    Val[0] = true;

    REP(i, D)
    FORE(v, 0, V)
        if(Val[v])
        if(Prev[v] != i){
            //cout <<v<<" "<<i<<endl;
            Val [v + Deno[i]] = true;
            Prev[v + Deno[i]] = i;
        };
};

int check(){
    int ans = 0;
    REP(i,D){
        if (Deno[i] == pow(2, ceil(log2(Deno[i])))) ans++;
    };
    return ans;
};

int solve(){
    int mmax = ceil(log2(V)) - check();

    int ans = 0;
    ReCount();
    //REP(i,V) if (Val[i] == false) cout <<i<<"w"<<endl;

    FORE(v, 1, V){
        bool newVal = false;
        if (Val[v] == false){
            ans++;
            //cout <<v<<" hehe "<<endl;
            Deno[D++] = v;
            Val[v] = true;
            newVal = true;
        };
        if (newVal){
            sort(Deno, Deno+D);
            ReCount();
        };
    };




    if (ans > mmax) ans  = mmax;

    return ans;
};

int main()
{
    cin >>T;
    t = 0;
    while(t<T){
        t++;
        init();
        cin >>C>>D>>V;
        for(int i=0; i<D; i++) cin >>Deno[i];
        int ans = solve();
        cout <<"Case #"<<t<<": "<<ans<<endl;
    }
    return 0;
}
