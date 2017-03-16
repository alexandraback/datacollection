// round1A.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <cstdio>
#include <vector>
#include <iomanip>

using namespace std;

// expected number of letters after some number of backspaces
double V(unsigned nBackSpace, double const *probs, unsigned nTyped, unsigned nLetters)
{
    if (nBackSpace >= nTyped)
    {
        return double(nBackSpace + nLetters + 1);
    }
    else if (nBackSpace > 0)
    {
        return V(0, probs, nTyped - nBackSpace, nLetters) + nBackSpace;   
    }
    // nBackSpace == 0
    else
    {
        // probability of no errors so far
        double q(1.0);
        for (unsigned i = 0; i < nTyped; ++i)
        {
            q *= probs[i];
        }

        // always have to type some letters, but if have error have to type it out again
        return (nLetters - nTyped + 1) + (1.0 - q) * (nLetters + 1);
    }
}

int main (int argc, char *argv[])
{
    unsigned nCases;
    std::cin >> nCases;
    for (unsigned iCase = 1; iCase <= nCases; ++iCase)
    {
        unsigned nTyped;
        unsigned nLetters;

        std::cin >> nTyped;
        std::cin >> nLetters;

        std::vector<double> probs(nTyped, 0.0);
        for (unsigned iProb = 0; iProb < nTyped; ++iProb)
        {
            std::cin >> probs[iProb];
        }
        // just press enter!
        double min_value(nLetters + 2);
        for (unsigned nBackSpace = 0; nBackSpace <= nTyped; ++nBackSpace)
        {
            double V1 = V(nBackSpace, &probs[0], nTyped, nLetters);
            //std::cerr << nBackSpace << " - " << V1 << std::endl;
            min_value = std::min(min_value, V1);
        }

        std::cout << "Case #" << iCase << ": " << fixed << setprecision(6) << min_value << std::endl;
    }
}






