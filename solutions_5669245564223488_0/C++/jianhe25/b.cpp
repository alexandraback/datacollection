#include <stdio.h>
#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

const long long MOD = 1000000007;
bool isSameCharacter(string word) {
    for (int i = 0; i < word.size(); ++i)
        if (word[i] != word[0])
            return false;
    return true;
}
int sameWord[256];
int numAsHead[256], numAsTail[256], numAsMiddle[256];
int headId[256], tailId[256];
int n;
long long ans1;
string str[200];

long long factor(int n) {
    long long ret = 1;
    for (int i = 1; i <= n; ++i) 
        ret = ret * i % MOD;
    return ret;
}
string shrink(string word) {
    string new_word;
    for (int i = 0; i < word.size(); ++i) {
        if (i == 0 || word[i] != word[i-1])
            new_word += word[i];
    }
    return new_word;
}

bool check(string word) { 
    vector<int> cover(256, 0);
    for (int j = 0; j < word.size(); ++j) {
        cover[ word[j] ]++;
    }
    for (int ch = 'a'; ch <= 'z'; ch++) {
        if (cover[ch] > 1) {
            return false;
        }
    }
    return true;
}

bool used[200];
int select[200];
int myCount[256];
int ans = 0;
void dfs(int depth, int last) {
    if (depth == n) {
        string final;
        for (int i = 0; i < n; ++i) {
            final += str[ select[i] ];
        }
        // +cout << "final = " << final << endl;
        final = shrink(final);
        if ( check(final) ) {
            ans1++;
        }
        return;
    }
    for (int i = 0; i < n; ++i) 
    if (!used[i]) {
        used[i] = true;
        select[depth] = i;

        string now = str[i];
        if (depth == 0 || str[last].back() == str[i][0] || myCount[ now[0] ] == 0) {
            for (int j = 0; j < now.size(); ++j) {
                myCount[now[j]]++;
            }
            dfs(depth + 1, i);
            for (int j = 0; j < now.size(); ++j) {
                myCount[now[j]]--;
            }
        }
        used[i] = false;
    }
}


int main() {
    string word;

    int test;
    cin >> test;
    for (int cas = 1; cas <= test; ++cas) {
        cin >> n;
        memset(numAsHead, 0, sizeof(numAsHead));
        memset(numAsTail, 0, sizeof(numAsTail));
        memset(numAsMiddle, 0, sizeof(numAsMiddle));

        memset(sameWord, 0, sizeof(sameWord));
        bool noAnswer = false;
        for (int i = 0; i < n; ++i) {
            cin >> word;                    
            str[i] = shrink(word);
            if (!isSameCharacter(word)) {                            
                word = shrink(word);                                

                for (int j = 0; j < word.size(); ++j) {
                    if (j == 0) {
                        numAsHead[ word[j] ]++;
                        headId[ word[j] ] = i;
                    } else if (j == word.size() - 1) {
                        numAsTail[ word[j] ]++;
                        tailId[ word[j] ] = i;
                    }
                    else {                        
                        numAsMiddle[ word[j] ]++;
                    }
                }
            } else {
                sameWord[ word[0] ]++;
            }
        }
        
        ans1 = 0;
        memset(used, 0, sizeof(used));
        memset(myCount, 0, sizeof(myCount));
        dfs(0, -1);

        int numHead = 0, numTail = 0;
        if (!noAnswer) {                
            for (int i = 'a'; i <= 'z'; ++i) {
                if (numAsHead[i] == 1 && numAsTail[i] == 1 && numAsMiddle[i] == 0 && headId[i] != tailId[i]) {
                    continue;
                }
                if (numAsHead[i] == 1 && numAsTail[i] == 0 && numAsMiddle[i] == 0) {
                    numHead++;
                    continue;
                }
                if (numAsHead[i] == 0 && numAsTail[i] == 1 && numAsMiddle[i] == 0) {
                    numTail++;
                    continue;
                }
                if (numAsHead[i] == 0 && numAsTail[i] == 0 && numAsMiddle[i] == 1) {                
                    continue;
                }
                if (numAsHead[i] == 0 && numAsTail[i] == 0 && numAsMiddle[i] == 0) {
                    continue;
                }
                noAnswer = true;
                break;
            }
        }


        printf("Case #%d: ", cas);
        cout << ans1 << endl;
        /*
        if (noAnswer) {
            puts("0");
        } else {
            for (int i = 'a'; i <= 'z'; ++i) {
                if (sameWord[i] > 0 && numAsHead[i] == 0 && numAsTail[i] == 0 && numAsMiddle[i] == 0) {
                    numHead++;
                    numTail++;
                }
            }            
            assert(numHead == numTail);
            long long ans = factor(numHead);
            for (int i = 'a'; i <= 'z'; ++i)
                ans = ans * factor(sameWord[i]) % MOD;
            cout <<  ans << " " << ans1 << endl;

            if (ans != ans1) { 
                cout << "!!!!!!!!!!!!!" << endl;
            }
        }
        */
    }

    
    
}










 