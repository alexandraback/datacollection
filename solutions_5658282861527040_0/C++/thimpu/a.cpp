#include <iostream>
#include <string>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <list>
#include <set>
#include <cmath>
#include <cstring>
#include <stdio.h>
#include <string.h>
#include <sstream>
#include <stdlib.h>
#include <vector>

using namespace std;


int main()
{
    freopen("b.in", "r", stdin);
    freopen("b.out", "w", stdout);
    int CaseNo=1 , A, B , K, cnt, tCase;
    scanf("%d", &tCase);
    while(tCase--)
    {       cnt=0;
            scanf("%d %d %d", &A, &B, &K);
            for(int i = 0;i<A; i++)
            for(int j =0;j<B; j++){
                if((i & j)<K) cnt++;
            }
            printf("Case #%d: %d\n", CaseNo++ , cnt);
    }
    return 0;
}

