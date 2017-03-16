#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <stdlib.h>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <functional>
#include <numeric>
#include <utility>
#include <deque>
#include <stack>
#include <bitset>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <queue>
#include <limits>
#include <fstream>
#include <list>
#include <sstream>
#include <iostream>
#include <iomanip>
//#include <time.h>
using namespace std;
#define MAX 1005
#define pii pair<long long , long long>
#define mp make_pair
string toStr(int n){string s;ostringstream buffer;buffer<<n;s=buffer.str();return s;}
int toInt(string str){int n;istringstream buffer(str);buffer>>n;return n;}
bool correct(string s){
    for( int i = 0 ; i < s.length() ; ++i ){
        if( s[i] == '?') return false;
    }
    return true;
}

int minDif;
string c, j;
void solve(string C, string J){

    if( correct(C) && correct(J) ){
        int nc = toInt(C), nj = toInt(J);

        if( minDif > abs(nc - nj)){
            minDif = abs(nc - nj);
            c = C; j = J;
        }else if( minDif == abs(nc - nj) ){
            int n1 = toInt(c) , n2 = toInt(C);
            if( n2 < n1 ){
                c = C;
                j = J;
            }else if( n2 == n1 ){
                n1 = toInt(j); n2 = toInt(J);
                if( n2 < n1 ){
                    j = J;
                }
            }
        }

        return;
    }
    //cout<<C<<" "<<J<<endl;
    int sz = C.size();
    for( int i = 0 ; i < sz ; ++i ){
        if( C[i] == '?' ){
            for( int j = 0 ; j < 10 ; ++j ){
                C[i] = (char)(j + '0');
                if( J[i] == '?' ){
                    for( int k = 0 ; k < 10 ; ++k ){
                        J[i] = (char)(k + '0');
                        solve(C,J);

                    }
                    J[i] = '?';
                }else{
                    solve(C,J);
                }
                C[i] = '?';
            }
        }else if( J[i] == '?'){
            for( int k = 0 ; k < 10 ; ++k ){
                J[i] = (char)(k + '0');
                solve(C,J);
            }
            J[i] = '?';
        }
    }
}

int main() {
    //srand (time(NULL));
    int t;
    scanf("%d", &t) ;
    string C, J;
    for( int q = 1 ; q <= t && cin>>C>>J ; ++q ){
        int sz = C.size();
        if( C == "???" && J == "???" ){
            c = "000"; j = "000";
        }else{

        minDif = 1<<30;
        c = "";
        j = "";
        solve( C, J);
        }
        printf("Case #%d: ", q  );
        cout<<c<<" "<<j<<endl;
    }
    return 0 ;
}
