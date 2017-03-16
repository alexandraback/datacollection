#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <vector>
#include <map>
#include <ctime>

std::map<char, char> buildMapping();
std::string translateLine(std::string line, std::map<char, char> mapping);

struct TestCase
{
    std::string line;
};

int main(int argc, char* argv[])
{
    //clock_t begin = clock();
    std::map<char, char> mapping;
    
    // read in data
    std::ifstream finput(argv[1]);

    std::string line = ""; // treating this as more of a delimited item, less a line

    int numCases = 0;

    std::vector<TestCase> testCases;

    if (finput.is_open())
    {
        // get number of test cases
        std::getline(finput, line); 
        numCases = atoi(line.c_str());

        for (int i = 0; i < numCases; ++i)
        {
            TestCase tc = TestCase();
           
            std::getline(finput, line); 
            tc.line = line;

            testCases.push_back(tc);
        } // for
    }

    finput.close();

    // build mapping (determined this from sample test cases since mapping remains the same for ALL test cases)
    mapping = buildMapping();

    int i = 1;

    // solve each test case
    for (std::vector<TestCase>::iterator it = testCases.begin(); it < testCases.end(); ++it)
    {
        std::cout << "Case #" << i++ << ": " << translateLine(it->line, mapping) << std::endl;
    } // for

    //clock_t end = clock();
    //std::cout << "Time elapsed: " << (end - begin) << std::endl;

    return 0;
}

std::map<char, char> buildMapping()
{
    std::map<char, char> mapping;

    mapping['y'] = 'a';
    mapping['n'] = 'b';
    mapping['f'] = 'c';
    mapping['i'] = 'd';
    mapping['c'] = 'e';
    mapping['w'] = 'f';
    mapping['l'] = 'g';
    mapping['b'] = 'h';
    mapping['k'] = 'i';
    mapping['u'] = 'j';
    mapping['o'] = 'k';
    mapping['m'] = 'l';
    mapping['x'] = 'm';
    mapping['s'] = 'n';
    mapping['e'] = 'o';
    mapping['v'] = 'p';
    mapping['z'] = 'q';
    mapping['p'] = 'r';
    mapping['d'] = 's';
    mapping['r'] = 't';
    mapping['j'] = 'u';
    mapping['g'] = 'v';
    mapping['t'] = 'w';
    mapping['h'] = 'x';
    mapping['a'] = 'y';
    mapping['q'] = 'z';

    return mapping;
}

std::string translateLine(std::string line, std::map<char, char> mapping)
{
    std::string translatedLine = "";

    for (int i = 0; i < line.length(); i++)
    {
        translatedLine += (line[i] == ' ' ? line[i] : mapping[line[i]]);
    } // for

    return translatedLine;
}
