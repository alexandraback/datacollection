//-----------------------------------------------------------------------------
// Template for G00gle C0de Jam :-)
//-----------------------------------------------------------------------------

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <iterator>
#include <string>
#include <cmath>


void solution(int test, std::ofstream& ofs) {
    ofs << "Case #" << test << ": ";
    /* Start coding here */

    int line = 0;
    int column = 0;
    int ship = 0;

    std::cin >> line;
    std::cin >> column;
    std::cin >> ship;

    int quotient = column / ship;
    int reste = column % ship;
    int tries = quotient * line;
    tries += ship;

    if (reste == 0) {
        --tries;
    }

    /* End */
    ofs << tries << std::endl;
}


int
main(int argc, char *argv[])
{
    std::string out(argv[0]);
    out.append(".out");
    std::ofstream ofs(out.c_str(), std::ofstream::out);

    int nb_tests_case = 0;
    std::cin >> nb_tests_case;

    for(int i = 1; i <= nb_tests_case; ++i) {
        solution(i, ofs);
    }

    ofs.close();

    return EXIT_SUCCESS;
}
