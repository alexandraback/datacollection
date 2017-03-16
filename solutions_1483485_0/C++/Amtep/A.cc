#include <iostream>
#include <set>
#include <utility>

// table created by inspecting the example strings.
// z was not in the examples, but q was the only missing letter for it.
static char table[] = {
    'y', 'h', 'e', 's', 'o',  // a - e
    'c', 'v', 'x', 'd', 'u',  // f - j
    'i', 'g', 'l', 'b', 'k',  // k - o
    'r', 'z', 't', 'n', 'w',  // p - t
    'j', 'p', 'f', 'm', 'a', 'q'  // u - z
};

static void translate(std::string & str, int casenr)
{
    int len = str.length();
    for (int i = 0; i < len; i++) {
        char c = str[i];
        if (c >= 'a' && c <= 'z')
            str[i] = table[c - 'a'];
        else if (c == ' ')
            continue;
        else
            std::cerr << "Case #"  << casenr << ": bad char '" << c << "' at pos " << i << "\n";
    }
}

int main(void)
{
    int ncases;

    std::cin >> ncases;
    std::cin.ignore();
    for (int casenr = 1; casenr <= ncases; casenr++) {
      std::string str;
      getline(std::cin, str);
      translate(str, casenr);
      std::cout << "Case #" << casenr << ": " << str << "\n";
      //std::cerr << "Case #" << casenr << ": " << str << "\n";
    }
}
