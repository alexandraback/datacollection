#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <map>
#include <list>
#include <vector>

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
    double      r_C;
    double      r_F;
    double      r_X;
    std::string r_solution;

    void solveProblem();
};

Problem::Problem()
 : r_C(-1),
   r_F(),
   r_X(),
   r_solution("")
{
    //would read the problem data from input file
    GetIn() >> r_C;
    std::cout << std::setprecision(7);
    std::cout << std::fixed;
    //std::cout << "C: " << r_C << std::endl;
    GetIn() >> r_F;
    //std::cout << "F: " << r_F << std::endl;
    GetIn() >> r_X;
    //std::cout << "X: " << r_X << std::endl;

    //std::cout << "\n";
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
    if(r_X <= r_C)
    {
        r_solution = std::to_string(r_X / 2.0);
        return;
    }

    double production = 2.0;
    double nextProduction = 0.0;
    double nextProductionTotalTime = 0.0;
    double productionTotalTime = 0.0;
    double productionFarmTime = 0.0;
    double extraFarmTime = 0.0;
    double totalTime = 0.0;

    while (true)
    {
        nextProduction = production + r_F;
        productionFarmTime = r_C / production;
        nextProductionTotalTime = r_X / nextProduction;
        productionTotalTime = r_X / production;
        extraFarmTime = nextProductionTotalTime + productionFarmTime;

        if(productionTotalTime < extraFarmTime)
        {
            totalTime += productionTotalTime;
            break;
        }
        else
        {
            totalTime += productionFarmTime;
            production = nextProduction;
        }
    }

    r_solution = std::to_string(totalTime);
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
    ProblemSolver("B-small-attempt0.in");
    //ProblemSolver("B-large-attempt0.in");
    getchar();
}
