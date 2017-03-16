#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <bitset>
#include <cmath>
#include <numeric>
#include <iterator>
#include <iostream>
#include <cstdlib>
#include <functional>
#include <queue>
#include <stack>
#include <list>
using namespace std;

int T,N;
int heights[3333];

int main() {
    scanf("%d",&T);
    int cases = 1;
    while( T -- ) {
        scanf("%d",&N);
        memset(heights,0,sizeof(heights));
        int t;
        for(int i = 0 ; i  < N + N - 1 ; i++ ) {
            for(int j = 0 ; j < N; j++ ){
                scanf("%d",&t);
                heights[t]++;
            }
            
        }
        vector<int> vec;
        for(int i = 0 ; i < 3333;i++ ){
            if( heights[i]&1 ) vec.push_back(i);
        }
        printf("Case #%d:",cases++);
        for(int i = 0 ; i < vec.size() ;i ++ ){
            printf(" %d",vec[i]);
        }
        printf("\n");
    }
    return 0;
}