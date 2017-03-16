#include<iostream>
#include <memory>
#include <utility>
#include <algorithm>
#include <memory.h>
using namespace std;
#define FOR(a, b, n) for(int (a) = (b); (a) < (n); ++(a))
#define ZERO(v) memset(v, 0, sizeof v)

string s;
int cnt[30];
int res[20];

string a[11] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
void remove(int index, int c)
{
    FOR(i,0,a[index].size())
    {
        cnt[a[index][i] - 'A'] -= c;
    }
}
void solve()
{
    ZERO(res);
    ZERO(cnt);
    FOR(i,0,s.size())
    {
        cnt[s[i] - 'A']++;
    }
    res[0] = cnt[25];
    remove(0, res[0]);
    res[8] = cnt['G' - 'A'];
    remove(8, res[8]);
    res[6] = cnt['X' - 'A'];
    remove(6, res[6]);
    res[7] = cnt['S' - 'A'];
    remove(7,res[7]);
    res[5] = cnt['V' - 'A'];
    remove(5,res[5]);
    res[2] = cnt['W' - 'A'];
    remove(2, res[2]);
    res[3] = cnt['T' - 'A'];
    remove(3, res[3]);
    res[4] = cnt['R' - 'A'];
    remove(4, res[4]);
    res[9] = cnt['I' - 'A'];
    remove(9,res[9]);
    res[1] = cnt['O' - 'A'];
    remove(1,res[1]);
    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < res[i]; j++)
            printf("%d", i);
    }
    cout << endl;
}
int main(){
    int T;
    cin >> T;
    FOR(h,0,T)
    {
        cin >> s;
        cout << "Case #" << h + 1 << ": ";
        solve();
    }
    return 0;
}