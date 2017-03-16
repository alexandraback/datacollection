#include <iostream>
#include <cstdio>
#include <cmath>
#include <deque>
#include <map>
#include <cstring>
#include <string>
#include <cstdlib>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <memory.h>
#include <list>
#include <complex>
#include <sstream>

using namespace std;

char s[1000005];

bool isVovel(char c){
    if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
        return true;
    else
        return false;
}

int main()
{
    freopen("A-small-attempt1.in","r",stdin);
    freopen("A.out","w",stdout);
    int TestNumbers;
    scanf("%d",&TestNumbers);
    for(int test = 0; test < TestNumbers; test++)
    {
        printf("Case #%d: ", test + 1);

        int n;
        scanf("%s%d",s,&n);

        int leftPointer = -1;
        int rightPointer = 0;
        int current = 0;

        long long result = 0;
        int len = strlen(s);

        for(int i = 0; i < len; i++){
            if(!isVovel(s[i])){
                current++;
                if(current >= n){
                    result += (long long)(i - n + 1 - leftPointer) * (long long)(len - i);
                    if(current == n)
                        leftPointer = i - n + 1;
                    else
                        leftPointer++;
                }
            }
            else{
                current = 0;
            }
        }
        printf("%lld",result);
        printf("\n");
    }
    return 0;
}

