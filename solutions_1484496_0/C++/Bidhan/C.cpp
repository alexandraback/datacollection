/*
 * Bidhan Roy
 * University of Dhaka
 */

using namespace std;

#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <list>
#include <ctime>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

#define rep(i,n) for(__typeof(n) i=0; i<(n); i++)
#define foreach(i,n) for(__typeof((n).begin())i =(n).begin();i!=(n).end();i++)
#define inf (1<<30)
#define eps 1e-9
#define pb push_back
#define ins insert
#define mp make_pair
#define sz(x) ((int)x.size())
#define clr clear()
#define all(x) x.begin(),x.end()
#define xx first
#define yy second
#define sqr(x) ((x)*(x))
#define mem(x,val) memset((x),(val),sizeof(x));
#define read(x) freopen(x,"r",stdin);
#define rite(x) freopen(x,"w",stdout);
#define chk(a,k) ((bool)(a&(1<<(k))))
#define off(a,k) (a&(~(1<<(k))))
#define on(a,k) (a|(1<<(k)))

typedef long long i64;
typedef unsigned long long ui64;
typedef string st;
typedef vector<int> vi;
typedef vector<st> vs;
typedef map<int,int> mii;
typedef map<st,int> msi;
typedef map<int,st> mis;
typedef set<int> si;
typedef set<st> ss;
typedef pair<int,int> pii;
typedef vector<pii> vpii;

#define mx 100000*20+2
int sum,n,temp,ans;
int f=0;
vi vec;
void call(int pos,int ttt,int tm){
    //if(ttt==1) cout<<"____++ "<<pos<<endl;
    if(f) return ;
    //cout<<pos<<" "<<f<<" "<<tm<<endl;
    if(pos==n){
        if(ttt==sum) {
            //cout<<ttt<<" ?? "<<sum<<endl;
            f=1;
        }
        if(f) ans=tm;//, cout<<"----"<<pos<<" "<<ttt<<endl;
        return ;
    }
    //if(pos==0) cout<<chk(temp,pos)<<endl;
    if(chk(temp,pos)) {  call(pos+1,ttt,tm); return ;}
    call(pos+1,ttt+vec[pos],on(tm,pos));
    call(pos+1,ttt,tm);
}
int main(){
    read("cin.txt");
    rite("cout.txt");
	double cl = clock();
    cl = clock() - cl;
    int test,kas=0;
    cin>>test;
    while(test--){
        cin>>n;
        vec.clr;
        rep(i,n){
            int tt;
            cin>>tt;
            vec.pb(tt);
        }
        f=0;
        printf("Case #%d:\n",++kas);
        rep(i,1<<n)if(i){
            sum=0;
            temp=i;
            rep(j,20) if(chk(i,j)) sum+=vec[j];
            //cout<<i<<"="<<sum<<endl;
            call(0,0,0);
            if(f){
                int tttt=0;
                //cout<<i<<" ---- "<<ans<<endl;
                rep(j,20)if(chk(i,j)){
                    if(tttt) printf(" ");
                    tttt=1;
                    printf("%d",vec[j]);
                }
                //cout<<i<<" --"<<ans<<" here"<<endl;
                cout<<endl;
                tttt=0;
                rep(j,20) if(chk(ans,j)){
                    if(tttt) printf(" ");
                    tttt=1;
                    printf("%d",vec[j]);
                }
                cout<<endl;
                break;
            }
        }
        if(!f) cout<<"Impossible"<<endl;
    }
    fprintf(stderr, "Total Execution Time = %lf seconds", cl / CLOCKS_PER_SEC);
    return 0;
}

