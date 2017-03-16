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

LL B,M;
int Mat[22][22];

void solve(){
    mems(Mat,0);
    LL sum = 0;
    int vert = B-1;
    for(LL P = -1;P<B;P++){
        if(sum == M) break;
        if(vert == 0) break;
        Mat[0][vert] = 1;
        if(vert == B-1){
            sum++;
            vert--;
            continue;
        }
        if(sum + POW(2,P) > M){
            int rem = M - sum;
            for(int i = 0;i<30;i++){
                if(Check(rem,i) == true){
                    Mat[vert][B-i-2] = 1;
                    sum += POW(2,i);
                }
            }
        }else{
            sum += POW(2,P);
            for(int v2 = vert+1;v2<B;v2++){
                Mat[vert][v2] = 1;
            }
        }
        vert--;
    }
    if(sum < M){
        cout << "IMPOSSIBLE" << endl;
        return;
    }
    cout << "POSSIBLE" << endl;

    for(int i = 0;i<B;i++){
        for(int j = 0;j<B;j++){
            if(i == j) Mat[i][j] = 0;
            cout << Mat[i][j];
        }
        cout << endl;
    }
}

int main(){
    read("input.txt");
    write("output_2.txt");
    fast_cin;
    int nCase;
    cin >> nCase;
    for(int cs = 1;cs<=nCase;cs++){
        cin >> B >> M;
        cout << "Case #" << cs << ": ";
        if(B == 2 && M>1){
            cout << "IMPOSSIBLE" << endl;
            continue;
        }
        if(B == 2 && M == 1){
            cout << "POSSIBLE" << endl;
            cout << "01" << endl;
            cout << "00" << endl;
            continue;
        }
        solve();
    }
}
