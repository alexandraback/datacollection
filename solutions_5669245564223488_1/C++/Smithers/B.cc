#include <algorithm>
#include <iostream>
#include <string>

// Google Code Jam Round 1C 2014
// Problem B. Reordering Train Cars
// Solution in C++
// By Smithers

#define MODULUS 1000000007

long long fact(int i)
{
    long long result = 1;
    while (i)
    {
        result *= i--;
        result %= MODULUS;
    }
    return result;
}

int main()
{
    int t;
    int n;
    std::string car;
    int full_count[26], start_count[26], end_count[26], mid_count[26];
    int start_end[26], end_start[26];
    
    std::cin >> t;
    for (int ti = 1; ti <= t; ti++)
    {
        std::cin >> n;
        std::fill_n(full_count, 26, 0);
        std::fill_n(start_count, 26, 0);
        std::fill_n(end_count, 26, 0);
        std::fill_n(mid_count, 26, 0);
        for (int i = 0; i < n; i++)
        {
            std::cin >> car;
            char c = car[0];
            int j;
            for (j = 1; j < car.length(); j++)
            {
                if (car[j] != c)
                    break;
            }
            if (j == car.length())
            {
                full_count[c - 'a']++;
                continue;
            }
            start_count[c - 'a']++;
            start_end[c - 'a'] = car[car.length()-1] - 'a';
            end_start[car[car.length()-1] - 'a'] = c - 'a';
            c = car[j];
            for (j++; j < car.length(); j++)
            {
                if (car[j] != c)
                {
                    mid_count[c - 'a']++;
                    c = car[j];
                }
            }
            end_count[c - 'a']++;
        }
        
        int result = 1;
        for (int i = 0; i < 26; i++)
        {
            if (mid_count[i] > 1 || start_count[i] > 1 || end_count[i] > 1)
            {
                result = 0;
                break;
            }
            else if (mid_count[i] == 1 && (full_count[i] > 0 || start_count[i] > 0 || end_count[i] > 0))
            {
                result = 0;
                break;
            }
            else if (full_count[i] > 0)
            {
                result = (int)(result * fact(full_count[i]) % MODULUS);
            }
        }
        
        if (result > 0)
        {
            for (int i = 0; i < 26; i++)
            {
                if (start_count[i] == 1 || end_count[i] == 1)
                {
                    full_count[i] = 0;
                }
                if (start_count[i] == 1 && end_count[i] == 1)
                {
                    if (start_end[i] == i)
                    {
                        result = 0;
                        break;
                    }
                    start_count[i] = 0;
                    end_count[i] = 0;
                    start_end[end_start[i]] = start_end[i];
                    end_start[start_end[i]] = end_start[i];
                    i = -1;
                }
            }
        }
        
        if (result > 0)
        {
            int j = 0;
            for (int i = 0; i < 26; i++)
            {
                if (start_count[i] > 0 || full_count[i] > 0)
                    j++;
            }
            result = (int)(result * fact(j) % MODULUS);
        }
        
        std::cout << "Case #" << ti << ": " << result << std::endl;
    }
    return 0;
}
