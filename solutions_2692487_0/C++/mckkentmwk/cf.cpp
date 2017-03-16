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
#define oo 100000000000000
#define MAX 1000009
#define MOD 1000000007

using namespace std;

int main(){
    freopen("in.c","r",stdin);
    freopen("out.c","w",stdout);
    ll a;
    int n,x,TC,NC=1;
    scanf("%d",&TC);
    while(TC--){
        scanf("%lld%d",&a,&n);
        vint save;
        f(i,0,n){
            scanf("%d",&x);
            save.pb(x);
        }
        if(a==1){
            printf("Case #%d: %d\n",NC++,n);
            continue;
        }
        sort(all(save));
        //comienzo a comer
        int cont = 0;
        vector<ll> ans;
        f(i,0,n){
            //cout<<"save[i]->"<<save[i]<<endl;
            if(a>save[i]){//puedo comer
                a+=save[i];
            }else{
                //cout<<"entra"<<endl;
                //cuando aumento y puedo comer
                int cont_t = 0;
                ans.pb(cont + (n-i));
                //cout<<cont + (n-i)<<endl;
                while(a<=save[i]){
                    a+=(a-1);
                    cont++;
                }
                a+=save[i];
                //cout<<"a-->"<<a<<endl;
                //cout<<"-->"<<cont<<endl;
            }
            //cout<<a<<endl;
            //y cuando aumento y no puedo comer... lo que hago es eliminar
        }
        ans.pb(cont);
        //cout<<ans.size()<<endl;
        ll sol = (ll) 1000000000000;
        f(i,0,ans.size()){
            //cout<<"-->"<<ans[i]<<endl;
            sol = min(sol,ans[i]);
        }
        printf("Case #%d: %lld\n",NC++,sol);
    }

    return 0;
}
