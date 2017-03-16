#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Claim: as long n > 0, i.e. kn that contains a number x
// for all numbers x from 0 to 9 inclusive.

vector<string> m = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE", "TEN"};
void add(vector<int>& V, int i) {
    for (char c : m[i]) {
        --V[c];
    }
}

string solve(string input) {
    vector<int> V(128, 0);
   for (char c : input) {
        ++V[c];
   }

   string result;

   while (V['Z']) {
        result.push_back('0');
        for (char c : m[0]) {
            --V[c];
        }
   }
   while (V['W']) {
        result.push_back('2');
        for (char c : m[2]) {
            --V[c];
        }
   }

   while (V['U']) {
        result.push_back('4');
        add(V, 4);
   }


   while (V['X']) {
    result.push_back('6');
    add(V, 6);
   }

   while (V['G']) {
    result.push_back('8');
    add(V, 8);
   }

   // ONE THREE FIVE SEVEN NINE

   while (V['O']) {
    result.push_back('1');
    add(V,1);
   }

   // THREE FIVE SEVEN NINE
   while (V['R']) {
    result.push_back('3');
    add(V,3);
   }

   while (V['F']) {
    result.push_back('5');
    add(V,5);
    }

   // SEVEN NINE
   while (V['V']) {
    result.push_back('7');
    add(V, 7);
   }

   while (V['N']) {
    result.push_back('9');
    add(V,9);
   }

   sort(result.begin(), result.end());
   return result;
}

int main() {
    int T;
    string n;
    cin >> T;
    for (int i = 1; i <= T; ++i) {
        cin >> n;
        cout << "Case #" << i << ": " << solve(n) << endl;
    }
    return 0;
}
