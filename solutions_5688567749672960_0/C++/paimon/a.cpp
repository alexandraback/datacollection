#include<deque>
#include<string>
#include<iostream>
#include<algorithm>

using namespace std;

const int Max = 10000000;

int res[Max];

int tr(int x)
{
    string s = to_string(x);
    reverse(s.begin(), s.end());
    return stoi(s);
}

void precalc()
{
    res[1] = 1;
    deque<int> D = {1};
    while(!D.empty()) {
        int x = D.front();
        D.pop_front();
        int y = x + 1, z = tr(x);
        if(y < Max && !res[y]) {
            res[y] = res[x] + 1;
            D.push_back(y);
        }
        if(z < Max && !res[z]) {
            res[z] = res[x] + 1;
            D.push_back(z);
        }
    }
}
    
int main()
{
    precalc();
    int t;
    cin >> t;
    for(int i = 1; i <= t; ++i) {
        int x;
        cin >> x;
        cout << "Case #" << i << ": " << res[x] << endl;
    }
}
