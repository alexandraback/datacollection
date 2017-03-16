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

int s(int a, int b){
    return (b ? -1 : 1) * a;
}

int result(int a , int b){
    //
    int c = 0;
    if(a * b < 0) c = 1;
    a = abs(a), b = abs(b);
    if(a == 1 || b == 1) return s(a*b,c);
    if(a == b) return s(-1,c);
    if(a == 2){
        if(b == 3) return s(4,c);
        if(b == 4) return s(-3,c);
    }
    if(a == 3){
        if(b == 2) return s(-4,c);
        if(b == 4) return s(2,c);
    }
    if(a == 4){
        if(b == 2) return s(3,c);
        if(b == 3) return s(-2,c);
    }
    // bug("not handled");
    return -1;
}

int main()
{
    //bug(s(5,0));
    _();
    freopen("C-small-attempt0.in" , "r" , stdin);
    freopen("C-small-attempt0.out" , "w" , stdout);
    int tc; tk(tc);
    long long l,x;
    for(int t = 1; t <= tc; t++){
        tk(l,x);
        string s;
        tk(s);
        int res = 1;
        bool one_time = false;
        bool two_time = false;
        for(size_t i = 0;i < s.length();i++) res = result(res , s[i] - 'i' + 2);
        if(res == 1) one_time = true;
        else
        {
            res = 1;
            string tmp = s; tmp += s;
            for(size_t i = 0;i < tmp.length();i++) res = result(res , tmp[i] - 'i' + 2);
            if(res == 1) two_time = true;
        }
        bool got_I = false,got_J = false,got_k = false;
        res = 1;
        string checker = "";
        int j = 0;
        for(int i = 0, number_concatination = 1;i < x&&number_concatination<=12;i++,number_concatination++){
            checker += s;
            for(;j < checker.length();j++){
                res = result(res , checker[j] - 'i' + 2);
                if(res == 2 && !got_I) got_I = true,res = 1;
                if(res == 3 && got_I && !got_J) got_J = true,res = 1;
                //bug(res);
            }
            //bug(one_time,two_time,number_concatination, got_I, got_J);
            if(res == 4 && got_I && got_J){
                if(one_time ||
                   (two_time && (x - number_concatination) % 2 == 0) ||
                   (x - number_concatination) % 4 == 0){
                    got_k = true;
                    //bug(number_concatination);
                    //bug(got_k);
                    break;
                }
            }
        }
        //bug(got_k);
        if(got_k) cout<<"Case #"<<t<<": YES"<<endl;
        else cout<<"Case #"<<t<< ": NO"<<endl;
    }
}

