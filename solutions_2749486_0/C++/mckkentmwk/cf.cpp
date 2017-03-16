#include<bits/stdc++.h>
#define f(i,x,y) for (int i = int(x); i < int(y); i++)
#define fd(i,x,y) for(int i = int(x); i>= int(y); i--)
#define FOR(it,A) for(typeof A.begin() it = A.begin(); it!=A.end(); it++)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define vint vector<int>
#define ll long long
#define clr(A,x) memset(A, x, sizeof A)
#define pb push_back
#define pii pair<int,int>
#define fst first
#define snd second
#define ones(x) __builtin_popcount(x)
#define cua(x) (x)*(x)
#define oo 10000000
#define MAX 1000009
#define MOD 1000000007

using namespace std;

int X[] = {0,1,0,-1};
int Y[] = {1,0,-1,0};
string cord = "NESW";

int main(){
    freopen("in.c","r",stdin);
    freopen("out.c","w",stdout);
    int TC,a,b,NC=1;
    scanf("%d",&TC);
    while(TC--){
        scanf("%d%d",&a,&b);
        map<pii, string> m1;
        queue<pair<pii,int> > q;
        q.push(make_pair(pii(0,0),1));
        int temp = false;
        string ans;
        while(!q.empty()){
            pair<pii,int> u = q.front();q.pop();
            int x = u.fst.fst , y = u.fst.snd,cont = u.snd;
            if(x==a && y==b){
                ans = m1[pii(x,y)];
                break;
            }
            f(i,0,4){
                int xx = x+(X[i]*cont) , yy = y+(Y[i]*cont);
                if(!m1.count(pii(xx,yy)) ){
                    m1[pii(xx,yy)] = m1[pii(x,y)];
                    m1[pii(xx,yy)]+= cord[i];
                    q.push(make_pair(pii(xx,yy),cont+1));
                }
            }
        }

        cout<<"Case #"<<NC++<<": "<<ans<<endl;
    }

    return 0;
}

