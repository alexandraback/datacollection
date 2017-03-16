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

int A, B , K;
int main(){
    int t, q , i,  j;
    freopen( "input.txt", "r", stdin );
	freopen( "output.txt", "w", stdout );
    scanf("%d" , &t );
    for( q = 1 ; q <= t && scanf("%d %d %d" , &A , &B , &K ); ++q ){
        int cnt = 0;
        for( int i = 0 ; i < A ; ++i ){
            for( int j = 0 ; j < B ; ++j ){
                if( ( i & j ) < K ){
                    cnt++;
                }
            }
        }
        printf("Case #%d: %d\n" , q , cnt );

    }
    return 0;
}
