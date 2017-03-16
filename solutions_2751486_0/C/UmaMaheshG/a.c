#include<stdio.h>
#include<string.h>

#define MAX_NO_ELEMENTS 1000001

void mydsort();
void myasort();
int mymax(int x, int y);
int mymin(int x, int y);


int T;
int i;
int j;
int k;
int L;
int n;
long long int count;
int cFnd;
int start;
char A[MAX_NO_ELEMENTS];
int min;
int max;

int main()
{
    scanf("%d", &T);
    
    for(i = 1; i <= T; i++)
    {
        scanf("%s", A);
        scanf("%d", &n);

        L = strlen(A);
        start = 0;
        count = 0;

        for(j = 0; j <= L - n; j++)
        {
            cFnd = 0;
            for(k = j; k < j + n; k++)
            {
                if(A[k] == 'a' || 
                   A[k] == 'e' || 
                   A[k] == 'i' || 
                   A[k] == 'o' || 
                   A[k] == 'u')
                {
                    cFnd = 1;
                }
            }

            if(cFnd == 0)
            {
                count += ((j - start + 1) * (L - k +1));
                start = j + 1;
            }
        }

        printf("Case #%d: %Ld\n", i, count);
    }
    return 0;
}

void myasort()
{
    int x;
    int y;

    for(x = 0; x < MAX_NO_ELEMENTS; x++)
    {
        for(y = x + 1; y < MAX_NO_ELEMENTS; y++)
        {
            if(A[y] < A[x])
            {
                A[y] = A[y] + A[x]; 
                A[x] = A[y] - A[x];
                A[y] = A[y] - A[x];
            }
        }
    }
    return;
}

void mydsort()
{
    int x;
    int y;

    for(x = 0; x < MAX_NO_ELEMENTS; x++)
    {
        for(y = x + 1; y < MAX_NO_ELEMENTS; y++)
        {
            if(A[y] > A[x])
            {
                A[y] = A[y] + A[x]; 
                A[x] = A[y] - A[x];
                A[y] = A[y] - A[x];
            }
        }
    }
    return;
}


int mymax(int x, int y)
{
    if(x > y)
        return x;
    else
        return y;
}

int mymin(int x, int y)
{
    if(x < y)
        return x;
    else
        return y;
}
