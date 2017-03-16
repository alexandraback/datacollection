#include <cmath>
#include <iostream>
#include <limits>
#include <string>

bool match(int number, const std::string& pattern, std::string& number_str)
{
    std::string suffix = std::to_string(number);
    std::string prefix(pattern.length() - suffix.length(), '0');
    number_str = prefix + suffix;
    for (unsigned i = 0; i < number_str.length(); ++i)
    {
        if (number_str[i] != pattern[i] && pattern[i] != '?')
        {
            return false;
        }
    }
    return true;
}

int main()
{
    unsigned T;
    std::cin >> T;
    for (unsigned t = 1; t <= T; ++t)
    {
        std::cout << "Case #" << t << ": ";

        std::string C, J;
        std::cin >> C >> J;

        /*int mode = 0;
        for (unsigned i = 0; i < C.length(); ++i)
        {
            if (C[i] == J[i])
            {
                if (J[i] == '?')
                {
                    switch (mode)
                    {
                        case -1:
                            C[i] = '9';
                            J[i] = '0';
                            break;
                        case 0:
                            if (i + 1 < C.length() && C[i + 1] != '?' && J[i + 1] != '?')
                            {
                                if (C[i + 1] + 5 < J[i + 1])
                                {
                                    C[i] = '1';
                                    J[i] = '0';
                                    mode = 1;
                                }
                                else
                                {
                                    if (J[i + 1] + 5 < C[i + 1])
                                    {
                                        C[i] = '0';
                                        J[i] = '1';
                                        mode = -1;
                                    }
                                    else
                                    {
                                        C[i] = J[i] = '0';
                                    }
                                }
                            }
                            else
                            {
                                C[i] = J[i] = '0';
                            }
                            break;
                        case 1:
                            C[i] = '0';
                            J[i] = '9';
                            break;
                    }
                }
                else
                {
                    if (mode == 0)
                    {
                        if (C[i] < J[i])
                        {
                            mode = -1;
                        }
                        else
                        {
                            mode = 1;
                        }
                    }
                }
            }
            else
            {
                if (C[i] == '?')
                {
                    switch (mode)
                    {
                        case -1:
                            C[i] = '9';
                            break;
                        case 0:
                            if (i + 1 < C.length() && C[i + 1] != '?' && J[i + 1] != '?')
                            {
                                if (C[i + 1] + 5 < J[i + 1] && J[i] < '9')
                                {
                                    C[i] = J[i] + 1;
                                    mode = 1;
                                }
                                else
                                {
                                    if (J[i + 1] + 5 < C[i + 1] && J[i] > '0')
                                    {
                                        C[i] = J[i] - 1;
                                        mode = -1;
                                    }
                                    else
                                    {
                                        C[i] = J[i];
                                    }
                                }
                            }
                            else
                            {
                                C[i] = J[i];
                            }
                            break;
                        case 1:
                            C[i] = '0';
                            break;
                    }
                }
                else
                {
                    if (J[i] == '?')
                    {
                        switch (mode)
                        {
                            case -1:
                                J[i] = '0';
                                break;
                            case 0:
                                if (i + 1 < C.length() && C[i + 1] != '?' && J[i + 1] != '?')
                                {
                                    if (C[i + 1] + 5 < J[i + 1] && C[i] > '0')
                                    {
                                        J[i] = C[i] - 1;
                                        mode = 1;
                                    }
                                    else
                                    {
                                        if (J[i + 1] + 5 < C[i + 1] && C[i] < '9')
                                        {
                                            J[i] = C[i] + 1;
                                            mode = -1;
                                        }
                                        else
                                        {
                                            C[i] = J[i];
                                        }
                                    }
                                }
                                else
                                {
                                    J[i] = C[i];
                                }
                                break;
                            case 1:
                                J[i] = '9';
                                break;
                        }
                    }
                    else
                    {
                        if (mode == 0)
                        {
                            if (C[i] < J[i])
                            {
                                mode = -1;
                            }
                            else
                            {
                                mode = 1;
                            }
                        }
                    }
                }
            }
        }*/

        std::string max_str(C.length() + 1, '0');
        max_str[0] = '1';

        int max = std::stoi(max_str);
        int best_diff = std::numeric_limits<int>::max(), diff;
        std::string C_best, J_best, C_curr, J_curr;

        for (int C_int = 0; C_int < max; ++C_int)
        {
            for (int J_int = 0; J_int < max; ++J_int)
            {
                if (match(C_int, C, C_curr) && match(J_int, J, J_curr))
                {
                    if ((diff = std::abs(C_int - J_int)) < best_diff)
                    {
                        best_diff = diff;
                        C_best = C_curr;
                        J_best = J_curr;
                    }
                }
            }
        }

        std::cout << C_best << ' ' << J_best << std::endl;
    }
    return 0;
}

