/*
 * =====================================================================================
 *
 * Nazwa pliku:  	A.cpp
 * Autor:		Szymon Stankiewicz (Daku)
 * Kontakt:		dakurels@gmail.com
 * Stworzony:		28.04.2012 02:58:38
 *
 * =====================================================================================
 */
#include<iostream>
#include<cstdio>
#include<cctype>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<string>
#include<list>
#include<deque>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<utility>
#include<sstream>
#include<cstring>
using namespace std;

double prawd[100007][2], pom, out;
long long A, B, K;

int main()
{
    scanf("%lld", &K);
    for (int iter=1; iter<=K; iter++)
    {
        scanf("%lld %lld", &A, &B);
        out=(double)B+2.0;
        prawd[0][1]=1;
        prawd[0][0]=0;
        for (int i = 1; i<=A; i++)
        {
            scanf("%lf", &pom);
            prawd[i][1]=pom*prawd[i-1][1];
            prawd[i][0]=1.0-prawd[i][1];
        }
        for(int i = 0; i<=A; i++)
        {
            pom=0.0;
            pom+=(double)(B-A+2*i+1)*prawd[A-i][1];
            pom+=(double)(B-A+2*i+B+2)*prawd[A-i][0];
            out=min(out, pom);
 //           printf("%d %.6lf\n", i, pom);
        }
        printf("Case #%d: %.6lf\n", iter, out);
    }
    return 0;
}
