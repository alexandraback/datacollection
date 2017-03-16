/*
ID: hoou8547
PROG: A
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
ifstream fin ("in.in");
ofstream fout ("out.out");
int t, p, i, j;
string s, ans;
vector<int> cnt(256);
vector<int> cnt2(10);
const string table[10] = {"ZERO", "TWO", "SIX", "EIGHT", "FOUR", "FIVE", "SEVEN", "THREE", "ONE", "NINE"};
const int lookup[10] = {0, 2, 6, 8, 4, 5, 7, 3, 1, 9};

void dec(string s, int a)
{
    for(int i = 0; i < s.length(); i++) cnt[s[i]]--;
    cnt2[a]++;
}

bool ok(string s, vector<int> cnt)
{
    for(int i = 0; i < s.length(); i++) if(cnt[s[i]]-- == 0) return false;
    return true;
}

int main()
{
    fin >>t;
    for(p = 1; p <= t; p++)
    {
        fin >>s;
        fill(cnt.begin(), cnt.end(), 0);
        fill(cnt2.begin(), cnt2.end(), 0);
        ans = "";
        for(i = 0; i < s.length(); i++) cnt[s[i]]++;
        for(i = 0; i < 10; i++)
            while(ok(table[i], cnt)) dec(table[i], lookup[i]);
        for(i = 0; i < 10; i++)
            for(j = 0; j < cnt2[i]; j++)
                ans += 48 + i;
        fout <<"Case #" <<p <<": " <<ans <<endl;
    }
    return 0;
}
