#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <algorithm>

void Fashion(int J, int P, int S, int K);

int main()
{
    int T, J, P, S, K;
    std::cin >> T;

    for(int t = 0; t < T; t ++)
    {
        std::cin >> J >> P >> S >> K;
        std::cout << "Case #" << t + 1 << ": ";
        Fashion(J, P, S, K);
    }
    return 0;
}

void Fashion(int J, int P, int S, int K)
{
    int loop = S;
    if(K < S)
    {
        loop = K;
    }
    std::cout << J * P * loop << std::endl;

    int tmp = 1;

    for(int i = 0; i < J; i ++)
    {
        for(int j = 0; j < P; j ++)
        {
            for(int k = 0; k < loop; k ++)
            {
                if(tmp > S)
                {
                    tmp = 1;
                }
                std::cout << i + 1 << " " << j + 1 << " " << tmp ++ << std::endl;
            }
        }
    }
}
