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
#define oo 1000000
#define MAX 1000009
#define N 1010
using namespace std;


int main(){
    freopen("in.c","r",stdin);
    freopen("out.c","w",stdout);
    int TC,r,t,NC=1;
    scanf("%d",&TC);
    while(TC--){
        scanf("%d%d",&r,&t);
        int cont = 0;
        ll blanco ,negro;
        ll ans = 0;
        while(t>0){
            blanco = floor(pow(r+cont,2)+0.5);
            negro = floor(pow(r+cont+1,2) + 0.5);
            cont+=2;
            if((negro-blanco)<=t){
                ans++;
                t -= (negro-blanco);
            }else{
                break;
            }
        }
        printf("Case #%d: %lld\n",NC++,ans);
        //cout<<ans<<endl;
    }


    return 0;
}
