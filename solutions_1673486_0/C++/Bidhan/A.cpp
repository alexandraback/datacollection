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

#define mx 0
double p[100];
int a,b;
double kt,bs[100],ent=0;
void rec(int pos,vi &vul,double prob){
    //cout<<pos<<endl;
    if(pos==a){
        //kt
        if(!sz(vul)){
            kt+=(b-a+1)*prob;
        }
        else{
            kt+=(b-a+1+b+1)*prob;
        }

        //backspace
        //cout<<"vul "<<sz(vul)<<endl;
        for(int i=1; i<=a; i++){
            //cout<<"---------------------"<<i<<endl;
            int cnt=0;
            int tt=pos-i;
            rep(j,sz(vul)) cnt+=(tt>vul[j]);//, cout<<"--"<<vul[j]<<endl;
            //cout<<pos<<" "<<tt<<"--"<<cnt<<endl;
            int kk=0;
            if(cnt){
                bs[i]+=(b-tt+1+b+1+i)*prob;
                kk=(b-tt+1+b+1+i);
            }
            else{
                //cout<<prob<<" "<<(b-tt+1)<<endl;
                bs[i]+=(b-tt+1+i)*prob;
                kk=(b-tt+1+i);
            }
            //cout<<" cnt="<<cnt<<" vul="<<sz(vul)<<" "<<prob<<" tt="<<tt<<" kk="<<kk<<" "<<i<<"="<<bs[i]<<" ";
        }//cout<<endl;

        //enter
        if(a==b){
            if(sz(vul)) ent+=(b+1+1)*prob;
        }
        else{
            ent+=(b+1+1)*prob;
        }
        return ;
    }
    rec(pos+1,vul,prob*p[pos]);
    vul.pb(pos);
    rec(pos+1,vul,prob*(1.0-p[pos]));
    vul.pop_back();
}

int main(){
	read("ain.txt");
	rite("aout.txt");
    double cl = clock();
    cl = clock() - cl;
    int test,kas=0;//,a,b;

    cin>>test;
    while(test--){
        cin>>a>>b;
        rep(i,a) cin>>p[i];
        kt=0;
        mem(bs,0);
        ent=0;
        double ans=1e18;
        vi tt;
        rec(0,tt,1.0);
        ans=min(ans,kt);
        //cout<<kt<<"--"<<ent<<endl;
        for(int i=1; i<=a; i++) ans=min(ans,bs[i]);//, cout<<i<<"="<<bs[i]<<endl;
        ans=min(ans,ent);

        printf("Case #%d: %.6lf\n",++kas,ans+eps);
        /*if(a==1){
            for(int vul=0; vul<a; vul++){
            }
        }
        else if(a==2){
            rep(vul1,a){
                for(int vul2=vul1+1; vul2<a; vul2++){
                }
            }
        }
        else if(a==3){
            rep(vul1,a){
                for(int vul2=vul1+1; vul2<a; vul2++){
                    for(int vul3= vul2+1; vul3<a; vul3++){
                    }
                }
            }
        }*/
    }
    fprintf(stderr, "Total Execution Time = %lf seconds", cl / CLOCKS_PER_SEC);
    return 0;
}
