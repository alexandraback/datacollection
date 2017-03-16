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

#define INF (1<<30)
#define MOD 1000000007

#define Size 1000005

string s;
int N;

int cnt[27];
int sol[11];

void printAll(){
    for(int i = 0;i<26;i++){
        cout<<i<<": "<<(char)(i+'A')<<" = "<<cnt[i]<<endl;
    }
}

void call(){
    //printAll();
    int z = (int)('Z'-'A'); // 0
    if(cnt[z]>0){
        //cout << "ENTER "<< cnt[(int)('E'-'A')] << endl;
        sol[0] = cnt[z];
        cnt[(int)('E'-'A')] -= cnt[z];
        cnt[(int)('R'-'A')] -= cnt[z];
        cnt[(int)('O'-'A')] -= cnt[z];
        cnt[(int)('Z'-'A')] -= cnt[z];
        //cout << "ENTER "<< cnt[z] << endl;
    }
    //printAll();
    z = (int)('W'-'A'); // 2
    if(cnt[z]>0){
        sol[2] = cnt[z];
        cnt[(int)('T'-'A')] -= cnt[z];
        cnt[(int)('O'-'A')] -= cnt[z];
        cnt[(int)('W'-'A')] -= cnt[z];
    }
    z = (int)('U'-'A'); // 4
    if(cnt[z]>0){
        sol[4] = cnt[z];
        cnt[(int)('F'-'A')] -= cnt[z];
        cnt[(int)('O'-'A')] -= cnt[z];
        cnt[(int)('R'-'A')] -= cnt[z];
        cnt[(int)('U'-'A')] -= cnt[z];
    }
    z = (int)('X'-'A'); // 6
    if(cnt[z]>0){
        sol[6] = cnt[z];
        cnt[(int)('S'-'A')] -= cnt[z];
        cnt[(int)('I'-'A')] -= cnt[z];
        cnt[(int)('X'-'A')] -= cnt[z];
    }
    z = (int)('G'-'A'); // 8
    if(cnt[z]>0){
        sol[8] = cnt[z];
        cnt[(int)('E'-'A')] -= cnt[z];
        cnt[(int)('I'-'A')] -= cnt[z];
        cnt[(int)('H'-'A')] -= cnt[z];
        cnt[(int)('T'-'A')] -= cnt[z];
        cnt[(int)('G'-'A')] -= cnt[z];
    }

    z = (int)('O'-'A'); // 1
    if(cnt[z]>0){
        sol[1] = cnt[z];
        cnt[(int)('N'-'A')] -= cnt[z];
        cnt[(int)('E'-'A')] -= cnt[z];
        cnt[(int)('O'-'A')] -= cnt[z];
    }
    z = (int)('R'-'A'); // 3
    if(cnt[z]>0){
        sol[3] = cnt[z];
        cnt[(int)('T'-'A')] -= cnt[z];
        cnt[(int)('H'-'A')] -= cnt[z];
        cnt[(int)('E'-'A')] -= cnt[z];
        cnt[(int)('E'-'A')] -= cnt[z];
        cnt[(int)('R'-'A')] -= cnt[z];
    }
    z = (int)('F'-'A'); // 5
    if(cnt[z]>0){
        sol[5] = cnt[z];
        cnt[(int)('I'-'A')] -= cnt[z];
        cnt[(int)('V'-'A')] -= cnt[z];
        cnt[(int)('E'-'A')] -= cnt[z];
        cnt[(int)('F'-'A')] -= cnt[z];
    }
    z = (int)('S'-'A'); // 7
    if(cnt[z]>0){
        sol[7] = cnt[z];
        cnt[(int)('E'-'A')] -= cnt[z];
        cnt[(int)('V'-'A')] -= cnt[z];
        cnt[(int)('E'-'A')] -= cnt[z];
        cnt[(int)('N'-'A')] -= cnt[z];
        cnt[(int)('S'-'A')] -= cnt[z];
    }
    z = (int)('I'-'A'); // 9
    if(cnt[z]>0){
        sol[9] = cnt[z];
        cnt[(int)('N'-'A')] -= cnt[z];
        cnt[(int)('N'-'A')] -= cnt[z];
        cnt[(int)('E'-'A')] -= cnt[z];
        cnt[(int)('I'-'A')] -= cnt[z];
    }
}

void solve(){
    call();
    for(int d = 0;d<10;d++){
        for(int c = 0;c<sol[d];c++){
            cout << d;
        }
    }
    cout << endl;
}

int main(){
    read("input.txt");
    write("output_1.txt");
    fast_cin;
    int nCase;
    cin >> nCase;
    for(int cs = 1;cs<=nCase;cs++){
        cin >> s;
        N = s.length();
        mems(cnt,0);
        mems(sol,0);
        for(int i = 0;i<N;i++){
            int p = (int)(s[i] - 'A');
            cnt[p]++;
        }
        cout << "Case #" << cs << ": ";
        solve();
    }
}
