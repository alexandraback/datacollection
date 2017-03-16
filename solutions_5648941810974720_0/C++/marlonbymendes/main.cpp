#include <bits/stdc++.h> 
#define debug(x) cout << "> " << #x << " = " << x << endl;
#define debugat(arr, at) cout << "> " << #arr << "[" << at << "] = " << arr[at] << endl;

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;

map<char, int> cont;

void printCont() {
    for(char c = 'A'; c <= 'Z'; ++c) {
        if(cont[c])
            debugat(cont, c);
    }
    cout << endl;
}


int ammount;
void removeC(string s) {
    for(int i = 0; i < ammount; ++i) {
        for(char c : s) {
            cont[c] = cont[c] - 1;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);

    int tests;
    cin >> tests;

    for(int t = 1; t <= tests; ++t) {
        string s;
        cin >> s;

        cont.clear();
        for(char c : s) {
            cont[c] = cont[c] + 1;
        }

        vector<ii> next;
        vi ans;

        next.push_back(ii(0, cont['Z']));
        ammount = cont['Z'];
        removeC("ZERO");

        next.push_back(ii(2, cont['W']));
        ammount = cont['W'];
        removeC("TWO");

        next.push_back(ii(6, cont['X']));
        ammount = cont['X'];
        removeC("SIX");

        next.push_back(ii(8, cont['G']));
        ammount = cont['G'];
        removeC("EIGHT");

        next.push_back(ii(3, cont['T']));
        ammount = cont['T'];
        removeC("THREE");

        next.push_back(ii(4, cont['R']));
        ammount = cont['R'];
        removeC("FOUR");

        next.push_back(ii(1, cont['O']));
        ammount = cont['O'];
        removeC("ONE");

        next.push_back(ii(5, cont['F']));
        ammount = cont['F'];
        removeC("FIVE");

        next.push_back(ii(7, cont['S']));
        ammount = cont['S'];
        removeC("SEVEN");

        next.push_back(ii(9, cont['E']));
        ammount = cont['E'];
        removeC("NINE");

        for(ii p : next) {
            for(int i = 1; i <= p.second; ++i) {
                ans.push_back(p.first);
            }
        }

        sort(ans.begin(), ans.end());
        cout << "Case #" << t << ": ";
        for(int k : ans)
            cout << k;
        cout << "\n";
    }
    return 0;
}
