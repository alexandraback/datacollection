#include <iostream>
#include <cstdio>
#include <cmath>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <deque>
#include <memory.h>
#include <string>
#include <cstring>
#include <regex>

using namespace std;

bool isPalindrom(long long a){
    vector<int> p;
    while(a){
        p.push_back(a%10);
        a/=10;
    }
    for(int i = 0; i < p.size(); i++)
        if(p[i] != p[p.size() - 1 - i])
            return false;
    return true;
}

vector<long long> palindroms;

int main()
{
    for(long long i = 1; i < 10000000; i++)
        if(isPalindrom(i * i) && isPalindrom(i)){
            palindroms.push_back(i * i);
        }

    freopen("C-large-1.in","r",stdin);
    freopen("C.out","w",stdout);
    int T;
    scanf("%d",&T);
    for(int z = 0; z < T; z++){
        printf("Case #%d: ",z+1);
        long long A, B;
        scanf("%lld%lld",&A,&B);
        int k = 0;
        for(int i = 0; i < palindroms.size(); i++)
            if(palindroms[i] <= B && palindroms[i] >= A){
                //printf("%lld ",palindroms[i]);
                k++;
            }
        printf("%d",k);
        printf("\n");
    }
    return 0;
}

