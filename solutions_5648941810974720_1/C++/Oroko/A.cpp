#include <bits/stdc++.h>
using namespace std;

string cyfryANG[10] = { "ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE" };
char litery[10] = { 'Z', 'X', 'S', 'G', 'V', 'H', 'R', 'T', 'I', 'O' };
int cyfry[10] = { 0, 6, 7, 8, 5, 3, 4, 2, 9, 1};
int ilosc [10][26];
int iloscNOWA[10];
int ilosc2 [26];

/*void wypelnij() {
    for (int i = 0; i < 10; i ++)
        for(int j = 0; j < cyfryANG[i].size(); j++)
            ilosc[i][cyfryANG[i][j]-'A']++;
}*/

int main()
{
    //wypelnij();
    int t;
    cin >> t;
    int t2 = t;
    while( t--) {
        cout << "Case #"<< t2-t<<": ";
        string s;
        cin >> s;
        for (int i = 0; i < s.size(); i++) {
            ilosc2[s[i]-'A']++;
        }
        for(int i = 0; i < 26; i++) {
            while(ilosc2[litery[i]-'A']) {
                for(int j = 0; j < cyfryANG[cyfry[i]].size(); j++) {
                    ilosc2[cyfryANG[cyfry[i]][j]-'A'] --;
                }
                iloscNOWA[cyfry[i]]++;
            }
        }
        for(int i = 0; i < 10; i++) {
            while (iloscNOWA[i] > 0) {
                iloscNOWA[i]--;
                cout<<i;
            }
        }
        cout << endl;
    }
    return 0;
}
