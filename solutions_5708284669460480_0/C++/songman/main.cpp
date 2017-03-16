#include <iostream>
#include <iomanip>
#include <vector>
#include <limits>
#include <algorithm>
#include <cctype>
#include <cmath>
#include <queue>
#include <set>
#include <bitset>
#include <map>

#define UREP(i,n) for(unsigned int i=0;i<n;i++)
#define REP(i,n) for(int i=0;i<n;i++)
#define FRVR for(;;)

typedef unsigned long long int ULINT;
typedef long long int LINT;

const double EPS = 1e-6;

using namespace std;


double probs[26];

int k,l,s;
string keys, target;
set<char> poss_keys;

string perm_string;
double perm_prob;

double total_prob;
int max_occ;

void permsolve(int len) {
    if(len == 0) {

        int occ = 0;
        size_t pos = perm_string.find(target, 0);
        while(pos != string::npos)
        {
            occ++;
            pos = perm_string.find(target,pos+1);
        }
        if(occ>max_occ) max_occ=occ;

        double perm_prob = 1;

        for(char c : perm_string) perm_prob *= probs[c-'A'];

        total_prob += occ * perm_prob;
        return;
    }
    for(char c : poss_keys) {
        perm_string.push_back(c);

        permsolve(len-1);
        perm_string.pop_back();
    }
}


void process(int caseNum) {

    cin >> k >> l >> s;
    cin >> keys;
    cin >> target;

    REP(i, 26) probs[i] = 0;

    poss_keys.clear();
    for(char c : keys) {
        probs[c-'A'] += 1;
        poss_keys.insert(c);
    }

    REP(i, 26) probs[i] /= k;

    perm_string = "";
    perm_prob = 1;
    total_prob = 0;
    max_occ = 0;

    permsolve(s);

    cout << "Case #" << caseNum << ": " << fixed << max_occ - total_prob << endl;
 }

int main() {
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;
    REP(i, t) {
        process(i+1);
    }

    return 0;
}
