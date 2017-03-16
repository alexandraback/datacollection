#include <iostream>
#include <string>

using namespace std;

int main(int argc, const char *argv[])
{
    int i, j, k;
    int n;
    cin >> n;
    string str;
    char map[26] = {
        'y', // a
        'h', // b
        'e', // c
        's', // d
        'o', // e
        'c', // f
        'v', // g
        'x', // h
        'd', // i
        'u', // j
        'i', // k
        'g', // l
        'l', // m
        'b', // n
        'k', // o
        'r', // p
        'z', // q
        't', // r
        'n', // s
        'w', // t
        'j', // u
        'p', // v
        'f', // w
        'm', // x
        'a', // y
        'q'  // z
    };
    getline(cin, str);
    for (i = 0; i < n; i++) {
        getline(cin, str);
        for (j = 0; j < str.size(); j++) {
            if (str[j] == ' ') continue;
            str[j] = map[str[j]-'a'];
        }
        cout << "Case #" << i + 1 << ": " << str + "\n";
    }
    return 0;
}
