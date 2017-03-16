#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <memory>
#include <cstring>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <set>
#include <iostream>

using namespace std;
typedef pair <int, int> pii;

int results[25];
int numbers[30];
int numCount;
int usedCount = 0;

bool calculate(int diff, int curNum)
{
    if (diff == 0 && usedCount != 0)
        return true;
    
    if (curNum == numCount)
        return false;
    
    results[curNum] = 0;
    if(calculate(diff, curNum+1))
        return true;
    
    usedCount++;
    results[curNum] = 1;
    if(calculate(diff + numbers[curNum], curNum+1))
        return true;
    results[curNum] = 2;
    if(calculate(diff - numbers[curNum], curNum+1))
        return true;
    results[curNum] = 0;
    usedCount--;
    return false;
}

void test(int testNo)
{
    int pc;
    scanf("%d", &pc);
    numCount = pc;
    usedCount = 0;
    memset(results, 0, sizeof(results));
    
    for (int i = 0; i < pc; i++)
        scanf("%d", numbers+i);
    
    printf("Case #%d: \n", testNo+1);
    
    if (calculate(0, 0))
    {
        int sum = 0;
        for (int i = 0; i < pc; i++)
            if (results[i] == 1)
            {
                printf("%d ", numbers[i]);
                sum += numbers[i];
            }
        printf("\n");
        for (int i = 0; i < pc; i++)
            if (results[i] == 2)
            {
                printf("%d ", numbers[i]);
                sum -= numbers[i];
            }
        printf("\n");
        if (sum != 0)
            printf("BIDA");
    }
    else
    {
        printf("Impossible\n");
    }
    
}

int main()
{
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
    int TC;
    scanf("%d", &TC);
    
    for (int i = 0; i < TC; i++)
        test(i);
    
    return 0;
}

