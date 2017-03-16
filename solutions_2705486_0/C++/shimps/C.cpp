#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> dic;
int c;
void build_dic() {
    ifstream in("garbled_email_dictionary.txt");
    string word;
    while(in >> word) dic.push_back(word);
    c = dic.size();
    in.close();
}

int dp[4010][5];
int do_case() {
    string S;
    cin >> S;
    int n = S.size();
    memset(dp,0x7f,sizeof(dp));
#define INF 0x7f7f7f7f
    dp[0][4] = 0;
    for(int i=0;i<n;i++) {
        for(int j=0;j<5;j++) if(dp[i][j] != INF) {
            for(int p=0;p<c;p++) {
                bool f = true;
                int nu = j;
                int le = dic[p].size();
                int ch = 0;
                for(int q=0;q<le;q++) {
                    if(dic[p][q] == S[i+q]) {
                        nu++;
                        continue;
                    }
                    if(nu >= 4) {
                        ch++;
                        nu = 0;
                        continue;
                    }
                    f = false;
                    break;
                }
                nu = min(nu,4);
                if(f) dp[i+le][nu] = min(dp[i+le][nu],dp[i][j]+ch);
            }
        }
    }
    int res = INF;
    for(int i=0;i<5;i++) res = min(res,dp[n][i]);
    return res;
}

int main() {
    build_dic();
    int T;
    cin >> T;
    for(int it=1;it<=T;it++) cout << "Case #" << it << ": " << do_case() << endl;
    return 0;
}
