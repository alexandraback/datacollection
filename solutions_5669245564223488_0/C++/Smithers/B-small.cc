#include <algorithm>
#include <iostream>
#include <string>

// Google Code Jam Round 1C 2014
// Problem B. Reordering Train Cars
// (Small) Solution in C++
// By Smithers

int main()
{
    int t;
    int n;
    std::string cars[10];
    bool seen[26];
    
    std::cin >> t;
    for (int ti = 1; ti <= t; ti++)
    {
        std::cin >> n;
        for (int i = 0; i < n; i++)
            std::cin >> cars[i];
        
        int result = 0;
        int indices[10];
        for (int i = 0; i < n; i++)
            indices[i] = i;
        do
        {
            char last = '\0';
            std::fill_n(seen, 26, false);
            for (int i = 0; i < n; i++)
            {
                for (const char *p = cars[indices[i]].c_str(); *p; p++)
                {
                    if (*p != last)
                    {
                        if (seen[*p - 'a'])
                            goto invalid;
                        seen[*p - 'a'] = true;
                        last = *p;
                    }
                }
            }
            result++;
invalid:
            ;
        } while (std::next_permutation(indices, indices+n));
        
        std::cout << "Case #" << ti << ": " << result << std::endl;
    }
    return 0;
}
