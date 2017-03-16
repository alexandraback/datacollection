#include <bits/stdc++.h>

using namespace std;

const int me = 1025;


int t;
int cnt[me], has[me];
string s;
string nums[] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};

void go(int w){
    for(char i : nums[w])
        has[i] = 0;
    for(char i : nums[w])
        has[i] ++;
    for(char i : nums[w]){
        cnt[i] -= has[i];
        has[i] = 0;
    }
}
int main()
{
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    freopen("input.in", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> t;
    for(int cc = 0; cc < t; cc ++){
        for(int i = 'A'; i <= 'Z'; i ++)
            cnt[i] = 0;
        vector<int> ans;
        cin >> s;
        for(char i : s)
            cnt[i] ++;
        while(cnt['Z'] > 0) go(0), ans.push_back(0);
        while(cnt['W'] > 0) go(2), ans.push_back(2);
        while(cnt['G'] > 0) go(8), ans.push_back(8);
        while(cnt['H'] > 0) go(3), ans.push_back(3);
        while(cnt['U'] > 0) go(4), ans.push_back(4);
        while(cnt['X'] > 0) go(6), ans.push_back(6);
        while(cnt['F'] > 0) go(5), ans.push_back(5);
        while(cnt['V'] > 0) go(7), ans.push_back(7);
        while(cnt['O'] > 0) go(1), ans.push_back(1);
        while(cnt['I'] > 0) go(9), ans.push_back(9);
        cout << "Case #" << cc + 1 << ": ";
        sort(ans.begin(), ans.end());
        for(int i : ans)
            cout << i;
        cout << endl;
    }


    return 0;
}
