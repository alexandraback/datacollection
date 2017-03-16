#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define scd second
#define f(x, let) for(int let=0; let<x; let++)
#define ms(x, v) memset(x, v, sizeof x)
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pair<int, int> > vpi;
typedef set<int> si;
typedef set<int>::iterator sit;
const int MOD = 1000000007;
const int OO = 1000000000;
int digs[1000];
int num[15];

int main(){
    std::ios::sync_with_stdio(false);
    int t;
    cin >> t;
    f (t, k) {
        string s;
        cin >> s;
        ms (digs, 0);
        ms (num, 0);
        f (s.size (), i) {
            digs[s[i]]++;
        }
        int aux = digs['Z'];
        for (int i = 0; i < aux; i++) {
            num[0]++;
            digs['Z']--;
            digs['E']--;
            digs['R']--;
            digs['O']--;
        }
        aux = digs['W'];
        for (int i = 0; i < aux; i++) {
            num[2]++;
            digs['T']--;
            digs['W']--;
            digs['O']--;
        }
        aux = digs['U'];
        for (int i = 0; i < aux; i++) {
            num[4]++;
            digs['F']--;
            digs['O']--;
            digs['U']--;
            digs['R']--;
        }
        aux = digs['G'];
        for (int i = 0; i < aux; i++) {
            num[8]++;
            digs['E']--;
            digs['I']--;
            digs['G']--;
            digs['H']--;
            digs['T']--;
        }
        aux = digs['X'];
        for (int i = 0; i < aux; i++) {
            num[6]++;
            digs['S']--;
            digs['I']--;
            digs['X']--;
        }
        aux = digs['H'];
        for (int i = 0; i < aux; i++) {
            num[3]++;
            digs['T']--;
            digs['H']--;
            digs['R']--;
            digs['E']--;
            digs['E']--;
        }
        aux = digs['O'];
        for (int i = 0; i < aux; i++) {
            num[1]++;
            digs['O']--;
            digs['N']--;
            digs['E']--;
        }
        aux = digs['F'];
        for (int i = 0; i < aux; i++) {
            num[5]++;
            digs['F']--;
            digs['I']--;
            digs['V']--;
            digs['E']--;
        }
        aux = digs['V'];
        for (int i = 0; i < aux; i++) {
            num[7]++;
            digs['S']--;
            digs['E']--;
            digs['V']--;
            digs['E']--;
            digs['N']--;
        }
        aux = digs['I'];
        for (int i = 0; i < aux; i++) {
            num[9]++;
            digs['N']--;
            digs['I']--;
            digs['N']--;
            digs['E']--;
        }
        cout << "Case #" << k+1 << ": ";
        for (int i = 0; i <= 9; i++) {
            while (num[i] > 0) {
                cout << i;
                num[i]--;
            }
        }
        cout << endl;
    }
}
