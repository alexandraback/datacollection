#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;

char a[20], b[20];
int best;
int bestA, bestB;

void rec()
{
    for(int w=0;w<2;w++)
    {
        char* s = w ? b : a;
        for(int i=0;s[i];i++)
            if(s[i] == '?')
            {
                for(int k=0;k<10;k++)
                {
                    s[i] = '0'+k;
                    rec();
                }
                s[i] = '?';
                return;
            }
    }
    int A = atoi(a), B = atoi(b);
    if (abs(A-B)<best)
    {
        best=abs(A-B);
        bestA = A;
        bestB = B;
    }
}

int main()
{
    int TT;
    scanf("%d", &TT);
    for(int TI = 1; TI <= TT; TI++)
    {
        scanf(" %s %s", a, b);
        int L = strlen(a);
        best = 9999999;
        rec();
        
        printf("Case #%d: %0*d %0*d\n", TI, L, bestA, L, bestB);
    }
}
