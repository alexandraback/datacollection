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
#include <typeinfo>

using namespace std;
#define GetCurrentDir getcwd
#define debug cerr

template<typename T> void print_vector(const vector<T> & V){
    stringstream out;
    for(int i=0;i<V.size()-1;i++){
        out << V[i]<<", ";
    }
    out << V[V.size()-1];
    debug << "{" << out.str() <<"}" << endl;;

}
template<typename T> string str_vector(const vector<T> & V){
    stringstream out;
    out << "{";
    for(int i=0;i<V.size()-1;i++){
        out << V[i]<<", ";
    }
    out << V[V.size()-1];
    out <<"}" ;
    return out.str();

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

void solve(int case_id){
    debug << "=======================" << endl;
    debug << "==  Case :" << case_id << endl;
    debug << "=======================" << endl;

    int D;
    vector<int> P;
    cin >> D ;
    int total = 0;
    int max_cake = 0;
    for (auto i=0; i< D; i++ ){
        int t2;
        cin >> t2;
        if (max_cake < t2 ) {
            max_cake = t2;

        }
        total += t2;
        P.push_back(t2);
    }
//    debug << "D : " << D << " Total : " << total
//    << " Max : " << max_cake << endl;
    // Sorting on P
    sort(P.begin(),P.end(),greater_equal<int>());
    print_vector(P);
    int ans = max_cake;
    int special=0;
    for(int i =1;i<=max_cake;i++){
        special = 0;
        for(auto q:P){
            if(q < i)
                break;
            special += ceil(((float)q) / (float) i ) -1 ;
        }
        if (special + i < ans)
            ans = special + i;

    }
    debug << "Res : " << ans << endl;
    cout << ans << endl;




}
