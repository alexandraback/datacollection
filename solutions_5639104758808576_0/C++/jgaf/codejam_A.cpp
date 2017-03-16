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
    int t, q , n;
    //freopen( "input.txt", "r", stdin );
	//freopen( "output.txt", "w", stdout );
    scanf("%d" , &t );
    string s;
    for( q = 1 ; q <= t && cin>>n>>s ; ++q ){
        int ans = 0;
        int sum = s[0] - '0';
        for( int i = 1 ; i <= n ; ++i ){
            //cout<<s[i]<<" -- "<<sum<<" -- "<<i<<endl;
            if( sum >= i ){
                sum += s[i] - '0';
                continue;
            }else{
                int dif = i - sum;
                ans += dif;
                sum = i  + s[i] - '0';
            }
        }
        printf("Case #%d: %d\n" , q , ans  );
    }
    return 0;
}
