#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <sstream>
#include <fstream>
#include <map>

#define INF 987654321

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, char> pic;

map<char, map<char, pic>> mul;



void init();
pic mult(pic a, pic b);
pic mult(pic a, char b);
pic div(pic  a, pic b);
pic div(pic a, char b);

int main() {
    ofstream fout ("contest.out");
    ifstream fin ("contest.in");

    init();

    int caseCount;
    fin >> caseCount;

    for(int caseNo = 1; caseNo <= caseCount; caseNo++) {
        int charCount, repCount;
        fin >> charCount >> repCount;
        string chars;
        fin >> chars;
        string str;
        str.clear();
        str.reserve(charCount * repCount);
        for(int i = 0; i < repCount; i++) {
            str = str.append(chars);
        }

        pic mulHead = pic(1, '1');
        pic mulTail = pic(1, '1');
        for(char c : str) {
            mulTail = mult(mulTail, c);
        }

        int firstCut = -1;
        for(int i = 0; i < str.length(); i++) {
            mulHead = mult(mulHead, str[i]);
            mulTail = div(mulTail, str[i]);
            if(mulHead.first == 1 && mulTail.first == 1 &&
               mulHead.second == 'i' && mulTail.second == 'i') {
                firstCut = i + 1;
                break;
            }
        }
        bool foundSecondCut = false;
        mulHead = pic(1, '1');
        mulTail = pic(1, '1');
        for(int i = firstCut; i < str.length(); i++) { mulTail = mult(mulTail, str[i]); }
        for(int i = firstCut; i < str.length(); i++) {
            mulHead = mult(mulHead, str[i]);
            mulTail = div(mulTail, str[i]);
            if(mulHead.first == 1 && mulTail.first == 1 &&
               mulHead.second == 'j' && mulTail.second == 'k') {
                foundSecondCut = true;
                break;
            }
        }

        if(firstCut == -1 || !foundSecondCut) {
            fout << "Case #" << caseNo << ": NO\n";
        }
        else {
            fout << "Case #" << caseNo << ": YES\n";
        }
    }

    return 0;
}

void init() {
    mul['1']['1'] = pic(1, '1');
    mul['1']['i'] = pic(1, 'i');
    mul['1']['j'] = pic(1, 'j');
    mul['1']['k'] = pic(1, 'k');

    mul['i']['1'] = pic(1, 'i');
    mul['i']['i'] = pic(-1, '1');
    mul['i']['j'] = pic(1, 'k');
    mul['i']['k'] = pic(-1, 'j');

    mul['j']['1'] = pic(1, 'j');
    mul['j']['i'] = pic(-1, 'k');
    mul['j']['j'] = pic(-1, '1');
    mul['j']['k'] = pic(1, 'i');

    mul['k']['1'] = pic(1, 'k');
    mul['k']['i'] = pic(1, 'j');
    mul['k']['j'] = pic(-1, 'i');
    mul['k']['k'] = pic(-1, '1');
}

pic mult(pic a, char b) {
    return mult(a, pic(1, b));
}

pic mult(pic a, pic b) {
    pic result = mul[a.second][b.second];
    result.first *= a.first * b.first;
    return result;
}

pic div(pic a, pic b) {
    for(auto c : mul[b.second]) {
        if(c.second.second == a.second) {
            return pic(c.second.first * a.first * b.first,
                       c.first);
        }
    }
    throw(10);
}

pic div(pic a, char b) {
    return div(a, pic(1, b));
}
