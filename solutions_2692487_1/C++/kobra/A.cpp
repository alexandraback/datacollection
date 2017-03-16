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


vector<int> motes;
int solve(int N, int currentSize){
    if(currentSize == 1)
        return N;
    int quantityOfOperations = 0;
    for(int k = 0; k < N; k++){
        if(motes[k] < currentSize){
            currentSize += motes[k];
        }
        else
        {
            while(motes[k] >= currentSize){
                currentSize += currentSize - 1;
                quantityOfOperations++;
            }
            currentSize += motes[k];
        }
    }
    return quantityOfOperations;
}

int main()
{
    freopen("A-large (1).in","r",stdin);
    freopen("A.out","w",stdout);
    int TestNumbers;
    scanf("%d",&TestNumbers);
    for(int test = 0; test < TestNumbers; test++)
    {
        printf("Case #%d: ", test + 1);
        int currentSize;
        scanf("%d",&currentSize);
        int N;
        scanf("%d",&N);
        motes.clear();
        for(int i = 0; i < N; i++){
            int s;
            scanf("%d",&s);
            motes.push_back(s);
        }
        if (currentSize == 1)
            printf("%d",N);
        else
        {
            sort(motes.begin(), motes.end());
            int best = 1000;
            for(int i = 0; i <= N; i++)
            {
                int value = solve(i, currentSize);
                if(value + N - i < best)
                    best = value + N - i;
            }
            printf("%d", best);
        }


        printf("\n");
    }
    return 0;
}

