#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <algorithm>
#include <bitset> 
#include <math.h>

void Slides(int B, long long M);

int main()
{
    int T, B;
    long long M;
    std::cin >> T;

    for(int t = 0; t < T; t ++)
    {
        std::cin >> B >> M;
        std::cout << "Case #" << t + 1 << ": ";
        Slides(B, M);
    }
    return 0;
}

void Slides(int B, long long M)
{
    if(M > std::exp2(B-2))
    {
        std::cout << "IMPOSSIBLE" << std::endl;
        return;
    }else
    {
        std::cout << "POSSIBLE" << std::endl;
    }

    std::bitset<8> loss(std::exp2(B-2) - M);
    //std::cout << loss << std::endl;
    loss.flip();
    std::string result = 
        loss.to_string<char,std::string::traits_type,std::string::allocator_type>();
    std::cout << 0 << result.substr(10-B) << 1 << std::endl;
    for(int i = 1; i < B; i ++)
    {
        for(int j = 0; j < B; j ++)
        {
            if(j > i)
            {
                std::cout << 1;
            }else
            {
                std::cout << 0;
            }
        }
        std::cout << std::endl;
    }
}
