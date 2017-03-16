#include <cassert>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <iomanip>

std::unordered_map<char, double> getDistribution(const std::string& letters)
{
    std::unordered_map<char, int> counts;
    for (auto c: letters)
        ++counts[c];

    std::unordered_map<char, double> result;
    for (const auto& e: counts)
        result[e.first] = (static_cast<double>(e.second) / static_cast<double>(letters.size()));
    return result;
}

int count(const std::string& str, const std::string& pattern)
{
    int res = 0;
    for (unsigned i = 0; i < str.size(); ++i)
    {
        unsigned j = 0;
        while (i + j < str.size() && j < pattern.size() && str[i + j] == pattern[j])
            ++j;
        res += j == pattern.size();
    }
    return res;
}

void update(const std::string& generated, const std::string& pattern, const std::unordered_map<char, double>& dist, int& maxLen, double& exp)
{
    int cnt = count(generated, pattern);

    double p = 1.0;
    for (auto c: generated)
    {
        auto it = dist.find(c);
        assert(it != dist.end());
        p *= it->second;
    }

    maxLen = std::max(maxLen, cnt);
    exp += p * cnt;
}

std::vector<char> makeLetters(const std::string& letters)
{
    std::unordered_set<char> s;
    for (auto c: letters)
        s.insert(c);
    std::vector<char> res;
    for (auto c: s)
        res.push_back(c);
    return res;
}

void gen(std::string& generated, const std::string& pattern, const std::vector<char>& letters, std::unordered_map<char, double>& dist, int len, int& maxLen, double& exp)
{
    if (len == 0)
    {
        update(generated, pattern, dist, maxLen, exp);
        return;
    }

    for (auto c: letters)
    {
        generated.push_back(c);
        gen(generated, pattern, letters, dist, len - 1, maxLen, exp);
        generated.pop_back();
    }
}

double solve(const std::string& pattern, const std::string& letters, int len)
{
    auto dist = getDistribution(letters);
    auto lettersDistinct = makeLetters(letters);

    int maxLen = 0;
    double exp = 0;
    std::string generated;
    gen(generated, pattern, lettersDistinct, dist, len, maxLen, exp);

    return maxLen - exp;
}

int main()
{
    int T;
    std::cin >> T;
    for (int t = 1; t <= T; ++t)
    {
        int K, L, S;
        std::cin >> K >> L >> S;
        std::cin.get();

        std::string letters;
        std::cin >> letters;
        std::cin.get();
        std::string pattern;
        std::cin >> pattern;

        std::cout << "Case #" << t << ": " << std::fixed << std::setprecision(8) << solve(pattern, letters, S) << '\n';
    }

    return 0;
}
