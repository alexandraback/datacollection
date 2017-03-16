#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <map>
#include <list>
#include <vector>
#include <algorithm>
#include <functional>

////////////////////////////////////////////////////////////
// Input
// Output
////////////////////////////////////////////////////////////

namespace
{
    static std::ofstream &GetOut()
    {
        static std::ofstream C_OUT("out.txt", std::ofstream::out);
        return C_OUT;
    }

    static std::ifstream &GetIn()
    {
        static std::ifstream C_IN;
        return C_IN;
    }
}

////////////////////////////////////////////////////////////
// Problem specific data
////////////////////////////////////////////////////////////

typedef std::vector<double> ListOfMasses;

////////////////////////////////////////////////////////////
// Problem
////////////////////////////////////////////////////////////

class Problem
{
public:
    Problem();
    ~Problem();

    const std::string& getSolution();
private:
    int          r_n;
    ListOfMasses r_ken;
    ListOfMasses r_naomi;
    std::string r_solution;

    void solveProblem();
};

Problem::Problem()
 : r_n(-1),
   r_ken(),
   r_naomi(),
   r_solution("")
{

    //would read the problem data from input file
    GetIn() >> r_n;
    std::cout << std::setprecision(7);
    std::cout << std::fixed;

    double value;
    int i = 0;
    for(i = 0; i < r_n; ++i)
    {
        GetIn() >> value;
        r_naomi.push_back(value);
    }

    for(i = 0; i < r_n; ++i)
    {
        GetIn() >> value;
        r_ken.push_back(value);
    }
}

Problem::~Problem()
{
}

const std::string& Problem::getSolution()
{
    solveProblem();
    return r_solution;
}

void Problem::solveProblem()
{
    int deceitfulScore = 0;
    int score = 0;

    ListOfMasses deceitfulKen = r_ken;
    ListOfMasses deceitfulNaomi = r_naomi;

    std::stable_sort(begin(deceitfulKen), end(deceitfulKen), 
        std::greater<double>());
    std::stable_sort(begin(deceitfulNaomi), end(deceitfulNaomi),
        std::greater<double>());
    int i = 0;
    int n = 0;
    int k = 0;
    int nChosen = 0;
    int kChosen = 0;

    for(i = 0; i < r_n; ++i)
    {
        nChosen = deceitfulNaomi.size() - 1;
        kChosen = deceitfulKen.size() - 1;
        if (deceitfulNaomi[nChosen] > deceitfulKen[kChosen])
        {
            ++deceitfulScore;
        }else
        {
            kChosen = 0;
        }

        deceitfulNaomi.erase(deceitfulNaomi.begin() + nChosen);
        deceitfulKen.erase(deceitfulKen.begin() + kChosen);
    }

    ListOfMasses ken = r_ken;
    ListOfMasses naomi = r_naomi;

    std::stable_sort(begin(ken), end(ken), std::greater<double>());
    std::stable_sort(begin(naomi), end(naomi), std::greater<double>());

    for(i = 0; i < r_n; ++i)
    {
        nChosen = 0;
        kChosen = 0;
        if (naomi[nChosen] > ken[kChosen])
        {
            ++score;
            kChosen = ken.size() - 1;
        }else
        {
            do 
            {
                ++kChosen;
            } while (kChosen < ken.size() && ken[kChosen] > naomi[nChosen]);
            --kChosen;
        }

        naomi.erase(naomi.begin());
        ken.erase(ken.begin() + kChosen);
    }

    r_solution = std::to_string(deceitfulScore);
    r_solution += " ";
    r_solution += std::to_string(score);
}
////////////////////////////////////////////////////////////
// Test case
////////////////////////////////////////////////////////////

class TestCase
{
public:
    TestCase(int iCaseNumber)
    {
        std::cout << "\t\t -- Process Test Case: " << iCaseNumber 
            << " --"<<std::endl;

        auto solution = Problem().getSolution();

        std::cout << "Case #" << iCaseNumber << ": "
            << solution.c_str() << std::endl;

        GetOut() << "Case #" << iCaseNumber << ": "
            << solution.c_str() << std::endl;
    }
    ~TestCase(){}
};

////////////////////////////////////////////////////////////
// The problem solver
////////////////////////////////////////////////////////////

class ProblemSolver
{
public:
    ProblemSolver(const std::string &iInputFile)
    {
        GetIn().open(iInputFile, std::ifstream::in);

        if(false == GetIn().good())
        {
            std::cout << "read file failed\n";
            return;
        }
        else
        {
            int nbOfTestCases = 0;
            GetIn() >> nbOfTestCases;

            std::cout << "Test cases: " << nbOfTestCases << std::endl;

            for(int i = 1; i <= nbOfTestCases; ++i)
            {
                TestCase t(i);
            }
        }
    }

    ~ProblemSolver() 
    {
        GetIn().close();
        GetOut().close();
    }

private:
};

void readInput();
void openOutput();
void findItems(TestCase testCase);
void closeOutput();

////////////////////////////////////////////////////////////
// main function
////////////////////////////////////////////////////////////

void main()
{
    //ProblemSolver("test.txt");
    ProblemSolver("D-small-attempt0.in");
    //ProblemSolver("D-large.in");
    getchar();
}
