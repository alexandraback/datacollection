#include <bits/stdc++.h>
#define     mems(a,b)       memset(a,b,sizeof(a))
#define     IT              iterator
#define     mp              make_pair
#define     pb              push_back
#define     eps             1E-9
#define     all(a)          a.begin(),a.end()
#define     allr(a)         a.rbegin(),a.rend()
#define     MOD             (1000000007)
#define     llInf           (1LL<<62)
#define     iInf            (2123456789)
#define     o(i, start, n)          for(int i = start; i < n; i++)
#define     I3              (ll)1000
#define     I4              (ll)10000
#define     I5              (ll)100000
#define     I6              (ll)1000000
#define     I7              (ll)10000000
#define     I8              (ll)100000000
#define     I9              (ll)2000000000
#define     I10             (ll)10000000000
#define     I11             (ll)100000000000
#define     I12             (ll)1000000000000
#define     I13             (ll)10000000000000
#define     I14             (ll)100000000000000
#define     I15             (ll)1000000000000000
#define     I16             (ll)10000000000000000
#define     I17             (ll)100000000000000000
#define     I18             (ll)1000000000000000000
using namespace std;
typedef long long int ll;
typedef unsigned long long  ull;
typedef double dd;
typedef string str;
typedef char ch;
typedef int I;
inline void _(){ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0); }
void __(){
    #ifndef ONLINE_JUDGE
    cout << endl << "time elsaped : " << (double)clock() / CLOCKS_PER_SEC << " ms" << endl;
    #endif
}
inline void ___(char *i, char *j){ freopen(i, "r", stdin); freopen(j, "w", stdout); }

//input templates
template<class T1> bool tk(T1 &e1){if(cin>>e1)return true;return false;}
template<class T1,class T2> bool tk(T1 &e1,T2 &e2){if(cin>>e1>>e2)return true;return false;}
template<class T1,class T2,class T3> bool tk(T1 &e1,T2 &e2,T3 &e3){if(cin>>e1>>e2>>e3)return true;return false;}
template<class T1,class T2,class T3,class T4> bool tk(T1 &e1,T2 &e2,T3 &e3,T4 &e4){if(cin>>e1>>e2>>e3>>e4)return true;return false;}
template<class T1,class T2,class T3,class T4,class T5> bool tk(T1 &e1,T2 &e2,T3 &e3,T4 &e4,T5 &e5){if(cin>>e1>>e2>>e3>>e4>>e5)return true;return false;}
template<class T1,class T2,class T3,class T4,class T5, class T6> bool tk(T1 &e1,T2 &e2,T3 &e3,T4 &e4,T5 &e5,T6 &e6){if(cin>>e1>>e2>>e3>>e4>>e5>>e6)return true;return false;}

// output templates
template<class T1> void put(T1 e){cout<<e<<endl;}
template<class T1,class T2> void put(T1 e1,T2 e2){cout<<e1<<" "<<e2<<endl;}
template<class T1,class T2,class T3> void put(T1 e1,T2 e2,T3 e3){cout<<e1<<" "<<e2<<" "<<e3<<endl;}
template<class T1,class T2,class T3,class T4> void put(T1 e1,T2 e2,T3 e3,T4 e4){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<endl;}
template<class T1,class T2,class T3,class T4,class T5> void put(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<endl;}
template<class T1,class T2,class T3,class T4,class T5,class T6> void put(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5,T6 e6){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<" "<<e6<<endl;}
template<class T1> void putVec(vector<T1>e1){for(I i=0; i<(e1).size(); i++)(!i?cout<<e1[i]:cout<<" "<<e1[i]);cout<<endl;}
template<class T1> void putArr(T1 arr[],I l){for(I i=0; i<l; i++)(!i?cout<<arr[i]:cout<<" "<<arr[i]);cout<<endl;}
// end of output

// bug templates
template<class T1> void bug(T1 e){
    #ifndef ONLINE_JUDGE
    cout<<e<<endl;
    #endif
}
template<class T1,class T2> void bug(T1 e1,T2 e2){
    #ifndef ONLINE_JUDGE
    cout<<e1<<" "<<e2<<endl;
    #endif
}
template<class T1,class T2,class T3> void bug(T1 e1,T2 e2,T3 e3){
    #ifndef ONLINE_JUDGE
    cout<<e1<<" "<<e2<<" "<<e3<<endl;
    #endif
}
template<class T1,class T2,class T3,class T4> void bug(T1 e1,T2 e2,T3 e3,T4 e4){
    #ifndef ONLINE_JUDGE
    cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<endl;
    #endif
}
template<class T1,class T2,class T3,class T4,class T5> void bug(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5){
    #ifndef ONLINE_JUDGE
    cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<endl;
    #endif
}
template<class T1,class T2,class T3,class T4,class T5,class T6> void bug(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5,T6 e6){
    #ifndef ONLINE_JUDGE
    cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<" "<<e6<<endl;
    #endif
}
template<class T1> void bugVec(vector<T1>e1){
    #ifndef ONLINE_JUDGE
    for(I i=0; i<(e1).size(); i++)(!i?cout<<e1[i]:cout<<" "<<e1[i]);cout<<endl;
    #endif
}
template<class T1> void bugArr(T1 arr[],I l){
    #ifndef ONLINE_JUDGE
    for(I i=0; i<l; i++)(!i?cout<<arr[i]:cout<<" "<<arr[i]);cout<<endl;
    #endif
}
// end of bugs

