#include <fstream>
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <sstream>
#include <algorithm>

// Usage:
// cat input.txt | ./main > output.txt
// ./main input.txt > output.txt
// ./main input.txt output.txt

void processAllCases(std::istream &is, std::ostream &os);
void processCase(const int iteration, std::istream &is, std::ostream &os);

int main(int argc, char *argv[]) {
    std::ostream* os;
    std::istream* is;
    std::ofstream fout;
    std::ifstream fin;
    switch(argc) {
        case 1:
            os = &std::cout;
            is = &std::cin;
            break;
        case 2:
            fin.open(argv[1]);
            is = &fin;
            os = &std::cout;
            break;
        case 3:
            fin.open(argv[1]);
            is = &fin;
            fout.open(argv[2]);
            os = &fout;
            break;
        default:
            std::cout
                << "Usage:" << std::endl
                << "cat input.txt | ./main > output.txt" << std::endl
                << "./main input.txt > output.txt" << std::endl
                << "./main input.txt output.txt" << std::endl;
            return 1;
    }
    processAllCases(*is, *os);
    return 0;
}

// process all cases
void processAllCases(std::istream &is, std::ostream &os)
{
    int totalCases;
    is >> totalCases;
    for(int caseNumber = 1; caseNumber <= totalCases; ++caseNumber)
    {
        processCase(caseNumber, is, os);
    }
}

bool isVowel(const char letter);

// process individual case, caseNumber = 1..totalCases
void processCase(const int caseNumber, std::istream &is, std::ostream &os)
{
    std::string name;
    long n;
    is >> name;
    is >> n;
    long count = 0;

    std::vector<std::string> substrings;


    for(long i = 0; i < name.length(); ++i)
    {
        for (long j = i + n; j < name.length() + 1; ++j)
        {
            substrings.push_back(name.substr(i, j - i));
        }

    }

    for (long k =0; k < substrings.size(); ++k)
    {
        long maxNumberOfConsonants = 0;
        long numberOfConsonants = 0;
        for(long l=0; l < substrings[k].size(); ++l)
        {
            if(!isVowel(substrings[k][l]))
            {
                numberOfConsonants++;
            }
            else
            {
                if(numberOfConsonants > maxNumberOfConsonants)
                {
                    maxNumberOfConsonants = numberOfConsonants;
                }
                numberOfConsonants =0;
            }



        }

        if(numberOfConsonants > maxNumberOfConsonants)
        {
            maxNumberOfConsonants = numberOfConsonants;
        }

        if(maxNumberOfConsonants >= n)
        {
            count++;
        }


    }




    os << "Case #" << caseNumber << ": " << count << std::endl;

}

bool isVowel(const char letter)
{
    return (letter == 'a' || letter == 'e' || letter == 'i' || letter == 'o' || letter == 'u');
}
