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

void solve(int case_id){
    debug << "=======================" << endl;
    debug << "==  Case :" << case_id << endl;
    debug << "=======================" << endl;

    int Smax;
    vector <int> Slist;
    cin >> Smax ;
    debug << "Smax :" << Smax<< endl;
    for (int i = 0; i<= Smax ; i++){
        char c;
        cin >> c;
        Slist.push_back(int(c) - int('0')) ;
    }
    print_vector(Slist);
    int sum = 0;
    int r = 0;
    for (int k= 0 ; k<= Smax; k++){
        if (k != 0 && sum < k){
            if( Slist[k] > 0) {
                r += k  - sum;
                sum += Slist[k] +( k  - sum) ;
            } else {
                sum += Slist[k] ;

            }


//            if(r < 0 ){
//                r = 0;
//            }
        } else {

            sum += Slist[k] ;
        }
        debug << " K: " << k << " Sum :" << sum << " R : " << r << endl;

    }
    debug << r << endl;
    cout << r << endl;
}
