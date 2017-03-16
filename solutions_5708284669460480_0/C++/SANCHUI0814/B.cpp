#include<cstdio>
#include<cstring>

#define MAX_LEN 7

class KeyBoard
{
public:
    int Input()
    {
        scanf("%d %d %d", &K, &L, &S);
        scanf("%s", keys);
        scanf("%s", target);
        return 0;
    }

    long double getBananers()
    {
        totalCnt = 0;
        totalBananers = 0;
        maxBananers = 0;
        DFS(0);
        return maxBananers - totalBananers*1.0/totalCnt;
    }

    int computeBananers()
    {
        int cnt = 0;
        for(int i=0; i<S-L+1; i++)
        {
            if(strncmp(target, combine+i, L) == 0)
                cnt++;
        }

        return cnt;
    }

    int DFS(int index)
    {
        if(index == S)
        {
            combine[index] = '\0';
            totalCnt++;
            int res = computeBananers();
            if(res > maxBananers)
                maxBananers = res;
            totalBananers += res;
    //        printf("%s %d\n", combine, computeBananers());
            return 0;
        }
        
        for(int i=0; i<K; i++)
        {
            combine[index] = keys[i];
            DFS(index+1);
        }
        return 0;
    }
private:
    char keys[MAX_LEN+1];
    char target[MAX_LEN+1];
    char combine[MAX_LEN+1];
    int K, L, S;
    int totalCnt;
    int totalBananers;
    int maxBananers;
};

int main(int argc, char* argv[])
{
    int T;
    scanf("%d", &T);

    for(int i=0; i<T; i++)
    {
        KeyBoard testObj;
        testObj.Input();
        printf("Case #%d: %.7Lf\n", i+1, testObj.getBananers());
    }
    return 0;
}

