#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>

std::string concat(std::vector<std::string> const &lines, std::vector<int> const &perm)
{
    std::string ans;
    for (int i = 0; i < perm.size(); ++i)
        ans += lines[perm[i] - 1];
    return ans;
}

bool correct(std::string line)
{
    for (int i = 1; i < line.length(); ++i)
    {
        while (i < line.length() && line[i] == line[i - 1])
            ++i;
        if (line.find(line[i - 1], i) != std::string::npos)
            return false;
    }
    return true;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int test_num;
    std::cin >> test_num;
    for (int test = 1; test <= test_num; test++)
    {
        int n;
        std::cin >> n;
        std::vector<std::string> lines;
        for (int i = 0; i < n; i++)
        {
            std::string line;
            std::cin >> line;
            lines.push_back(line);
        }
        std::vector<int> perm;
        for (int i = 0; i < n; i++)
            perm.push_back(i + 1);
        int ans = 0;
        do
        {
            if (correct(concat(lines, perm)))
                ans++;
        } while (std::next_permutation(perm.begin(), perm.end()));
        std::cout << "Case #" << test << ": " << ans << std::endl;
    }
}
