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
    ll TC,r,t,NC=1;
    scanf("%lld",&TC);
    while(TC--){
        scanf("%lld%lld",&r,&t);
        ll cont = 0;
        ll blanco ,negro;
        ll ans = 0;
        //primer circunferencia de cuanto de tamaño es
        //blanco = floor(pow(r+cont,2)+0.5);
        //negro = floor(pow(r+cont+1,2) + 0.5);
        //
        //ll par2 = 3 , impar3 = 5;
        //
        ll temp,act;
        if(((r+1)%2)==0){//cuando es par
            temp = (r+1 - 2) / 2;
            //negro = 3+(4*temp);
            if(temp ==0){
                act = 0;
            }else   act = 3*(temp) + 4*((temp-1)*(temp)/2);
            ll L = temp+1, R = 1000000000, mid;
            while(R-L>1){
                mid = (R+L)/2;
                ll todo = (3*(mid)) + 4*((mid-1)*mid/2);
               // cout<<todo-act<<endl;
                if((todo-act)<=t)  L = mid;
                else    R = mid;
            }
            ll todo = (3*(R)) + 4*((R-1)*R/2);
            //cout<<R<<"--"<<L<<endl;
            if((todo-act)<=t){
                //cout<<"entra"<<endl;
                ans = R - temp;
            }else {
                ans = L - temp;
            }


        }else{
            temp = (r+1 - 3) /2;
            //negro = 5 + (4*temp);
            act = 5*(temp) + 4*((temp-1)*(temp)/2);
            ll L = temp+1, R = 1000000000, mid;
            while(R-L>1){
                mid = (R+L)/2;
                ll todo = (5*(mid)) + 4*((mid-1)*mid/2);
                //cout<<todo-act<<endl;
                if((todo-act)<=t)  L = mid;
                else    R = mid;
            }
            ll todo = (5*(R)) + 4*((R-1)*R/2);
            if((todo-act)<=t){
                //cout<<"entra"<<endl;
                ans = R - temp;
            }else {
                ans = L - temp;
            }

        }
        //ya tengo el anillo negro
        printf("Case #%lld: %lld\n",NC++,ans);
        //printf("Case #%lld: %lld\n",NC++,ans);
        //cout<<ans<<endl;
    }


    return 0;
}
