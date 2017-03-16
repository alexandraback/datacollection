#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int NumOfConsecutinveConsonants(string& name, int i, int j);
bool IsConsonant(char c);
int Solve(string& name, int n);


int main(void)
{
    int T;
    cin >> T;
    int i = 1;
    while (T--) {
        string name;
        int n;
        cin >> name >> n;
        cout << "Case #" << i++ << ": " << Solve(name, n) << endl;
    }
    return 0;
}

int Solve(string& name, int n)
{
    int N = 0;
    // Consider all substring from length n onward
    for (int l = n; l <= name.length(); ++l)
        for (int i = 0; i <= name.length()-l; ++i)
            if (NumOfConsecutinveConsonants(name, i, i+l-1) >= n)
                ++N;
    return N;
}

int NumOfConsecutinveConsonants(string& name, int i, int j)
{
    int cnt_max = 0, cnt = 0;
    for (int s = i; s <= j; ++s)
        if (IsConsonant(name[s]))
            ++cnt;
        else {
            if (cnt >= cnt_max)
                cnt_max = cnt;
            cnt = 0;
        }
    return max(cnt_max, cnt);
}

bool IsConsonant(char c)
{
    if ('a' == c || 'e' == c || 'i' == c || 'o' == c || 'u' == c)
        return false;
    return true;
}

