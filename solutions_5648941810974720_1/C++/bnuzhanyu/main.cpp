#include <iostream>
#include <algorithm>
#include <set>
#include <string>
#include <random>
#include <map>
#include <functional>
using namespace std;

void use_file(const std::string& s = "")
{
    if (s != "std" && s != "") {
        freopen((s+".in").c_str(), "r", stdin);
        freopen((s+".out").c_str(), "w", stdout);
    }
}



std::string NUMS[] = {
    "ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"
};
char cnt_char[] = {"ZOWRFVXSGI"};
int cnt_seq[] = {0, 6, 8, 7, 5, 4, 2, 3, 1, 9};


void calc(std::string& res, const std::string& s)
{
    vector<int> cnt(10, 0);
    std::map<char, int> mp;
    for (int i = 0; i < s.size(); i++){
        mp[s[i]]++;
    }
    for (int i = 0; i < 10; i++){
        int cur = cnt_seq[i];
        char c = cnt_char[cur];
        cnt[cur] = mp[c];
        for (int j = 0; j < NUMS[cur].size(); j++){
            char t = NUMS[cur][j];
            mp[t] -= cnt[cur];
        }
    }
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < cnt[i]; j++){
            res.push_back(i + '0');
        }
    }
}

int main() {
    use_file("A2");
    int T, N;
    cin >> T;

    std::string s;
    for(int ca = 1; ca <= T; ca++){
        cin >> s;
        string res;
        calc(res, s);
        cout << "Case #" << ca << ": " << res << std::endl;
    }
	return 0;
}
