#include <iostream>
#include <stdio.h>
#include <vector>
#include <string.h>
#include <utility>
#include <algorithm>
#include <queue>
using namespace std;

int main(){
    int runs, i , j, R, C, W, cnt;
    cin>>runs;
    for(j=1; j<=runs; j++){
        cin>>R>>C>>W;
        cnt=0;
        cnt += C/W;
        cnt*=R;
        if(C%W != 0)
            cnt++;
        cnt+=W-1;
        printf("Case #%d: %d\n", j, cnt);
    }
    return 0;
}
