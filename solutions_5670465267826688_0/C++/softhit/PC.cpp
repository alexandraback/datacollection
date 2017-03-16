//
// Created by LH on 4/10/15.
//
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <cstring>
#include <stdio.h>  /* defines FILENAME_MAX */
#include <algorithm>
#include <functional>   // std::minus
#include <numeric>      // std::accumulate
#include <map>
#include <deque>
#include <set>
#include <sstream>
#include <unistd.h>
#define GetCurrentDir getcwd
#include <typeinfo>

using namespace std;
#define debug cerr

template<typename T> void print_vector(const vector<T> & V){
    stringstream out;
    for(int i=0;i<V.size()-1;i++){
        out << V[i]<<", ";
    }
    out << V[V.size()-1];
    debug << "{" << out.str() <<"}" << endl;;

}
template< typename T > void print_map(const T & m) {
    vector <string> out;
    for( auto it:m)
    {
        string tmp = it.first + ":" + to_string(it.second) ;
        out.push_back(tmp);
    }
    print_vector(out);
}
template<typename T> bool inSet( const set<T> st,T &item) {
    return st.find(item) != st.end();
}

void solve(int );

int main(int argc,char *args[]){
    if(argc == 2 && strcmp(args[1],"sample") == 0){

        freopen("sample.in", "rt", stdin);
        freopen("sample.out", "wt",stdout);
        debug << "Using sample input set" <<endl;

    } else if(argc == 2 && strcmp(args[1],"small") == 0){

        freopen("small.in", "rt", stdin);
        freopen("small.out", "wt",stdout);
        debug << "Using small input set" <<endl;

    } else if(argc == 2 && strcmp(args[1],"large") == 0){

        freopen("large.in", "rt", stdin);
        freopen("large.out", "wt",stdout);
        debug << "Using Large input set" <<endl;

    } else {
        debug << "invalid argusments" <<endl;
        debug << "usage: " << args[0] <<" sample | small | large" << endl;
        return -1;
    }
    char cCurrentPath[FILENAME_MAX];

    if (!GetCurrentDir(cCurrentPath, sizeof(cCurrentPath)))
    {
        return errno;
    }
    debug << "CWD: " <<  cCurrentPath << endl;

    int N;
    cin >> N;
    debug << "N = " << N << endl;
    debug.flush();
    cout.flush();
    for(int casenum=1;casenum <= N;casenum++){
        cout << "Case #"<< casenum  << ": " ;
        solve(casenum);
//      cout << std::fixed;
//      cout.precision(7);


    }
    return 0;
}
typedef enum { A, B,C,D,O,P,Q,R } Quat;
ostream &operator<<(ostream &out, const Quat &value) {
    static std::map<Quat, std::string> strings;
    if (strings.size() == 0) {
    #define INSERT_ELEMENT(p) strings[p] = #p
            INSERT_ELEMENT(A);
            INSERT_ELEMENT(B);
            INSERT_ELEMENT(C);
            INSERT_ELEMENT(D);
            INSERT_ELEMENT(O);
            INSERT_ELEMENT(P);
            INSERT_ELEMENT(Q);
            INSERT_ELEMENT(R);

    #undef INSERT_ELEMENT
    }
    return out << strings[value];
}
const Quat TLB[8][8]={
        { A,	B,	C,	D,	O,	P,	Q,	R },
        { B,	O,	D,	Q,	P,	A,	R,	C },
        { C,	R,	O,	B,	Q,	D,	A,	P },
        { D,	C,	P,	O,	R,	Q,	B,	A },
        { O,	P,	Q,	R,	A,	B,	C,	D },
        { P,	A,	R,	C,	B,	O,	D,	Q },
        { Q,	D,	A,	P,	C,	R,	O,	B },
        { R,	Q,	B,	A,	D,	C,	P,	O } };
inline Quat operator *(Quat a, Quat b){  return TLB[a][b];}

