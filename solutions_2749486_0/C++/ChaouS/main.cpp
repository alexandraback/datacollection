
/************** Elvis Rusnel Capia Quispe ***************/
#include <bits/stdc++.h>
#define f(i,x,y) for (int i = (x); i < (y); i++)
#define fd(i,x,y) for(int i = x; i>= y; i--)
#define FOR(it,A) for(typeof A.begin() it = A.begin(); it!=A.end(); it++)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define vint vector<int>
#define pii pair<int,int>
#define vpii vector<pii>
#define ll long long
#define clr(A,x) memset(A, x, sizeof A)
#define pb push_back
#define fst first
#define snd second
#define ones(x) __builtin_popcount(x)
#define cua(x) (x)*(x)
#define MOD 1000000007
#define INF 1000000000
#define HASH unsigned long long
#define bug1(x) cout<<#x<<" = "<<x<<endl
#define bug2(x,y) cout<<#x<<" = "<<x<<" "<<#y<<" = "<<y<<endl
#define bug3(x,y,z) cout<<#x<<" = "<<x<<" "<<#y<<" = "<<y<<" "<<#z<<" = "<<z<<endl
#define bug4(x,y,z,m) cout<<#x<<" = "<<x<<" "<<#y<<" = "<<y<<" "<<#z<<" = "<<z<<" "<<#m<<" = "<<m<<endl
#define sc(x) scanf("%d",&x)
#define ana(x) cout<<"NO JUST FOR ME"<<endl
#define MAXN 100005

using namespace std;
int toi(string a){	int ans;  sscanf(a.c_str(),"%d",&ans);  return ans;  }
string tos(int a){	ostringstream st; st<<a; string ans = st.str(); return ans;   }//char ans[20]; sprintf(ans,"%d",a);      return ans; }

string ans;
int x,y;
bool ok ;

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
string dir = "NSEW";
bool visited[505][505][30];

void rec(int posx,int posy,string a,int mov)
{   if(ok || mov > 20) return;
    if(posx + 200 >=500 || posy + 200>=500) return;
    if( posx == x && posy == y){
    ans = a;
    ok = true;
    return;
    }
    if(visited[posx + 200][posy + 200][mov]) return;

    visited[posx + 200][posy + 200][mov] = true;

    f(i,0,4)
    {   int xnew = posx + dx[i]*mov;
        int ynew = posy + dy[i]*mov;
    rec(xnew,ynew,a+dir[i],mov+1);
    }
}


int main(){
    freopen("in.c","r",stdin);
    freopen("on.c","w",stdout);
    int tc , nc = 1;
    cin>>tc;

    while(tc--)
    {   cin>>x>>y;
        clr(visited,false);
        ok = false;
        rec(0,0,"",1);
    cout<<"Case #"<<nc++<<": "<<ans<<endl;
    }

    return 0;
}

