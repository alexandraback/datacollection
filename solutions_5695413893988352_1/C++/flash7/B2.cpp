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

LL str2int(string s) {
	stringstream ss(s);
	LL x;
	ss >> x;
	return x;
}

string int2str(LL a) {
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

LL res = 1000000000000000005;
string resA,resB;

void updateRes(string A,string B){
    LL aa = str2int(A);
    LL bb = str2int(B);
    LL dif = abs(aa-bb);
    if(dif<res){
        res = dif;
        resA = A;
        resB = B;
    }else if(dif == res){
        if(A<resA){
            res = dif;
            resA = A;
            resB = B;
        }else if(A == resA){
            if(B<resB){
                res = dif;
                resA = A;
                resB = B;
            }
        }
    }
}

void call(int cur,string sC,string sJ,int f){
    if(cur == N){
        updateRes(sC,sJ);
        return;
    }
    if(f == 0){
        if(sC[cur] == '?' && sJ[cur] == '?'){
            string nsC = sC,nsJ = sJ;
            nsC[cur] = '0';
            nsJ[cur] = '0';
            call(cur+1,nsC,nsJ,0);
        }else if(sC[cur] == '?'){
            char ch0 = sJ[cur],ch1 = sJ[cur],ch2 = sJ[cur];
            ch1++;ch2--;
            if(ch1>'9') ch1 = '0';
            if(ch2<'0') ch2 = '9';

            string nsC;

            nsC = sC;
            nsC[cur] = ch0;
            if(nsC[cur] == sJ[cur]) call(cur+1,nsC,sJ,0);
            else if(nsC[cur] > sJ[cur]) call(cur+1,nsC,sJ,1);
            else call(cur+1,nsC,sJ,2);

            nsC = sC;
            nsC[cur] = ch1;
            if(nsC[cur] == sJ[cur]) call(cur+1,nsC,sJ,0);
            else if(nsC[cur] > sJ[cur]) call(cur+1,nsC,sJ,1);
            else call(cur+1,nsC,sJ,2);

            nsC = sC;
            nsC[cur] = ch2;
            if(nsC[cur] == sJ[cur]) call(cur+1,nsC,sJ,0);
            else if(nsC[cur] > sJ[cur]) call(cur+1,nsC,sJ,1);
            else call(cur+1,nsC,sJ,2);

        }else if(sJ[cur] == '?'){
            char ch0 = sC[cur],ch1 = sC[cur],ch2 = sC[cur];
            ch1++;ch2--;
            if(ch1>'9') ch1 = '0';
            if(ch2<'0') ch2 = '9';

            string nsJ;

            nsJ = sJ;
            nsJ[cur] = ch0;
            if(sC[cur] == nsJ[cur]) call(cur+1,sC,nsJ,0);
            else if(sC[cur] > nsJ[cur]) call(cur+1,sC,nsJ,1);
            else call(cur+1,sC,nsJ,2);

            nsJ = sJ;
            nsJ[cur] = ch1;
            if(sC[cur] == nsJ[cur]) call(cur+1,sC,nsJ,0);
            else if(sC[cur] > nsJ[cur]) call(cur+1,sC,nsJ,1);
            else call(cur+1,sC,nsJ,2);

            nsJ = sJ;
            nsJ[cur] = ch2;
            if(sC[cur] == nsJ[cur]) call(cur+1,sC,nsJ,0);
            else if(sC[cur] > nsJ[cur]) call(cur+1,sC,nsJ,1);
            else call(cur+1,sC,nsJ,2);
        }else{
            if(sC[cur] == sJ[cur]) call(cur+1,sC,sJ,0);
            else if(sC[cur] > sJ[cur]) call(cur+1,sC,sJ,1);
            else call(cur+1,sC,sJ,2);
        }
        return;
    }else if(f == 1){
        if(sC[cur] == '?' && sJ[cur] == '?'){
            sC[cur] = '0';
            sJ[cur] = '9';
        }else if(sC[cur] == '?'){
            sC[cur] = '0';
        }else if(sJ[cur] == '?'){
            sJ[cur] = '9';
        }
        call(cur+1,sC,sJ,f);
    }else{
        if(sC[cur] == '?' && sJ[cur] == '?'){
            sC[cur] = '9';
            sJ[cur] = '0';
        }else if(sC[cur] == '?'){
            sC[cur] = '9';
        }else if(sJ[cur] == '?'){
            sJ[cur] = '0';
        }
        call(cur+1,sC,sJ,f);
    }
}

int main(){
    read("input.txt");
    write("output_2.txt");
    fast_cin;
    int nCase;
    cin >> nCase;
    for(int cs = 1;cs<=nCase;cs++){
        cin >> sC >> sJ;
        N = sC.length();
        cout << "Case #" << cs << ": ";
        res = 1000000000000000005;
        string a = sC,b = sJ;
        call(0,a,b,0);
        cout << resA << " " << resB << endl;
    }
}
