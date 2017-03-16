#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
using namespace std;

#define YET 0
#define MAX 1
#define MIN 2

typedef long long int LLI;
typedef pair<string, string> SPair;

int T;
int n;
char S1[100001];
char S2[100001];

bool cmp(SPair a, SPair b) {
    LLI p = strtoll(a.first.c_str(), NULL, 10);
    LLI q = strtoll(a.second.c_str(), NULL, 10);
    LLI r = strtoll(b.first.c_str(), NULL, 10);
    LLI s = strtoll(b.second.c_str(), NULL, 10);
    if (llabs(p-q) != llabs(r-s)) return llabs(p-q) < llabs(r-s);
    if (a.first != b.first) return a.first < b.first;
    return a.second < b.second;
}

int main() {
    scanf("%d", &T);
    for (int Case=1; Case<=T; Case++) {
        vector<SPair> posans;

        scanf(" %s", S1);
        scanf(" %s", S2);
        n = strlen(S1);

        for (int i=0; i<n; i++) {
            if (S1[i] == '?' && S2[i] == '?') {
                S1[i] = '0';
                S2[i] = '1';
                string a(S1);
                string b(S2);
                replace(a.begin(), a.end(), '?', '9');
                replace(b.begin(), b.end(), '?', '0');
                posans.push_back(SPair(a, b));
                S1[i] = '1';
                S2[i] = '0';
                a = string(S1);
                b = string(S2);
                replace(a.begin(), a.end(), '?', '0');
                replace(b.begin(), b.end(), '?', '9');
                posans.push_back(SPair(a, b));
                S1[i] = '0';
            } else if (S1[i] == '?') {
                if (S2[i] != '0') {
                    S1[i] = S2[i]-1;
                    string a(S1);
                    string b(S2);
                    replace(a.begin(), a.end(), '?', '9');
                    replace(b.begin(), b.end(), '?', '0');
                    posans.push_back(SPair(a, b));
                }

                if (S2[i] != '9') {
                    S1[i] = S2[i]+1;
                    string a = string(S1);
                    string b = string(S2);
                    replace(a.begin(), a.end(), '?', '0');
                    replace(b.begin(), b.end(), '?', '9');
                    posans.push_back(SPair(a, b));
                
                }
                S1[i] = S2[i];
            } else if (S2[i] == '?') {
                if (S1[i] != '0') {
                    S2[i] = S1[i]-1;
                    string a(S1);
                    string b(S2);
                    replace(a.begin(), a.end(), '?', '0');
                    replace(b.begin(), b.end(), '?', '9');
                    posans.push_back(SPair(a, b));
                }

                if (S1[i] != '9') {
                    S2[i] = S1[i]+1;
                    string a = string(S1);
                    string b = string(S2);
                    replace(a.begin(), a.end(), '?', '9');
                    replace(b.begin(), b.end(), '?', '0');
                    posans.push_back(SPair(a, b));
                
                }
                S2[i] = S1[i];
            }

            string a(S1);
            string b(S2);
            replace(a.begin(), a.end(), '?', '9');
            replace(b.begin(), b.end(), '?', '0');
            posans.push_back(SPair(a, b));
            a = string(S1);
            b = string(S2);
            replace(a.begin(), a.end(), '?', '0');
            replace(b.begin(), b.end(), '?', '9');
            posans.push_back(SPair(a, b));
        }
        posans.push_back(SPair(S1, S2));
        sort(posans.begin(), posans.end(), cmp);
        printf("Case #%d: %s %s\n", Case, posans[0].first.c_str(), posans[0].second.c_str());
    }
}
