#include <fstream>
#include <iostream>
#include <string>
#include <map>
#include <set>

using namespace std;

string s;
map<int, int> M;
set<string> ZERO, ONE, TWO;

int d[4200][8];

int main() {
    ifstream inp("garbled_email_dictionary.txt");
    while(inp >> s) {
        ZERO.insert(s);
        for(int i = 0; i < s.size(); ++i) {
            char c = s[i];
            s[i] = '?';
            ONE.insert(s);
            for(int j = i + 5; j < s.size(); ++j) {
                char cc = s[j];
                s[j] = '?';
                TWO.insert(s);
                s[j] = cc;
            }
            s[i] = c;
        }
    }
    //cout << G.size() << endl;
    int t;
    cin >> t;
    for(int T = 0; T < t; ++T) {
        
        int ans = 1000000000;

        cin >> s;

        for(int i = 0; i < 4100; ++i) {
            for(int j = 0; j <= 6; ++j) {
                d[i][j] = 1000000000;
            }
        }
        d[0][0] = 0;
        for(int i = 0; i < s.size(); ++i) {
            for(int j = 0; j <= 5; ++j) {
                if (d[i][j] == 1000000000) {
                    continue;
                }
                string word;
                for(int len = 0; len <= 10; ++len) {
                    if (i + len >= s.size()) {
                        break;
                    }
                    word += s[i + len];
                    if (i == 4 && j == 1) {
                        //cout << word << endl;
                    }
                    if (ZERO.find(word) != ZERO.end()) {
                        int mistk = j - (int)word.size();
                        mistk = max(mistk, 0);
                        d[i + word.size()][mistk] = min(d[i + word.size()][mistk], d[i][j]);
                        continue;
                    }
                    for(int A = j; A < word.size(); ++A) {
                        char c = word[A];
                        word[A] = '?';

                        if (i == 4 && j == 1) {
                            //cout << word << endl;
                        }
                        
                        if (ONE.find(word) != ONE.end()) {
                            // j == len - 1    => mistk = 4
                            int mistk = 4 - (len - A);
                            mistk = min(mistk, 5);
                            mistk = max(mistk, 0);
                            //cerr << s << " " << word << " " << mistk << endl;
                            //cerr << i + word.size() << " " << mistk << "  " << d[i][j] + 1 << endl;
                            d[i + word.size()][mistk] = min(d[i + word.size()][mistk], d[i][j] + 1);
                            word[A] = c;
                            //break;
                        }

                        for(int B = A + 5; B < word.size(); ++B) {
                            char cc = word[B];
                            word[B] = '?';

                            if (TWO.find(word) != TWO.end()) {
                                int mistk = 4 - (len - B);
                                mistk = max(mistk, 0);
                                mistk = min(mistk, 5);
                                d[i + word.size()][mistk] = min(d[i + word.size()][mistk], d[i][j] + 2);
                                word[B] = cc;
                                //break;
                            }

                            word[B] = cc;
                        }


                        word[A] = c;
                    }
                }
            }
        }

        for(int i = 0; i <= 5; ++i) {
            ans = min(ans, d[s.size()][i]);
        }


        cout << "Case #" << T + 1 << ": " << ans << endl;
    }
}
