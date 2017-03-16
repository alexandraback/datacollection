#include <cstring>
#include <cmath>
#include <climits>
#include <vector>
#include <deque>
#include <set>
#include <map>
#include <string>
#include <iostream>
#include <algorithm>
#include <functional>
#include <utility>
using namespace std;
using ll = long long;
using ull = unsigned long long;

void solve()
{
    string S;
    cin >> S;

    sort(S.begin(), S.end());
    int count[100] = {0};
    for(char c : S)
        count[c] += 1;

    string phone;
    
    while(count['Z'] > 0)
    {
        phone += '0';
        for(char c : "ZERO")
            count[c] -= 1;
    }
    while(count['W'] > 0)
    {
        phone += '2';
        for(char c : "TWO")
            count[c] -= 1;
    }
    while(count['X'] > 0)
    {
        phone += '6';
        for(char c : "SIX")
            count[c] -= 1;
    }
    while(count['G'] > 0)
    {
        phone += '8';
        for(char c : "EIGHT")
            count[c] -= 1;
    }
    while(count['U'] > 0)
    {
        phone += '4';
        for(char c : "FOUR")
            count[c] -= 1;
    }
    while(count['O'] > 0)
    {
        phone += '1';
        for(char c : "ONE")
            count[c] -= 1;
    }
    while(count['F'] > 0)
    {
        phone += '5';
        for(char c : "FIVE")
            count[c] -= 1;
    }
    while(count['V'] > 0)
    {
        phone += '7';
        for(char c : "SEVEN")
            count[c] -= 1;
    }
    while(count['T'] > 0)
    {
        phone += '3';
        for(char c : "THREE")
            count[c] -= 1;
    }
    while(count['N'] > 0)
    {
        phone += '9';
        for(char c : "NINE")
            count[c] -= 1;
    }

    for(int i = 1; i < 100; i++)
    {
        if(count[i] < 0)
        {
            cerr << "oops " << i << " " << count[i] << "\n";
        }
    }

    sort(phone.begin(), phone.end());
    cout << phone;
    
}

int main()
{
    cout.precision(8);
    int T;
    cin >> T;
    for(int t = 1; t <= T; t++)
    {
        cout << "Case #" << t << ": ";
        solve();
        cout << endl;
    }
    return 0;
}

