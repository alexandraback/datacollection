#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <iomanip>
#include <sstream>
#include <cassert>

using namespace std;

void prologue()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    FILE *fp = freopen("/Users/-RooneY-/Desktop/src/input", "r", stdin);
    assert(fp);
    
    FILE *fpw = freopen("/Users/-RooneY-/Desktop/src/output", "w", stdout);
    assert(fpw);
}

int K, L, S;
string keyboard, target;
vector<pair<string, long long>> all;

string current;
map<char, int> freq;

void Generate(int index, int till_now)
{
    if (index == S)
    {
        all.push_back({current, till_now});
        return;
    }
    
    for (auto iter = freq.begin(); iter != freq.end(); ++iter)
    {
        current[index] = iter->first;
        Generate(index + 1, till_now * iter->second);
    }
}

int countSubstring(const std::string& str, const std::string& sub)
{
    if (sub.size() == 0 || str.size() == 0)
        return 0;
    
    int m = (int)(str.size() - sub.size());
    int total = 0;
    
    for (int i = 0; i <= m; ++i)
    {
        total += (str.substr(i, sub.size()) == sub);
    }
    
    return total;
}

int main()
{    
    prologue();
    
    int t;
    cin >> t;
    
    for (int test = 1; test <= t; ++test)
    {
        cin >> K >> L >> S;
        cin >> keyboard >> target;
        
        all.clear();
        current.resize(S);
        freq.clear();
        
        for (char c : keyboard)
        {
            freq[c]++;
        }
        
        // generate all strings with length S
        Generate(0, 1);
        
        long long denominator = 1;
        for (int i = 0; i < S; ++i)
            denominator = denominator * K;
        
        double expected_occurence = 0.0;
        int max_occurence = 0;

        for (auto iter = all.begin(); iter != all.end(); ++iter)
        {
            int occurence = countSubstring(iter->first, target);
            max_occurence = max(max_occurence, occurence);
            
            double prob = ((double)iter->second / denominator);
            expected_occurence += prob * occurence;
        }
        
        double ans = max_occurence - expected_occurence;
        
        cout.precision(9);
        cout << "Case #" << test << ": " << ans << endl;
    }
    
    return 0;
}