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

int str2int(string s) {
	stringstream ss(s);
	int x;
	ss >> x;
	return x;
}

string int2str(int a) {
	stringstream ss;
	ss << a;
	string str = ss.str();
	return str;
}

string char2str(char a) {
	stringstream ss;
	ss << a;
	string str = ss.str();
	return str;
}

#define INF (1<<30)
#define MOD 1000000007

#define Size 1000005

string sC,sJ;
int N;
vector<int> rC,rJ;

void call_1(int cur,int num){
    if(cur == N){
        rC.pb(num);
        return;
    }
    if(sC[cur] == '?'){
        for(int d = 0;d<10;d++){
            call_1(cur+1,num*10+d);
        }
    }else{
        int d = (int)(sC[cur]-'0');
        call_1(cur+1,num*10+d);
    }
}

void call_2(int cur,int num){
    if(cur == N){
        rJ.pb(num);
        return;
    }
    if(sJ[cur] == '?'){
        for(int d = 0;d<10;d++){
            call_2(cur+1,num*10+d);
        }
    }else{
        int d = (int)(sJ[cur]-'0');
        call_2(cur+1,num*10+d);
    }
}

void solve(){
    rC.clear();
    rJ.clear();
    call_1(0,0);
    call_2(0,0);
    int L1 = rC.size();
    int L2 = rJ.size();
    int res = 10000000,A = 1000000,B = 1000000;
    for(int i = 0;i<L1;i++){
        for(int j = 0;j<L2;j++){
            int dif = abs(rC[i]-rJ[j]);
            if(dif<res){
                res = dif;
                A = rC[i];
                B = rJ[j];
            }else if(dif == res){
                if(rC[i]<A){
                    A = rC[i];
                    B = rJ[j];
                }else if(rC[i] == A){
                    if(rJ[j]<B){
                        A = rC[i];
                        B = rJ[j];
                    }
                }
            }
        }
    }
    string a = int2str(A);
    string b = int2str(B);
    for(int i = 0;i<N-a.length();i++) cout << "0";
    cout << a;
    cout << " ";
    for(int i = 0;i<N-b.length();i++) cout << "0";
    cout << b;
    cout << endl;
}

int main(){
    read("input.txt");
    write("output_1.txt");
    fast_cin;
    int nCase;
    cin >> nCase;
    for(int cs = 1;cs<=nCase;cs++){
        cin >> sC >> sJ;
        N = sC.length();
        cout << "Case #" << cs << ": ";
        solve();
    }
}
