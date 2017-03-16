#include <iostream>
#include <sstream>

int table[] = { 0, 1, 10, 100, 1000, 10000, 100000, 1000000 };

static int cycle(int i, int mult) {
    return i / 10 + (i % 10) * mult;
}

int main(void)
{
    int ncases;

    std::cin >> ncases;
    std::cin.ignore(1, '\n');
    for (int casenr = 1; casenr <= ncases; casenr++) {
        std::string Astr, Bstr;
        int A, B;
        std::cin >> Astr >> Bstr;
        std::stringstream(Astr) >> A;
        std::stringstream(Bstr) >> B;
        int digits = Astr.length();
        int mult = table[digits];
        int pairs = 0;
        
        for (int i = A; i < B; i++) {
            int s = i;
            while ((s = cycle(s, mult)) != i) {
                if (s > i && s <= B)
                    pairs++;
            }
        }
        std::cout << "Case #" << casenr << ": " << pairs << "\n";
        //std::cerr << "Case #" << casenr << ": " << pairs << "\n";
    }
}
