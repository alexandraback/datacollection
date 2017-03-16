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

using namespace std;
#define mp make_pair
#define pii pair<int , char>
pii getValue( char a , char b ){

    if( a == 'i' ){
        if( b == 'j' )
            return mp(1 , 'k');
        if( b == 'k' )
            return mp(-1 , 'j');
        return mp(-1 , 0 );
    }
    if( a == 'j' ){
        if( b == 'i' )
            return mp( -1 , 'k');
        if( b == 'k' )
            return mp(1 , 'i');
        return mp(-1 , 0 );
    }
    if( a == 'k' ){
        if( b == 'i' )
            return mp(1 , 'j');
        if( b == 'j' )
            return mp(-1 , 'i');
        return mp(-1 , 0);
    }
    if( a == 0 )
        return pii(1 , b);
}

int main(){
    string s , tmp;
    int t, q , L , X;
    scanf("%d" , &t );
    for( q = 1 ; q <= t && scanf("%d %d" , &L , &X) ; ++q ){
        cin>>tmp;
        s = "";
        for( int i = 0 ; i < X ; ++i )
            s += tmp;
        int sign = 1;
        char act = s[0];
        int i = 1;
        bool iFound = false , jFound = false, kFound = false;
        for( ; i < s.length() ; ++i ){
            if( sign == 1 && act == 'i' ){
                iFound = true;
                break;
            }

            pii p = getValue( act , s[i] );
            int op = p.first;
            char res = p.second;
            sign *= op;
            act = res;
            /*if( res != 0 ){
                act = res;
            }*/
        }

        if( sign == 1 && act == 'i' ){
            iFound = true;
            act = s[i++];
        }

        //cout<<iFound<<" "<<i<<" "<<act<<endl;
        for( ; i < s.length() ; ++i ){
            if( sign == 1 && act == 'j' ){
                break;
            }

            pii p = getValue( act , s[i] );
            int op = p.first;
            char res = p.second;
            sign *= op;
            //if( res != 0 ){
                act = res;
            //}
        }

        if( sign == 1 && act == 'j' ){
            jFound = true;
            act = s[i++];
        }
        //cout<<jFound<<" "<<i<<" "<<act<<endl;

        //cout<<jFound<<" "<<s<<endl;

        for( ; i < s.length() ; ++i ){
            pii p = getValue( act , s[i] );
            int op = p.first;
            char res = p.second;
            sign *= op;
            //if( res != 0 ){
                act = res;
            //}
        }
        //cout<<sign<<" "<<act<<endl;
        if( sign == 1 && act == 'k' ){
            kFound = true;
        }



        printf("Case #%d: " , q  );
        if( iFound && jFound && kFound ){
            puts("YES");
        }else
            puts("NO");
    }
    return 0;
}
