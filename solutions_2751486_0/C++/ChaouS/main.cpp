
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
#define MAXN 1000005

using namespace std;
int toi(string a){	int ans;  sscanf(a.c_str(),"%d",&ans);  return ans;  }
string tos(int a){	ostringstream st; st<<a; string ans = st.str(); return ans;   }

int dp[MAXN];

bool isvocal(char a)
{   if(a=='a' || a=='e' || a=='i' || a=='o' || a=='u')
    return true;
return false;
}
int n;

ll binary_search(int num,vector<ll> a)
{   int L = -1 , R = a.size();
    while(L + 1 < R)
    {   int mid = (L+R)/2;
        if(a[mid]>=num) R = mid;
        else L = mid;
    }
    if(R==(int)a.size()) return n;
return a[R];
}

int main(){
    freopen("in.c","r",stdin);
    freopen("on.c","w",stdout);
    string a;  int tc , k , nc = 1;
    cin>>tc;

    while(tc--)
    {   cin>>a; cin>>k; // al menos k
        n = a.size();
        f(i,0,n) dp[i] = 0;

        vector<ll> buscar;
        vector<pii> mm;
        int cont = 0 , L;
        bool est = false;
        f(i,0,n){
                if(isvocal(a[i])) {
                    if(est) mm.pb(make_pair(L,i-1));
                    cont = 0;
                est = false;
                }
                else cont++;
        dp[i] = cont;
        if(cont==1) L = i , est = true;
        if(cont == k)
        buscar.pb(i);
        }

        if(est) mm.pb(make_pair(L,n-1));
        ll ans = 0;

            if(mm.size() > 0)
            f(j,0,mm[0].fst)
            {    ll aux = binary_search(j,buscar);
            ans+=n-aux;
            }

        f(i,0,mm.size())
        {   int x = mm[i].fst , y = mm[i].snd;
            //inicio y final
            int tam = y - x + 1;
            //los primeros tam - k + 1
            f(j,x,min(x + tam - k + 1,y + 1) )
             {   ans+=(n-j-k+1);
             }

            fd(j,y,max(x,y-k+2))
            { // busqueda binaria
                ll aux = binary_search(y+1,buscar);
            ans+=n-aux;
            }

          if(i + 1 < (int)mm.size())
            f(j,y + 1,mm[i + 1].fst)
            { // busqueda binaria
                 ll aux = binary_search(j,buscar);
            ans+=n-aux;
            }
        }

        printf("Case #%d: %lld\n",nc++,ans);
    }





    return 0;
}
