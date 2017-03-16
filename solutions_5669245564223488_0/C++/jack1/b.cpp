#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <set>
#include <string>
#include <deque>

struct MetaString
{
    std::set<char> chars;
    std::string string;
    
    explicit MetaString(const std::string& string) : string(string)
    {
        for (char c : string)
        {
            chars.insert(c);
        }
    }
    
    bool hasCharsInCommonWith(const MetaString& other) const 
    {
        for (char c : chars)
        {
            if (other.chars.find(c) != other.chars.end()) return true;
        }
        return false;
    }
};

std::vector<std::vector<MetaString> > make_clusters(const std::vector<MetaString>& strings)
{
    std::vector<std::vector<MetaString> > result;
    for (const MetaString& s : strings)
    {
        bool done = false;
        for (std::vector<MetaString>& v : result)
        {
            for (const MetaString& other : v)
            {
                if (s.hasCharsInCommonWith(other))
                {
                    v.push_back(s);
                    done = true;
                    break;
                }
            }
            if (done)
                break;
        }
        if (!done)
        {
            std::vector<MetaString> v = { s };
            result.push_back(std::move(v));
        }
    }
    return result;
}

const uintmax_t MODULO = 1000000007;

uintmax_t evaluate_cluster(const std::vector<MetaString>& cluster)
{
    std::deque<std::string> sequence;
    for (const MetaString& s : cluster)
    {
        const std::string& str = s.string;
        if (sequence.empty()) // the first tring
        {
            sequence.push_back(str);
        }
        else
        {
            // try to append at the bottom
            if (sequence.back().back() == str.front())
                sequence.push_back(str);
            // try to append at the front
            else if (sequence.front().front() == str.back())
                sequence.push_front(str);
            else return 0;
        }
    }
    
    // verify adjacency condition
    std::set<char> chars;
    bool first = true;
    char prev;
    for (size_t i = 0; i < sequence.size(); i++)
    {
        for (char c : sequence[i])
        {
            if (!first)
            {
                if (chars.find(c) != chars.end() && c != prev)
                    return 0;
                first = false;
            }
            chars.insert(c);
            prev = c;
        }
    }
    
    // verify and count
    uintmax_t count = 1;
    uintmax_t local_count = 1;
    for (size_t i = 1; i < sequence.size(); i++)
    {
        if (sequence[i] == sequence[i - 1])
        {
            local_count *= 2;
        }
        else
        {
            count *= local_count;
            local_count = 1;
        }
    }
    count *= local_count;
    
    return count;
    
}

uintmax_t count_valid_trains(const std::vector<MetaString>& strings)
{
    std::vector<std::vector<MetaString> > clusters = make_clusters(strings);
    uintmax_t accum = 1;
    bool first = true;
    for (const std::vector<MetaString>& c : clusters)
    {
        uintmax_t e = evaluate_cluster(c);
        accum *= e;
        if (!first)
            accum *= 2;
        first = false;
        if (accum == 0) return 0;
    }
    return accum % MODULO;
}


int main()
{

    // Read the number of test cases
    int no_test_cases;
    std::cin >> no_test_cases;
    
    // Debug
    //std::cout << no_test_cases << std::endl;
    
    for (int i = 1; i <= no_test_cases; i++)
    {
        int no_strings;
        std::cin >> no_strings;
        
        std::vector<MetaString> strings;
        strings.reserve(no_strings);
        for (int j = 0; j < no_strings; j++)
        {
            std::string s;
            std::cin >> s;
            strings.emplace_back(s);
            //std::cout << s << " ";
        }
        //std::cout << std::endl;
        
        const uintmax_t result = count_valid_trains(strings);
        std::cout << "Case #" << i << ": " << result << std::endl;
        
    }
    
    return 0;
    
}
