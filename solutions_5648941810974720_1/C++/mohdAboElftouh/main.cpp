#include <bits/stdc++.h>
#define ll long long
#define ff first
#define ss second
#define mp make_pair
using namespace std;


string a[] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
int b[30];

int main(){

    freopen("A-large.in" , "r" , stdin);
    freopen("dream.out" , "w" , stdout);
    int t , z = 1;
    cin >> t;
    while(t--){
        printf("Case #%d: " , z++);
        memset(b  , 0 , sizeof b);
        string x;
        cin >> x;

        for(int i = 0; i < x.length(); ++i){
            ++b[x[i] - 'A'];
        }

        vector<int> ans;

        int zero = b['Z' - 'A'];
        for(int i = 0; i < zero; ++i){
            ans.push_back(0);
            b['Z' - 'A']--;
            b['E' - 'A']--;
            b['R' - 'A']--;
            b['O' - 'A']--;
        }

        int two = b['W' - 'A'];
        for(int i = 0; i < two; ++i){
            ans.push_back(2);
            b['T' - 'A']--;
            b['W' - 'A']--;
            b['O' - 'A']--;
        }


        int eight = b['G' - 'A'];
        for(int i = 0; i < eight; ++i){
            ans.push_back(8);
            b['E' - 'A']--;
            b['G' - 'A']--;
            b['H' - 'A']--;
            b['I' - 'A']--;
            b['T' - 'A']--;
        }


        int three = b['T' - 'A'];
        for(int i = 0; i < three; ++i){
            ans.push_back(3);
            b['T' - 'A']--;
            b['H' - 'A']--;
            b['R' - 'A']--;
            b['E' - 'A']--;
            b['E' - 'A']--;
        }

        int four = b['U' - 'A'];
        for(int i = 0; i < four; ++i){
            ans.push_back(4);
            b['F' - 'A']--;
            b['O' - 'A']--;
            b['U' - 'A']--;
            b['R' - 'A']--;
        }

        int one = b['O' - 'A'];
        for(int i = 0; i < one; ++i){
            ans.push_back(1);
            b['O' - 'A']--;
            b['N' - 'A']--;
            b['E' - 'A']--;
        }

        int five = b['F' - 'A'];
        for(int i = 0; i < five; ++i){
            ans.push_back(5);
            b['F' - 'A']--;
            b['I' - 'A']--;
            b['V' - 'A']--;
            b['E' - 'A']--;
        }

        int six = b['X' - 'A'];
        for(int i = 0; i < six; ++i){
            ans.push_back(6);
            b['S' - 'A']--;
            b['I' - 'A']--;
            b['X' - 'A']--;
        }

        int seven = b['S' - 'A'];
        for(int i = 0; i < seven; ++i){
            ans.push_back(7);
            b['S' - 'A']--;
            b['E' - 'A']--;
            b['V' - 'A']--;
            b['E' - 'A']--;
            b['N' - 'A']--;
        }

        int nine = b['I' - 'A'];
        for(int i = 0; i < nine; ++i){
            ans.push_back(9);
            b['N' - 'A']--;
            b['I' - 'A']--;
            b['N' - 'A']--;
            b['E' - 'A']--;
        }


        sort(ans.begin(), ans.end());
        for(int i = 0; i < ans.size(); ++i)cout << ans[i];
        cout << "\n";

    }
    return 0;
}
