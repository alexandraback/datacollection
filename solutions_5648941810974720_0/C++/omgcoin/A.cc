//Eldar Gaynetdinov
#include <bits/stdc++.h>
using namespace std;

vector<string> nums =
{
    "ZERO",     //Z     #               1
    "ONE",      //O     * after Z W R   9
    "TWO",      //W     #               2
    "THREE",    //H     * after G       5
    "FOUR",     //R     * after Z H     6
    "FIVE",     //F     * after R       7
    "SIX",      //X     #               3
    "SEVEN",    //S     * after X       8
    "EIGHT",    //G     #               4
    "NINE"      //I     * last          10
};

void f(vector<int>& ans, vector<int>& v, int K, int n)
{
    if(!K) return;

    for(int i = 0; i < K; i++)
        ans.push_back(n);

    for(auto c : nums[n])
        v[c] -= K;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T; cin >> T;

    for(int t = 1; t <= T; t++)
    {
        string S; cin >> S;

        vector<int> v(255);

        for(auto c : S) v[c]++;

        vector<int> ans;

        f(ans, v, v['Z'], 0);
        f(ans, v, v['W'], 2);
        f(ans, v, v['X'], 6);
        f(ans, v, v['G'], 8);
        f(ans, v, v['H'], 3);
        f(ans, v, v['R'], 4);
        f(ans, v, v['F'], 5);
        f(ans, v, v['S'], 7);
        f(ans, v, v['O'], 1);
        f(ans, v, v['I'], 9);

        sort(begin(ans), end(ans));

        for(auto k : v) assert(!k);

        cout << "Case #" << t << ": ";

        for(auto k : ans) cout << k;
        cout << endl;
    }

    return 0;
}
