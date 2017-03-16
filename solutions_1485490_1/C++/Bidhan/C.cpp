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
typedef pair<i64,i64> pii;
typedef vector<pii> vpii;

#define mx 110
#define linf (1LL<<60)
int n,m;
vpii box,toy;
/*pii state[mx][mx][mx][mx];//[2];

i64 call(int i,int j,int Pb,int Pt){
    if(i==n && j==m) return 0;
    if(i>n || j>m) return -linf;
    i64 ret=0;
    cout<<"Entered "<<i<<" "<<j<<" Pb="<<Pb<<" Pt="<<Pt<<endl;
    if(box[i].xx==toy[j].xx){
        i64 mini=min(box[i].yy,toy[j].yy);
        if(!Pb && !Pt){
            cout<<"Both 0!"<<endl;
            pii bb=box[i], tt=toy[j];
            state[i][j][0][0]=mp(box[i].yy,toy[j].yy);//[0]=box[i].yy;
            //state[i][j][0][0][1]=toy[j].yy;
            if(mini==bb.yy && mini==tt.yy) ret=max(ret,call(i+1,j+1,0,0)+mini);
            else if(mini==bb.yy) ret=max(ret,mini+call(i+1,j,1,0));
            else ret=max(ret,mini+call(i,j+1,0,1));
        }
        else if(Pb){
            cout<<"Pb boro"<<endl;
            //cout<<"Here"<<endl;
            pii bb=box[i], tt=toy[j];
            int temp=Pb,idx=i-1;
            while(temp--){
                while(box[idx].xx!=tt.xx) idx--;
                tt.yy-=state[idx][j][0][Pt-1].xx;//box[idx].yy;
                idx--;
            }
            mini=min(bb.yy,tt.yy);
            //for(int jj=i-1,cnt=0;cnt<Pb;jj--,cnt++){
             //   tt.yy-=box[jj].yy;
            //}
            cout<<endl<<"11 Now "<<bb.yy<<" "<<tt.yy<<endl;
            state[i][j][Pb][0]=mp(bb.yy,tt.yy);//[0]=bb.yy;
            //state[i][j][Pb][0][1]=tt.yy;
            if(mini==bb.yy && mini==tt.yy) ret=max(ret,call(i+1,j+1,0,0)+mini);
            else if(mini==bb.yy) ret=max(ret,mini+call(i+1,j,Pb+1,0));
            else ret=max(ret,mini+call(i,j+1,0,1));
        }
        else if(Pt){
            cout<<"Pt boro!"<<endl;
            pii bb=box[i], tt=toy[j];
            //for(int jj=i-1,cnt=0;cnt<Pt;jj--,cnt++){
            //    bb.yy-=toy[jj].yy;
            //}
            int temp=Pt, idx=j-1;;
            int cnt=0;
            while(temp--){
                while(toy[idx].xx!=bb.xx) idx--;
                cnt++;
                bb.yy-=state[i][idx][0][Pt-1].yy;//toy[idx].yy;
                idx--;
            }
            mini=min(bb.yy,tt.yy);
            cout<<"22 Now "<<bb.yy<<" "<<tt.yy<<endl;
            state[i][j][Pb][0]=mp(bb.yy,tt.yy);
            //state[i][j][0][Pt][0]=bb.yy;
            //state[i][j][0][Pt][1]=tt.yy;
            if(mini==bb.yy && mini==tt.yy) ret=max(ret,call(i+1,j+1,0,0)+mini);
            else if(mini==bb.yy) ret=max(ret,mini+call(i+1,j,1,0));
            else ret=max(ret,mini+call(i,j+1,0,Pt+1));
        }
    }
    else ret=max(ret,max(call(i+1,j,Pb,0),call(i,j+1,0,Pt)));
    cout<<i<<"--"<<j<<" "<<Pb<<" "<<Pt<<" ="<<ret<<endl;
    return ret;
}*/

i64 dp[mx][mx];
i64 call(int i,int j){
    if(i==n && j==m) return 0;
    if(i>n || j>m) return -linf;
    if(dp[i][j]!=-1) return dp[i][j];
    i64 ret=0;
    pii bb=box[i], tt=toy[j];
    if(bb.xx!=tt.xx) ret=max(ret, max(call(i+1,j),call(i,j+1)) );
    else{
        i64 tot=0;
        int i1=i, i2=j;
        bb=box[i1], tt=toy[i2];
        while(true){
            if(bb.yy==tt.yy) {  tot+=bb.yy; ret=max(ret,call(i1+1,i2+1)+tot); break; }
            else if(bb.yy<tt.yy) {
                tot+=bb.yy;
                tt.yy-=bb.yy;
                ret=max(ret,call(i1+1,i2+1)+tot);
                i1++;
                while(i1<n && box[i1].xx!=tt.xx) i1++;
                if(i1<n) bb=box[i1];
            }
            else{
                tot+=tt.yy;
                bb.yy-=tt.yy;
                ret=max(ret,call(i1+1,i2+1)+tot);
                i2++;
                while(i2<m && toy[i2].xx!=bb.xx) i2++;
                if(i2<m) tt=toy[i2];
            }
            if(i1>=n || i2>=m)  break;
        }
    }
    return dp[i][j]=ret;
}
int main(){
	double cl = clock();
    cl = clock() - cl;
    read("cin.txt");
    rite("cout.txt");
    int test,kas=0;
    cin>>test;
    while(test--){
        printf("Case #%d: ",++kas);
        cin>>n>>m;
        box.clr; toy.clr;
        rep(i,n){
            i64 a,b;
            cin>>a>>b;
            box.pb(mp(b,a));
        }
        rep(i,m){
            i64 a,b;
            cin>>a>>b;
            toy.pb(mp(b,a));
        }
        mem(dp,-1);
        cout<<call(0,0)<<endl;
    }
    fprintf(stderr, "Total Execution Time = %lf seconds", cl / CLOCKS_PER_SEC);
    return 0;
}
