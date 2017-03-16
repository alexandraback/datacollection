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

bool solve(int );

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
        bool ans = solve(casenum);
//      cout << std::fixed;
//      cout.precision(7);
        if(ans){

            debug << "T" << endl;
            cout << "GABRIEL" << endl;
        }
        else{

            debug << "F" << endl;
            cout << "RICHARD" << endl;
        }

    }
    return 0;
}

bool solve(int case_id){
    debug << "=======================" << endl;
    debug << "==  Case :" << case_id << endl;
    debug << "=======================" << endl;

    int X,R,C;
    cin >> X >> R >> C;
    fprintf(stderr,"X:%d R: %d C: %d\t",X,R,C);
    if ( X ==1 ){
        return true;
    } else if (X == 2){
        return (R*C) % 2 ==0? true: false;
    } else if( X == 3){
        if(((R*C) % 3 )== 0) {
            if (R ==1 || C==1) return false;
//            else if (R*C==9) return false;
            else return true;
        } else
            return false;
    } else {
        if( ((R*C)%4) == 0){
            if( R==1 || C ==1) return false;
            else if (R ==2 || C == 2) return false;
            else if (R == 3 || C == 3) return true;
            else return true;
        }
        else
            return false;
    }

}
