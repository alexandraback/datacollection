#include <iostream>
#include <map>
#include <vector>
using namespace std;

int n, nums[500];
multimap<int, vector<int>> sums;
multimap<int, vector<int>>::iterator it, ite;

void print(vector<int> v)
{
    int i, n = v.size();
    cout << v[0];
    for(i = 1; i < n; i++)
        cout << " " << v[i];
    cout << endl;
}

void dfs(int i, int sum, vector<int> num)
{
    if(i == n) {
        if(sum != 0)
            sums.insert(make_pair(sum, num));
        return;
    }
    dfs(i + 1, sum, num);
    num.push_back(nums[i]);
    dfs(i + 1, sum + nums[i], num);
}

void solve(int index)
{
    int i, j;
    cin >> n;
    for(i = 0; i < n; i++)
        cin >> nums[i];
    dfs(0, 0, vector<int>());
    for(it = sums.begin(); it != sums.end(); it++) {
        if(sums.count(it->first) != 1) {
            ite = sums.find(it->first);
            cout << "Case #" << index << ": " << endl;
            print(ite->second);
            ite++;
            print(ite->second);
            return;
        }
    }
    cout << "Case #" << index << ": Impossible" << endl;
}

int main(void)
{
    int I, N;
    cin >> N;
    for(I = 0; I < N; I++) {
        solve(I + 1);
        sums.clear();
    }
    return 0;
}
