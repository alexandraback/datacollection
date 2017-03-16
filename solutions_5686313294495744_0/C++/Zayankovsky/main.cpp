#include <iostream>
#include <string>
#include <utility>
#include <vector>

bool match(const std::vector<bool>& mask, const std::vector<std::pair<std::string, std::string>>& themes)
{
    for (unsigned i = 0; i < mask.size(); ++i)
    {
        if (mask[i])
        {
            const std::string& first_word = themes[i].first;
            const std::string& second_word = themes[i].second;
            bool found_first = false, found_second = false;
            for (unsigned j = 0; j < mask.size(); ++j)
            {
                if (!mask[j])
                {
                    if (!found_first && themes[j].first == first_word)
                    {
                        found_first = true;
                    }
                    if (!found_second && themes[j].second == second_word)
                    {
                        found_second = true;
                    }
                    if (found_first && found_second)
                    {
                        break;
                    }
                }
            }
            if (!found_first || !found_second)
            {
                return false;
            }
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

        unsigned N;
        std::cin >> N;

        std::vector<std::pair<std::string, std::string>> themes(N);
        for (auto&& theme : themes)
        {
            std::cin >> theme.first >> theme.second;
        }

        unsigned best_fakers = 0, fakers;
        std::vector<bool> mask(N);
        for (unsigned i = 0; i < 1u << N; ++i)
        {
            fakers = 0;
            for (unsigned j = 0; j < N; ++j)
            {
                mask[j] = (i & (1u << j)) != 0;
                if (mask[j])
                {
                    ++fakers;
                }
            }
            if (match(mask, themes) && fakers > best_fakers)
            {
                best_fakers = fakers;
            }
        }

        std::cout << best_fakers << std::endl;

    }
    return 0;
}

