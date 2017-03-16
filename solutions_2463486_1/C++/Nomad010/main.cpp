#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cinttypes>
#include <string>
#include <vector>

using std::vector;

typedef uint64_t uint64;

char buffer[100];
vector<uint64> pals;

bool IsPalindrome(uint64 pal)
{
    sprintf(buffer, "%lu", pal);
    const int len = strlen(buffer);
    for(int i = 0; i < len/2; ++i)
        if(buffer[i] != buffer[len - 1 - i])
            return false;
    return true;
}

int main(int argc, char** argv)
{
    for(uint64 i = 1; i <= 10000000ULL; ++i)
    {
        if(IsPalindrome(i) && IsPalindrome(i*i))
            pals.push_back(i*i);
    }
    
    int T;
    scanf("%d", &T);
    
    for(int t = 1; t <= T; ++t)
    {
        printf("Case #%d: ", t);
        
        uint64 A, B;
        scanf("%lu %lu", &A, &B);
        
        int answer = 0;
        for(int i = 0; i < int(pals.size()); ++i)
            if(pals[i] >= A && pals[i] <= B)
                ++answer;
            
        printf("%d\n", answer);
    }
}