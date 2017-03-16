#include <iostream>

void solve(int case_no)
{
    std::cout << "Case #" << case_no << ": ";

    int a;
    int b;
    int k;

    std::cin >> a;
    std::cin >> b;
    std::cin >> k;

    int result = 0;
    for (int aa = 0; aa < a; ++aa)
    {
        for (int bb = 0; bb < b; ++bb)
        {
            int c = aa & bb;
            //std::cout << "(" << aa << " | " << bb << ") = " << c << " ";
            if (c < k)
            {
                //std::cout << "!";
                ++result;
            }
            //std::cout << std::endl;

        }
    }
    
    std::cout << result << std::endl;
}
int main()
{
    int test_cases;
    std::cin >> test_cases;

    for (int i = 1; i <= test_cases; ++i)
        solve(i);
}
