#include <cstdio>
#include <cstdlib>
#include <cmath>

int arr1[10] = {0};
int arr2[10] = {0};
int main()
{
    int T,caseNum=1;
    freopen("C-small-attempt1.in","r",stdin);
	freopen("C-small-attempt1.out","w",stdout);
    scanf("%d", &T);
    /*arr1[0] = 2;
    arr2[0] = 2;
    arr1[1] = 5;
    arr2[1] = 4;
    arr1[2] = 8;
    arr2[2] = 6;
    arr1[3] = 11;
    arr2[3] = 8;
    arr1[4] = 14;
    arr2[4] = 10;
    arr1[5] = 17;
    arr2[5] = 12;*/
    for(int i=0; i<10; i++)
    {
        arr1[i] = 2 + 3*i;
        arr2[i] = 2 + 2*i;
        //printf("%d %d\n",arr1[i], arr2[i]);
    }
    while(caseNum<=T)
    {
        int N,M,K;
        scanf("%d %d %d", &N, &M, &K);
        int i=0;
        while(arr1[i]<K)
        {
            i++;
        }
        printf("Case #%d: %d\n", caseNum, arr2[i]);
        caseNum++;
    }
    return 0;
}

