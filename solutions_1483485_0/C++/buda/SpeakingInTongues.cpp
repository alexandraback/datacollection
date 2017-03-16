#include <iostream>
#include <iterator>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cctype>
#include <cstring>

using namespace std;

/* used this python code to generate the 'code' array
based on the given examples
   
orig = ["y qee",
"ejp mysljylc kd kxveddknmc re jsicpdrysi",
"rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd",
"de kr kd eoya kw aej tysr re ujdr lkgc jv"]

target = ["a zoo",
"our language is impossible to understand",
"there are twenty six factorial possibilities",
"so it is okay if you want to just give up"]

charmap = [-1]*26
unused = set(range(26))

def process_word(a, b):
    assert(len(a) == len(b))
    for i in range(len(a)):
        val = ord(a[i]) - ord('a')
        other = ord(b[i]) - ord('a')
        if charmap[val] == -1:
            charmap[val] = other
            unused.remove(other)
        else:
            assert(charmap[val] == other)

def process(a, b):
    p = a.find(' ')
    assert(b.find(' ') == p)
    if p == -1:
        process_word(a, b)
    else:
        process_word(a[:p], b[:p])
        process(a[p+1:], b[p+1:])

for i in range(len(orig)):
    process(orig[i], target[i])

if len(unused) > 0:
    assert(len(unused) == 1)
    for i in range(26):
        if charmap[i] == -1:
            charmap[i] = list(unused)[0]
            break

for i in range(26):
    print('{}, '.format(charmap[i]), end='')
*/
int code[] = {24, 7, 4, 18, 14, 2, 21, 23, 3, 20, 8, 6, 11, 1, 10, 17, 25, 19, 13, 22, 9, 15, 5, 12, 0, 16};

int main() {
    cin.sync_with_stdio(false);
    int T;
    string s;
    cin >> T;
    getline(cin, s); // \n
    
    for (int t=1; t<=T; ++t) {
        getline(cin, s);
        for (int i=0; i<(int)s.size(); ++i) {
            if (s[i] != ' ') {
                s[i] = char(code[s[i]-'a'] + 'a');
            }
        }
        cout << "Case #" << t << ": " << s << '\n';
    }
    
	return 0;
}
