#include <iostream>

#define IS_V(c) (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')

inline
bool has_n(const char *str, unsigned int n)
{
    for (unsigned int i = 0; i < n; i++)
        if (str[i] == 0 || IS_V(str[i]))
            return false;
    return true;
}

inline
void jump_voy(const char* &str, size_t &length, unsigned int n)
{
    while (!has_n(str, n))
    {
        if (n > length)
        {
            str += length;
            length = 0;
            return;
        }
        str++;
        length--;
    }
}

int compute(const char *str, size_t length, unsigned int n)
{
    int prod_stack = 0;

    size_t first_length = length;
    jump_voy(str, length, n);

    if (!length)
        return 0;

    while (length)
    {
        //If we found some place
        if (length)//length > n so
        {
            prod_stack += (first_length - length + 1) * (length - n + 1);
        }
        str++;
        length--;
        
        first_length = length;
        jump_voy(str, length, n);
    }
    return prod_stack;
}

int main(void)
{
    int T;
    std::cin >> T;

    for (int i = 0; i < T; i++)
    {
        std::cout << "Case #" << (i + 1) << ": ";
        std::string str;
        std::cin >> str;
        size_t length = str.length();
        unsigned int n;
        std::cin >> n;
        std::cout << compute(str.c_str(), length, n) << "\n";
    }
}
