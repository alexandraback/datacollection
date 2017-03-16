#include<iostream>
#include<stack>
#include<queue>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<string>
#include<cstring>
#include<map>
#include<numeric>
#include<sstream>
#include<cmath>
using namespace std;
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define pb push_back
#define f(i,x,y) for(int i = x; i<y; i++ )
#define FORV(it,A) for(vector<int>::iterator it = A.begin(); it!= A.end(); it++)
#define FORS(it,A) for(set<int>::iterator it = A.begin(); it!= A.end(); it++)
#define quad(x) (x) * (x)
#define mp make_pair
#define clr(x, y) memset(x, y, sizeof x)
#define fst first
#define snd second
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
#define inf 1000000

struct no{
    int x, y;
    int t;
    bool operator < (const no &e) const{
        if (x != e.x) return x < e.x;
        if (y != e.y) return y < e.y;
        return t < e.t;
    }
};

no make (int x, int y, int t){
    no e; e.x = x, e.y= y, e.t=t;
    return e;
}

map <no, no> pai;
pii des;
no ans;
void dfs (int x, int y, int t, no p){
    queue <no> Q;
    Q.push(make(x,y,t));
    pai[make(x,y,t)] = p;
    while (!Q.empty()){
        no e = Q.front(); Q.pop();
        x = e.x, y = e.y, t = e.t;
        //printf("(%d %d) %d\n", x, y, t);
        if (abs (x) >= 200 || abs(y) >= 200 || t > 500) continue;
        if (mp(x,y) == des){
            no e = make (x,y,t);
            ans = e;
            return;
        }
        no ee = make(x+t, y, t+1);
        if (pai.find(ee) == pai.end()){
            pai[ee] = e; Q.push(ee);
        }
        ee = make(x-t, y, t+1);
        if (pai.find(ee) == pai.end()){
            pai[ee] = e; Q.push(ee);
        }
        ee = make(x, y+t, t+1);
        if (pai.find(ee) == pai.end()){
            pai[ee] = e; Q.push(ee);
        }
        ee = make(x, y-t, t+1);
        if (pai.find(ee) == pai.end()){
            pai[ee] = e; Q.push(ee);
        }
    }
}


int main (){
    int t; cin >> t;
    f (tt, 1, t+1){
        int xx,yy;
        cin >> xx >> yy;
        pai.clear();
        des = mp (xx,yy);
        ans = make (-inf,-inf, -inf);
        dfs (0, 0, 1, ans);
        no x = ans;
        vector <char> ANS;
        while (x.x != -inf){
            no y = pai[x];
            if (y.x == -inf) break;
            if (x.x < y.x) ANS.pb('W');
            if (x.x > y.x) ANS.pb('E');
            if (x.y < y.y) ANS.pb('S');
            if (x.y > y.y) ANS.pb('N');
            x = y;
        }
        reverse (all(ANS));
        printf("Case #%d: ", tt);
        f (i, 0, ANS.size()) printf("%c", ANS[i]); printf("\n");
        int a = 0, b= 0;
        f (i, 0, ANS.size()){
            char c= ANS[i];
            int h = i+1;
            if (c == 'W') a -= (h);
            else if (c == 'E') a += (h);
            else if (c == 'N') b += (h);
            else b -= (h);
        }
        //printf("%d %d\n", a, b);

    }
    return 0;
}



