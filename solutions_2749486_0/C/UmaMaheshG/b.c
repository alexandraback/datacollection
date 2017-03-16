#include<stdio.h>

#define MAX_NO_ELEMENTS 100000

void mydsort();
void myasort();
int mymax(int x, int y);
int mymin(int x, int y);


int T;
int i;
int k;
int j;
int A[MAX_NO_ELEMENTS];
int min;
int max;
int x;
int y;
int z;
int xsum;
int ysum;
int diff;

int main()
{
    scanf("%d", &T);
    
    for(i = 1; i <= T; i++)
    {
        scanf("%d", &x);
        scanf("%d", &y);
        printf("Case #%d: ", i);
        xsum = 0;
        ysum = 0;

        if(x < 0)
        {
            for(j = 1; j <=500; j++)
            {
                z = 0;
                printf("W");
                xsum += j;
                if(xsum >= (-1 * x))
                {
                    diff = xsum - (-1 * x);
                    while(diff > 0)
                    {
                        printf("WE");
                        diff--;
                        j += 2;
                    }
                    z = 1;
                    break;
                }
                if(z == 1)
                    break;
            }
        }
        else
        {
            for(j = 1; j <=500; j++)
            {
                z = 0;
                printf("E");
                xsum += j;
                if(xsum >= x)
                {
                    diff = xsum - x;
                    while(diff > 0)
                    {
                        printf("EW");
                        diff--;
                        j += 2;
                    }
                    z = 1;
                    break;
                }
                if(z == 1)
                    break;
            }
        }

        if(y < 0)
        {
            for(k = j+1; k <=500; k++)
            {
                z = 0;
                printf("S");
                ysum += k;
                if(ysum >= (-1 * y))
                {
                    diff = ysum - (-1 * y);
                    while(diff > 0)
                    {
                        printf("SN");
                        diff--;
                        k += 2;
                    }
                    z = 1;
                    break;
                }
                if(z == 1)
                    break;
            }
        }
        else
        {
            for(k = j + 1; k <=500; k++)
            {
                z = 0;
                printf("N");
                ysum += k;
                if(ysum >= y)
                {
                    diff = ysum - y;
                    while(diff > 0)
                    {
                        printf("NS");
                        diff--;
                        k += 2;
                    }
                    z = 1;
                    break;
                }
                if(z == 1)
                    break;
            }
        }
        printf("\n");
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
