//==================================================================//
// Name        : flash7even                                         //
// Author      : Tarango Khan                                       //
// Codeforces  : flash_7                                            //
// Topcoder    : flash_7                                            //
// Hackerrank  : flash_7                                            //
// Email       : tarangokhan77@gmail.com                            //
// Facebook    : tarango.khan                                       //
//==================================================================//

//==================================================================//
#include <bits/stdc++.h>                                            //
using namespace std;                                                //
#define read(nm)        freopen(nm, "r", stdin)                     //
#define write(nm)       freopen(nm, "w", stdout)                    //
#define pb              push_back                                   //
#define mp              make_pair                                   //
#define F               first                                       //
#define S               second                                      //
#define eps             1e-9                                        //
#define FABS(x)         ((x)+eps<0?-(x):(x))                        //
#define pf              printf                                      //
#define sf              scanf                                       //
#define pi              acos(-1.0)                                  //
#define SZ(x)           ((int)(x).size())                           //
#define mems(x,v)       memset(x,v,sizeof(x))                       //
#define fills(v,n)      fill(v.begin(), v.end(), n)                 //
#define vsort(v)        sort(v.begin(),v.end())                     //
#define asort(v,n)  	sort(a,a+n)                                 //
#define LL              long long                                   //
#define LLU             long long unsigned int                      //
#define debug1(v1)      cout<<"1@ Debug Val 1 = "<<v1<<endl;        //
#define debug2(v2)      cout<<"   2@ Debug Num 2 = "<<v2<<endl;     //
#define debug3(v3)      cout<<"      3@ Debug Res 3 = "<<v3<<endl;  //
#define UB(v,a)   upper_bound(v.begin(),v.end(),a)-v.begin()        //
#define LB(v,a)   lower_bound(v.begin(),v.end(),a)-v.begin()        //
#define fast_cin ios_base::sync_with_stdio(false);cin.tie(NULL)     //
//==================================================================//

//==================================================================//
void make_unique(vector<int> &a){ sort(a.begin(), a.end());         //
     a.erase(unique(a.begin(), a.end()), a.end()); }                //
void printDouble(double f,int p){ cout << fixed;                    //
     cout << setprecision(p) << f <<endl; }                         //
int  Set(int N,int cur){ return N = N | (1<<cur); }                 //
int  Reset(int N,int cur){ return N = N & ~(1<<cur); }              //
bool Check(int N,int cur){ return (bool)(N & (1<<cur)); }           //
LL   GCD(LL a,LL b){ if(b == 0) return a; return GCD(b,a%b);}       //
LL   LCM(LL a,LL b){ return a*b/GCD(a,b);}                          //
LL   POW(LL a,LL p){ LL res = 1,x = a;while(p){if(p&1)              //
     res = (res*x); x = (x*x);p >>= 1;} return res;}                //
//==================================================================//

//==================================================================//
//int knightDir[8][2] = {{-2,1},{-1,2},{1,2},{2,1},                 //
//                      {2,-1},{-1,-2},{1,-2},{-2,-1}};             //
//int dir8[4][2]      = {{-1,0},{0,1},{1,0},{0,-1},                 //
//                      {-1,-1},{1,1},{1,-1},{-1,1}};               //
//int dir4[4][2]      = {{-1,0},{0,1},{1,0},{0,-1}};                //
//==================================================================//
//=======// Done With The Shortcut Stuffs! Now Let's Code! //=======//

struct PR{
    int j,p,s;
    PR(){
    }
    PR(int a,int b,int c){
        j = a;
        p = b;
        s = c;
    }
};

int J,P,S,K;

int JP[15][15];
int JS[15][15];
int SP[15][15];
int JPS[15][15][15];

vector<PR> res;
PR taken[100005];

int cnt = 0;
int pp = 0;

void call(int cur){
    //Mx = max(Mx,cur);
    if(pp>10000000) return;
    pp++;
    if(cur>cnt){
        res.clear();
        for(int i = 0;i<cur;i++){
            res.pb(taken[i]);
        }
        cnt = cur;
    }
    for(int j = 1;j<=J;j++){
        for(int p = 1;p<=P;p++){
            for(int s = 1;s<=S;s++){
                if(JPS[j][p][s] == 1) continue;
                if(JP[j][p] >= K) continue;
                if(JS[j][s] >= K) continue;
                if(SP[s][p] >= K) continue;

                taken[cur] = PR(j,p,s);

                JP[j][p]++;
                JS[j][s]++;
                SP[s][p]++;
                JPS[j][p][s] = 1;
                call(cur+1);
                JP[j][p]--;
                JS[j][s]--;
                SP[s][p]--;
                JPS[j][p][s] = 0;
            }
        }
    }
}

int main(){
    read("input.txt");
    write("output_5.txt");
    fast_cin;
    int nCase;
    cin >> nCase;
    for(int cs = 1;cs<=nCase;cs++){
        cin >>J>>P>>S>>K;
        res.clear();
        mems(JP,0);
        mems(JS,0);
        mems(SP,0);
        mems(JPS,0);
        cnt = 0;
        pp = 0;
        call(0);
        cout << "Case #" << cs << ": " << cnt << endl;
        for(int i = 0;i<cnt;i++){
            cout << res[i].j << " " << res[i].p << " " << res[i].s << endl;
        }
    }
}
