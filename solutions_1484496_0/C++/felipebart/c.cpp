#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 50;
const int MAXV = 100000;
const int MAXS = MAXN*MAXV;

int who[MAXS+1];

int calcsum(int msk, const vector<int>& numbers)
{
    int sum = 0;
    for(int i=0;i<numbers.size();++i)
    {
        sum += ((msk & (1 << i)) > 0) ? numbers[i] : 0; 
    }
    return sum;
}

void printset(int msk, const vector<int>& numbers)
{
    char prefix = '\n';
    for(int i=0;i<numbers.size();++i)
    {
        if((msk & (1 << i)) > 0)
        {
            printf("%c%d", prefix, numbers[i]);
            prefix = ' ';
        }
    }
}

int main()
{
    int t;
    scanf("%d", &t);
    for(int lp=1;lp<=t;++lp)
    {
        int n;
        scanf("%d", &n);
        vector<int> numbers(n);
        for(int& x : numbers)
        {
            scanf("%d", &x);
        }
        
        for(int i=1;i<=MAXS;++i)
        {
            who[i] = 0;
        }
        
        int seta = 0;
        int setb = 0;
        for(int i=1;i<(1<<n);++i)
        {
            int sum = calcsum(i, numbers);
            if(who[sum] > 0)
            {
                seta = who[sum];
                setb = i;
                break;
            }
            else
            {
                who[sum] = i;
            }
        }
        
        printf("Case #%d:", lp);
        if(seta > 0)
        {
            printset(seta, numbers);
            printset(setb, numbers);
            printf("\n");
        }
        else
        {
            printf("\nimpossible\n");
        }  
    }
    return 0;
}