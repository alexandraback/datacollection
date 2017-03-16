#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {

    string input;
    input +=  "ejp mysljylc kd kxveddknmc re jsicpdrysi";
    input +=  "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd";
    input +=  "de kr kd eoya kw aej tysr re ujdr lkgc jv";
    input +=  "y qee";

    string output;
    output += "our language is impossible to understand";
    output += "there are twenty six factorial possibilities";
    output += "so it is okay if you want to just give up";
    output += "a zoo";
 
    int OFF = 128;
    char m[256];
    memset(m, 0, sizeof(m));
    set<char> seenIn;
    set<char> seenOut;
    for(int i=0; i<input.size(); i++) {
        char ch = input[i];
        if (ch >= 'a' && ch<='z') { 
            m[OFF + ch] = output[i];
            seenIn.insert(ch);
            seenOut.insert(output[i]);
        }
    }
    char nIn, nOut;
    for(nIn = 'a'; nIn <='z'; nIn++) if (seenIn.count(nIn)==0) break;
    for(nOut = 'a'; nOut <='z'; nOut++) if (seenOut.count(nOut)==0) break;

    m[OFF+nIn] = nOut;

    int cases;
    cin >> cases;

    string line;
    getline(cin, line);

    for(int c=0; c<cases; c++) {
        getline(cin, line);
        for(int i=0; i<line.size(); i++) {
            if (line[i] >= 'a' && line[i] <= 'z') {
                line[i] = m[OFF + line[i]];
            }
        }
        cout << "Case #" <<(c+1) << ": " << line << endl;
    }
}
