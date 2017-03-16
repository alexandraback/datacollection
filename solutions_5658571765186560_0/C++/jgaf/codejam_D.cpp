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

int main(){
    int t, q , r , c , x;
    scanf("%d" , &t );
    for( q = 1 ; q <= t && scanf("%d %d %d" , &x , &r , &c ); ++q ){
        printf("Case #%d: " , q  );
        if( r * c < x ){
            puts("RICHARD");
        }else if( x == 1 ){
            puts("GABRIEL");
        }else if( x == 2 ){
            if( r == 1 ){
                if( c == 3 ){
                    puts("RICHARD");
                }else
                    puts("GABRIEL");
            }else if( r == 2 ){
                puts("GABRIEL");
            }else if( r == 3 ){
                if( c == 1 || c == 3 ){
                    puts("RICHARD");
                }else {
                    puts("GABRIEL");
                }
            }else{
                puts("GABRIEL");
            }
        }else if( x == 3 ){
            if( r == 1 ){
                if( c == 3 || c == 4 )
                    puts("RICHARD");
                else puts("GABRIEL");
            }else if( r == 2 ){
                if( c == 1 || c == 2 || c == 4 )
                    puts("RICHARD");
                else puts("GABRIEL");
            }else if( r == 3 ){
                if( c == 1 )
                    puts("RICHARD");
                else
                    puts("GABRIEL");
            }else{
                if( c == 1 || c == 2 || c == 4 )
                    puts("RICHARD");
                else
                    puts("GABRIEL");
            }
        }else if( x == 4 ){
            if( r == 1 ){
                puts("RICHARD");
            }else if( r == 2 ){
                if( c == 2 || c == 3 || c == 4 )
                    puts("RICHARD");
                else
                    puts("GABRIEL");
            }else if( r == 3 ){
                if( c == 2  || c == 3 )
                    puts("RICHARD");
                else
                    puts("GABRIEL");
            }else{
                if( c == 1 || c == 2 )
                    puts("RICHARD");
                else
                    puts("GABRIEL");
            }
        }

    }
    return 0;
}