//inline Quat operator *(Quat a, Quat b){
//    #define TLB_A(m,n,l)  if ( a == Quat::m &&  b == Quat::n) return  Quat::l
//    #define TLB(m,n,l) else if ( a == Quat::m &&  b == Quat::n) return   Quat::l
//    #define TLB_E(m,n,l) else  return Quat::l
//
//    TLB_A(A,A,A); TLB(A,B,B); TLB(A,C,C); TLB(A,D,D);     TLB(A,O,O); TLB(A,P,P); TLB(A,Q,Q); TLB(A,R,R);
//    TLB(B,A,B); TLB(B,B,O); TLB(B,C,D); TLB(B,D,Q);     TLB(B,O,P); TLB(B,P,A); TLB(B,Q,R); TLB(B,R,C);
//    TLB(C,A,C); TLB(C,B,R); TLB(C,C,O); TLB(C,D,B);     TLB(C,O,Q); TLB(C,P,D); TLB(C,Q,A); TLB(C,R,P);
//    TLB(D,A,D); TLB(D,B,C); TLB(D,C,P); TLB(D,D,O);     TLB(D,O,R); TLB(D,P,Q); TLB(D,Q,B); TLB(D,R,A);
//
//    TLB(O,A,O); TLB(O,B,P); TLB(O,C,Q); TLB(O,D,R);     TLB(O,O,A); TLB(O,P,B); TLB(O,Q,C); TLB(O,R,D);
//    TLB(P,A,P); TLB(P,B,A); TLB(P,C,R); TLB(P,D,C);     TLB(P,O,B); TLB(P,P,O); TLB(P,Q,D); TLB(P,R,Q);
//    TLB(Q,A,Q); TLB(Q,B,D); TLB(Q,C,A); TLB(Q,D,P);     TLB(Q,O,C); TLB(Q,P,R); TLB(Q,Q,O); TLB(Q,R,B);
//    TLB(R,A,R); TLB(R,B,Q); TLB(R,C,B); TLB(R,D,A);     TLB(R,O,D); TLB(R,P,C); TLB(R,Q,P); TLB_E(R,R,O);
//    #undef TLB
//    #undef TLB_A
//    #undef TLB_E
//
//}

map<Quat,string> map2 ={
        {A," 1"}, {B, " i"}, {C, " j"}, {D, " k"},
        {O,"-1"}, {P, "-i"}, {Q, "-j"}, {R, "-k"} };
map<char,Quat> map1 ={
        {'1',A} , { 'i' , B} ,{ 'j', C} ,{ 'k' ,D},
        {'-1',O} , { '-i' , P} ,{ '-j', Q} ,{ '-k' ,R}
        };
void test_mul(){
    // test mult
    vector<Quat > va,vb;
    va = { A, B, C, D, O,P, Q,R};

    vb = va;
     debug << "\t" ;
    for (auto a:va) { debug << map2[a] << "\t" ;}
    debug << endl;
    for (auto a:va) {
        debug << map2[a] <<"\t";
        for (auto b:vb){
            debug <<  map2[a*b] << "\t";
        }
        debug << " ";
        debug << endl;
    }
    debug << " }"<<endl;
   exit(0);
}


void solve(int case_id){
    debug << "=======================" << endl;
    debug << "==  Case :" << case_id << endl;
    debug << "=======================" << endl;
    // test_mul();
    int L,X;
    string s;
    cin >> L >> X;
    getline(cin,s);
    getline(cin,s);
    string s1 = s;
    for(int i =0; i< X-1; i++) {
        s += s1;
    }
//    debug << "L : " << L << "\t X: " << X << "\t\t" << s << endl;
//    Quat * vary ;
    long tlen= L*X;
    Quat vary[10000]={A};

//    vary = new Quat [tlen];
//    vector<Quat> vary(10000,A);
    int tt = 0;
    for(auto c:s){

        vary[tt]= map1[c];
        tt++;
    }
    debug <<" tlen: " << tlen << "tt: " << tt << endl;
//    auto res = accumulate(vec.begin(),vec.end(),A,std::multiplies<Quat>());
//    debug << "Result :" << map2[res] << endl;
    // search:
    debug << "Length: " << tlen << endl;
    Quat p1=A,p2=A,p3=A;
    bool reduciable =false;
    // precheck:
    Quat tp = accumulate(vary,vary+tlen,A,std::multiplies<Quat>());
    if(tp == O) {
    for(auto i=0; i < tlen-2;i++){
        // Match i, save index p1
//        debug << "P1 " << map2[p1] <<"_" << p1 << " cur: " << map2[vary[i]] <<"_" << vary[i]<< "\t i: " << i << endl;
        p1 = p1 * vary[i];
        if( p1 == B){
            // Match j, save index p2
            for (auto j=i+1;j<tlen-1;j++){
//                debug << "\tP2 " << map2[p2] << " cur: " << map2[vary[j]]<<"\t j: " << j << endl;
                p2 = p2 * vary[j];

                if( p2 == C){
//                    p3 = accumulate(vary+(j+1),vary+tlen,A,std::multiplies<Quat>());
                    for (auto k = j+1; k < tlen;k++){
//                        debug << "\t\tP3 " << map2[p3] <<" cur: " << map2[vary[j]]<< "\t k :" << k << endl;
                        p3 = p3* vary[k];

                    }
                    if(p3== D)
                        reduciable =true;
			break;
                }
            }
        }

        // Match k, save index p3
    }
   }
    string ans  = reduciable?"YES":"NO";
    debug << ans << endl;
    cout << ans << endl;


}

