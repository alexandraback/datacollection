#include <iostream>
#include <algorithm>
#include <string>
#include <functional>
using namespace std;

void process(int tc)
{
    string s, answer;
    cin >> s;
    for (auto it = s.begin() ; it != s.end() ; ++it) {
        if (!answer.empty() && *it >= *answer.begin())
            answer.insert(answer.begin(), *it);
        else
            answer.push_back(*it);
    }
    cout << "Case #" << tc << ": " << answer << endl;
}
int main()
{
    int t = 0;
    cin >> t;
    for (int i = 1 ; i <= t ; ++i)
        process(i);
    return 0;
}
