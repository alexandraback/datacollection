/* 2015
 * Maciej Szeptuch
 * II UWr
 */
#include <cstdio>
#include <queue>

inline
long long int reverse(long long int number)
{
    long long int result = 0;
    while(number)
    {
        result *= 10;
        result += number % 10;
        number /= 10;
    }

    return result;
}

long long int remember[9999999];

inline
long long int main_case(void)
{
    long long int finish = 0;
    scanf("%lld", &finish);
    return remember[finish];
}

inline
void preprocess(void)
{
    std::priority_queue<std::pair<long long int, long long int>> que;
    que.push(std::make_pair(-1, 1));
    remember[1] = 1;
    while(!que.empty())
    {
        auto act = que.top();
        que.pop();

        if(act.second + 1 >= 10000000 || remember[act.second] > -act.first)
            continue;

        if(!remember[act.second + 1] || remember[act.second + 1] > -act.first + 1)
        {
            remember[act.second + 1] = -act.first + 1;
            que.push(std::make_pair(-remember[act.second + 1], act.second + 1));
        }

        long long int rev = reverse(act.second);
        if(!remember[rev] || remember[rev] > -act.first + 1)
        {
            remember[rev] = -act.first + 1;
            que.push(std::make_pair(-remember[rev], rev));
        }
    }
    fprintf(stderr, "DONE\n");
}

int main(void)
{
    preprocess();
    int tests = 0;
    scanf("%d", &tests);
    for(int t = 0; t < tests; ++ t)
        printf("Case #%d: %lld\n", t + 1, main_case());

    return 0;
}
