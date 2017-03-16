#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <utility>
#include <list>
#include <set>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define forn(i, n) for(ll i = 0; i < n; i++)
#define forin(i, l, h) for(ll i = l; i < h; i++)

vector<int> dic, overlapLength;
string word;
int keyCount, wordLen, targetLen;
vector<vector<double>> dp;

double solve(int letterNo, int goodFor);
int calcMax();

int main() {
    ofstream fout ("test.out");
    ifstream fin ("test.in");

    int trialCount;
    fin >> trialCount;

    for(int trialNo = 1; trialNo <= trialCount; trialNo++) {
        fin >> keyCount >> wordLen >> targetLen;
        string keys;
        fin >> keys >> word;
        dic = vector<int>(26, 0);
        for(char c : keys)
            dic[c - 'A']++;
        dp = vector<vector<double>>(targetLen, vector<double>(wordLen, -1.0));
        overlapLength = vector<int>(wordLen, 0);
        forin(i, 1, wordLen) {
            overlapLength[i] = (word[i] == word[overlapLength[i - 1]])? overlapLength[i - 1] + 1 : 0;
        }

        fout << "Case #" << trialNo << ": " << calcMax() - solve(0, 0) << "\n";

    }
    return 0;
}

int calcMax() {
    int goodFor = 0, result = 0;
    forn(i, targetLen) {
        if(dic[word[goodFor] - 'A'] == 0) return 0;
        goodFor++;
        if(goodFor == wordLen) {
            result++;
            goodFor = overlapLength[goodFor - 1];
        }
    }
    return result;
}

double solve(int letterNo, int goodFor) {
    if(letterNo >= targetLen) return 0.0;
    if(goodFor > wordLen) throw(8);

    if(dp[letterNo][goodFor] == -1.0) {
        double satProb = dic[word[goodFor] - 'A'] / (double) keyCount;
        double overSatProb = dic[word[overlapLength[goodFor]] - 'A'] / double (keyCount);

        if(word[overlapLength[goodFor]] == word[goodFor]) overSatProb = 0.0;
        if(goodFor == wordLen - 1) {
            dp[letterNo][goodFor] = (1 + solve(letterNo + 1, overlapLength[goodFor])) * satProb +
                                    ((goodFor > 0)? solve(letterNo + 1, overlapLength[goodFor - 1] + 1) * overSatProb : 0) +
                                    solve(letterNo + 1, 0) * (1 - satProb - overSatProb);
        }
        else {
            dp[letterNo][goodFor] = solve(letterNo + 1, goodFor + 1) * satProb +
                                    ((goodFor > 0)? solve(letterNo + 1, overlapLength[goodFor - 1] + 1 ) * overSatProb : 0) +
                                    solve(letterNo + 1, 0) * (1 - satProb - overSatProb);
        }
    }
    return dp[letterNo][goodFor];
}
