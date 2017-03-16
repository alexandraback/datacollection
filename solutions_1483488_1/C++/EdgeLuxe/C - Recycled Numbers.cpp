#include <cstdio>
#include <set>

int numberLength(int a)
{
    int answer = 0;
    do {
        ++answer;
        a /= 10;
    } while(a != 0);
    return answer;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int t;
    scanf("%d", &t);

    for(int i = 0; i < t; ++i)
    {
        int a, b, answer = 0;
        scanf("%d%d", &a, &b);
        int len = numberLength(a);

        for(int n = a; n <= b; ++n)
        {
            std::set<int> ms;
            int modulo = 10;
            for(int k = 1; k < len; ++k, modulo *= 10)
            {
                int m = n;
                int dig = m % modulo;
                for(int q = 0; q < (len-k); ++q)
                    dig *= 10;

                m /= modulo;
                m += dig;

                if(n < m && m <= b)
                {
                    ms.insert(m);
                }
            }
            answer += ms.size();
        }

        printf("Case #%d: %d\n", i + 1, answer);
    }

    return 0;
}
