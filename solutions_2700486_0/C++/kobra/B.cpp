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

int sizeOfTriangle(int N){
    int k = 1;
    int current = 2;
    if(N == 1)
        return 0;
    else
        N--;
    while(true){
        if (N > 2 * current + 1)
        {
            N -= 2 * current + 1;
            current += 2;
            k++;
        }
        else
            break;
    }
    return k;
}

pair<int, int> getSizeOfNextTriangle(int N){
    int k = 1;
    int current = 2;
    if(N == 1)
        return make_pair(1, 1);
    else
        N--;
    while(true){
        if (N > 2 * current + 1)
        {
            N -= 2 * current + 1;
            current += 2;
            k++;
        }
        else
            break;
    }
    return make_pair(k + 1, N);
}

bool belong(int size, int x, int y){
    if(2 * size - 2 >= abs(x) + abs(y))
        return true;
    else
        return false;
}

int Ar[2000];

void fact1(int N){
    int p = 2;
    while(p * p <= N){
        while(N % p == 0){
            N /= p;
            Ar[p]++;
        }
        p++;
    }
    if(N != 1)
        Ar[N]++;
}

void fact2(int N){
    int p = 2;
    while(p * p <= N){
        while(N % p == 0){
            N /= p;
            Ar[p]--;
        }
        p++;
    }
    if(N != 1)
        Ar[N]--;
}

double Bernulli(int experiments, int succeded){
    memset(Ar,0,sizeof(Ar));
    for(int i = 1; i <= experiments; i++)
        fact1(i);
    for(int i = 1; i <= succeded; i++)
        fact2(i);
    for(int i = 1; i <= experiments - succeded; i++)
        fact2(i);
    double result = 1;
    for(int i = 2; i <= max(experiments, succeded); i++)
        while(Ar[i])
        {
            result *= i;
            Ar[i]--;
        }
    return result;
}

double calc(int maxInSide, int used, int needed){
    if(used < needed)
        return 0;

    int minimumInSide = max(used - maxInSide, 0);

    double result1 = 0;
    for(int i = minimumInSide; i < needed; i++){
        result1 += Bernulli(used, i);
    }

    double result2 = 0;
    for(int i = 0; i < minimumInSide; i++)
        result2 += 2 * Bernulli(used, i);


    double result = pow(2.0, (double)used);
    result = result - result2;
    result = result1 / result;
    result = 1 - result;
    return result;

}

int main()
{
    freopen("B-small-attempt1.in","r",stdin);
    freopen("B.out","w",stdout);
    int TestNumbers;
    scanf("%d",&TestNumbers);
    for(int test = 0; test < TestNumbers; test++)
    {
        printf("Case #%d: ", test + 1);

        int N, x, y;
        scanf("%d%d%d",&N,&x,&y);
        int finished = sizeOfTriangle(N);
        pair<int, int> lastLayer = getSizeOfNextTriangle(N);

        if(belong(finished, x, y))
            printf("1.0");
        else if(!belong(lastLayer.first, x, y))
            printf("0.0");
        else{

            if(lastLayer.second == finished * 4 + 1)
                printf("1.0");
            else if((y == 2 * finished) && (lastLayer.second != finished * 4 + 1))
                printf("0.0");
            else
            {
                double temp = calc(2 * finished, lastLayer.second, y + 1);
                printf("%lf",temp);
            }

        }
        printf("\n");
    }
    return 0;
}