namespace gv{

};

long long absolute(long long a){
    if(a < 0) return -a;
    return a;
}
/*
int lo = 0;
int mx = 0;
int dp[1005];
vector<int > v;

int solve(int num){
    if(num <= lo){ mx = max(mx,num); return 0; }
    int mn = I9;
    if(dp[num] != -1) return dp[num];
    for(int i = num-1; i >= 1; i--){
        mn = min(1 + solve(num-i) + solve(i), mn);
    }
    return dp[num]=mn;
}
*/
/*
int trylo(){
    memset(dp,-1,sizeof dp);
    int num = 0;
    int left = 0, right = 1002;
    while(left+2<right){
        int leftThird = left + (right - left)/3;
        int rightThird = right - (right - left)/3;
        lo = leftThird;
        num = 0;
        memset(dp,-1,sizeof dp);
        mx = 0;
        for(int i = 0; i < (int)v.size(); i++){
            mx = 0;
            int sol = solve(v[i]);
            mx += sol;
            num = max(mx, num);
        }
        int left_sol = num;
        lo = rightThird;
        num = 0;
        memset(dp,-1,sizeof dp);
        mx = 0;
        for(int i = 0; i < (int)v.size(); i++){
            mx = 0;
            int sol = solve(v[i]);
            mx += sol;
            num = max(mx, num);
        }
        int right_sol = num;
        if(left_sol <= right_sol){
            right = rightThird;
        }else{
            left = leftThird;
        }
    }
    int ans = I9;
    for(;left<=right;left++){
        num = 0;
            memset(dp,-1,sizeof dp);
            mx = 0;
            for(int i = 0; i < (int)v.size(); i++){
                mx = 0;
                int sol = solve(v[i]);
                mx += sol;
                num = max(mx, num);
            }
        ans = min(ans,num);
    }
    return ans;
}

int tryhi(){
    memset(dp,-1,sizeof dp);
    int num = 0;
    int left = 0, right = 1002;
    while(left+2<right){
        int leftThird = left + (right - left)/3;
        int rightThird = right - (right - left)/3;
        lo = leftThird;
        num = 0;
        memset(dp,-1,sizeof dp);
        mx = 0;
        for(int i = 0; i < (int)v.size(); i++){
            mx = 0;
            int sol = solve(v[i]);
            mx += sol;
            num = max(mx, num);
        }
        int left_sol = num;
        lo = rightThird;
        num = 0;
        memset(dp,-1,sizeof dp);
        mx = 0;
        for(int i = 0; i < (int)v.size(); i++){
            mx = 0;
            int sol = solve(v[i]);
            mx += sol;
            num = max(mx, num);
        }
        int right_sol = num;
        if(left_sol < right_sol){
            right = rightThird;
        }else{
            left = leftThird;
        }
    }
    int ans = I9;
    for(;left<=right;left++){
        num = 0;
            memset(dp,-1,sizeof dp);
            mx = 0;
            for(int i = 0; i < (int)v.size(); i++){
                mx = 0;
                int sol = solve(v[i]);
                mx += sol;
                num = max(mx, num);
            }
        ans = min(ans,num);
    }
    return ans;
}
*/



    /*
    freopen("B-small-attempt.in", "r", stdin);
    freopen("B-small-attempt.out", "w", stdout);
    int tc; tk(tc);
    for(int i = 1; i <= tc; i++){
        v.clear();
        int n; tk(n);
        for(int j = 0,k; j < n; j++){
            tk(k);
            v.push_back(k);
        }
        cout << "Case #" << i << ": ";
        put(min(trylo(),tryhi()));
    }
    */

int d[1050] , D;
int solveGreedy(int lower){
    int additional_time = 0;
    int main_time = 0;
    for(int i = 0;i < D;i++){
        if(d[i] > lower) additional_time += ((d[i] + (lower - 1)) / lower) - 1,main_time = max(main_time , lower);
        else main_time = max(main_time , d[i]);
    }
    return additional_time + main_time;
}

int main()
{
    freopen("B-large.in", "r", stdin);
    freopen("B-large.out", "w", stdout);
    int tc , t = 0; tk(tc);
    while(tc--)
    {
        tk(D);
        for(int i = 0;i < D;i++)tk(d[i]);
        sort(d , d + D);
        int ans = I9;
        for(int i = d[D - 1];i > 0;i--) ans = min(ans , solveGreedy(i));
        cout<<"Case #"<<++t<<": "<<ans;
        put("");
    }
}
