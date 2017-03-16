#include<cstdio>

#define MAX_NUM 1000001

int array[MAX_NUM];

int reverse(int num)
{
    int sum = 0;
    while(num)
    {
        sum = (sum*10) + (num%10);
        num = num/10;
    }

    return sum;
}

int compute()
{
    array[1] = 1;
    for(int i=2; i<MAX_NUM; i++)
    {
        if(array[i] == 0 || array[i-1]+1 < array[i])
            array[i] = array[i-1]+1;

        int rever_num = reverse(i);
        if(rever_num < MAX_NUM)
        {
            if(array[rever_num] == 0 || array[i] + 1 < array[rever_num])
                array[rever_num] = array[i] + 1;
        }

        //printf("i:%d value:%d\n", i, array[i]);
    }

    return 0;
}

int main(int argc, char* argv[])
{
    compute();
    int T;
    scanf("%d", &T);

    for(int i=0; i<T; i++)
    {
        int num;
        scanf("%d", &num);

        printf("Case #%d: %d\n", i+1, array[num]);
    }

    return 0;
}

