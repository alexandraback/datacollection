// -*- mode:c++; tab-width:4; c-basic-offset:4; indent-tabs-mode:nil -*-  
#include <iostream>
#include <string>

using namespace std;


int main()
{
    long T, n;
    int i, j, l, count, conSeq, lastGoodCons;
    bool isConsonant[26];
    bool haveConSeq;
    string s;

    
    for (i=0; i<26; i++)
        isConsonant[i] = true;
    isConsonant['a'-'a'] = false;
    isConsonant['e'-'a'] = false;
    isConsonant['i'-'a'] = false;
    isConsonant['o'-'a'] = false;
    isConsonant['u'-'a'] = false;

    cin >> T;
    for (i=0; i<T; i++) {
        cin >> s >> n;
        // Solve this case
        l = s.length();
        count = 0;
        conSeq = 0;
        haveConSeq = false;
        for (j=0; j<l; j++) {
            if (isConsonant[s[j]-'a']) {
                conSeq++;
                if (conSeq >= n) {
                    haveConSeq = true;
                    lastGoodCons = j;
                }
            }
            else {
                conSeq = 0;
            }
            if (haveConSeq) {
                count += lastGoodCons - n + 2;
            }
        }
        cout << "Case #" << i+1 << ": " << count << endl;
    }
    return 0;
}
