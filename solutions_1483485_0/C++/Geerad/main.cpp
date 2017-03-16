#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
#include <map>
#include <string>
#include <algorithm>
#include <cassert>

using namespace std;

int main()
{
    std::map<char, char> translationMap {
        {'y','a'},
        {'n','b'},
        {'f','c'},
        {'i','d'},
        {'c','e'},
        {'w','f'},
        {'l','g'},
        {'b','h'},
        {'k','i'},
        {'u','j'},
        {'o','k'},
        {'m','l'},
        {'x','m'},
        {'s','n'},
        {'e','o'},
        {'v','p'},
        {'z','q'},
        {'p','r'},
        {'d','s'},
        {'r','t'},
        {'j','u'},
        {'g','v'},
        {'t','w'},
        {'h','x'},
        {'a','y'},
        {'q','z'},
};

    int numCases;
    std::cin >> numCases;
    assert(std::cin);
    assert(numCases > 0 && numCases <= 30 );

    cin.ignore(1000, '\n');

    for( int i = 1; i <= numCases; ++i )
    {
        string line;
        getline(std::cin, line );

        for_each( line.begin(), line.end(), [&translationMap](char &c) { if(islower(c)) c = translationMap[c]; } );

        cout << "Case #" << i <<": " << line << endl;
    }


	return 0;
}
