#include <iostream>

int main(void)
{
    int ncases;

    std::cin >> ncases;
    std::cin.ignore(1, '\n');
    for (int casenr = 1; casenr <= ncases; casenr++) {
        int ngooglers, surprises, p, winners;
        std::cin >> ngooglers;
        std::cin >> surprises;
        std::cin >> p;
        winners = 0;
        for (int i = 0; i < ngooglers; i++) {
            int t;
            std::cin >> t;
            int minscore = (p >= 1) ? (p - 1) : 0;
            int minsurprise = (p >= 2) ? (p - 2) : 0;
            if (t >= p + minscore * 2) {
                winners++;
            } else if (surprises > 0 && t >= p + minsurprise * 2) {
                winners++;
                surprises--;
            }
        }
        std::cout << "Case #" << casenr << ": " << winners << "\n";
        //std::cerr << "Case #" << casenr << ": " << winners << "\n";
    }
}
