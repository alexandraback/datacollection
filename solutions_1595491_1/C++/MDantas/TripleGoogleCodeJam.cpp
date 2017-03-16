#include <stdio.h>
#include <algorithm>
#include <vector>
#define MAXN 110

using namespace std;

int bestSurp(int sum, int p)
{
    int maxi = -1;
    for(int i = 0; i <= 10; i++)
    {
        for(int j = i; j <= 10; j++)
        {
            if(i+2 < j)
                break;
            if((i+j)+(i+2) == sum && abs(max(i+2,j)-i) <= 2 && max(i+2,j) >= p)
                maxi = max(maxi,max(i+2,j));
            if((i+j)+(j+2) == sum && abs((j+2)-i) <= 2 && j+2 >= p)
                maxi = max(maxi,j+2);
        }
    }
    return maxi;
}

int bestNormal(int sum, int p)
{
    int maxi = -1;
    for(int i = 0; i <= 10; i++)
    {
        for(int j = i; j <= 10; j++)
        {
            if((j-i) >= 2)
                break;
            for(int k = j; k <= 10; k++)
            {
                if((k-j) >= 2 || (k-i) >= 2 || (j-i) >= 2)
                    break;
                if(k >= p && (i+j+k) == sum)
                    maxi = max(maxi,k);
            }
        }
    }
    return maxi;
}

struct Type
{
    int srp, normal;
    Type(){};
    Type(int a, int b)
    {
        srp = a, normal = b;
    }
    bool operator<(const Type &other)const
    {
        return normal < other.normal;
    }
};

vector < Type > K;

int main()
{
   /* freopen("B-large.in", "r", stdin);
    freopen("B-output.out", "w", stdout);*/
    int t, tz = 1;
    scanf("%d", &t);
    while( t-- )
    {
        K.clear();
        int n,s,p;
        scanf("%d %d %d", &n, &s, &p);
        int best = 0;
        for(int i = 0; i < n; i++)
        {
            int sum;
            scanf("%d", &sum);
            int auxn = bestNormal(sum,p);
            int auxsrp = bestSurp(sum,p);
           // printf("Sum: %d Auxn: %d Auxsrp: %d\n", sum, auxn, auxsrp);
            if(auxsrp != -1)
                K.push_back(Type(auxsrp, auxn));
            else
                best = best + ((auxn >= p) ? 1 : 0);
        }
        sort(K.begin(), K.end());
        int count = 0;
        int tm = K.size();
        for(int i = 0; i < tm; i++)
        {
            if(count >= s)
                best = best + ((K[i].normal >= p) ? 1 : 0);
            else
                best = best + ((K[i].srp >= p) ? 1 : 0), count++;
        }
        printf("Case #%d: %d\n", tz++, best);
    }
    return 0;
}
