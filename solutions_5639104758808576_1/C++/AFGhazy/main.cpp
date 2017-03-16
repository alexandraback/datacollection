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
#define     I9              (ll)1000000000
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

int main(){ _();
    freopen("A-large.in","r",stdin);
    freopen("A-large.out","w",stdout);
    int tc; tk(tc);
    for(int t = 1; t <= tc; t++){
        int n; tk(n);
        string s;
        tk(s);
        int ans = 0;
        int reached = (s[0]-'0');
        for(size_t i = 1; i <= n; i++){
            if(reached < i){
                ans += (i - reached);
                reached = i;
            }
            reached += (s[i] - '0');
        }
        cout << "Case #" << t << ": " << ans << endl;
    }
}
