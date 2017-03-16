#include <iostream>
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
    int         r_R;
    int         r_C;
    int         r_M;
    std::string r_solution;

    void solveProblem();
};

Problem::Problem() 
 : r_R(-1),
   r_C(),
   r_M(),
   r_solution("")
{
    //would read the problem data from input file
    GetIn() >> r_R;
    GetIn() >> r_C;
    GetIn() >> r_M;
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
    r_solution = "\n";
    int freeCells = (r_R * r_C) - r_M;

    if(1 == freeCells)
    {
        r_solution += "c";

        for(int i = 0; i < r_C - 1; ++i)
        {
            r_solution += "*";
        }

        r_solution += "\n";

        for(int i = 1; i < r_R; ++i)
        {
            for(int i = 0; i < r_C; ++i)
            {
                r_solution += "*";
            }

            r_solution += "\n";
        }

        return;
    }

    if(r_R == 1)
    {
        r_solution += "c";

        for(int i = 0; i < freeCells - 1; ++i)
        {
            r_solution += ".";
        }

        for(int i = 0; i < r_M; ++i)
        {
            r_solution += "*";
        }

        return;
    }

    if(r_C == 1)
    {
        r_solution += "c\n";

        for(int i = 0; i < freeCells - 1; ++i)
        {
            r_solution += ".\n";
        }

        for(int i = 0; i < r_M; ++i)
        {
            r_solution += "*\n";
        }

        return;
    }

    if((freeCells < 4) ||
       (5 == freeCells) ||
       (7 == freeCells))
    {
        r_solution += "Impossible";
        return;
    }

    //r_solution += "c";

    int** matrix = new int*[r_R];
    for (int i = 0; i < r_R; ++i)
        matrix[i] = new int[r_C];

    //int maxim = std::max(r_R, r_C);
    int minim = std::min(r_R, r_C);
    int minSq = floor(sqrt(freeCells));
    int remaining = freeCells - (minSq * minSq);
    bool reduced = false;

    if((2 == minim) &&
       (1 == r_M%2))
    {
        r_solution += "Impossible";
        return;
    }

    if(1 == remaining)
    {
        --minSq;
    }

    if(1 + minSq == remaining)
    {
        reduced = true;
    }

    //populate matrix
    if(minSq >= r_C)
    {
        minSq = r_C * r_C;

        bool moveLast = false;
        if(1 == (freeCells - minSq)%r_C)
        {
            moveLast = true;
        }

        int i = 0;
        int j = 0;
        while (freeCells > 0)
        {
            for(j = 0; (j < r_C) && (freeCells > 0); ++j)
            {
                matrix[i][j] = 1;
                --freeCells;
            }
            ++i;
        }

        if(moveLast == true)
        {
            --i;
            --j;
            matrix[i][j + 1] = 1;
            matrix[i - 1][r_C - 1] = 0;
        }
    }else if (minSq >= r_R)
    {
        minSq = r_R * r_R;

        bool moveLast = false;
        if(1 == (freeCells - minSq)%r_R)
        {
            moveLast = true;
        }

        int j = 0;
        int i = 0;
        while (freeCells > 0)
        {
            for(i = 0; (i < r_R) && (freeCells > 0); ++i)
            {
                matrix[i][j] = 1;
                --freeCells;
            }
            ++j;
        }

        if(moveLast == true)
        {
            --i;
            --j;
            matrix[i + 1][j] = 1;
            matrix[r_R - 1][j - 1] = 0;
        }
    }
    else
    {
        for(int i = 0; i < minSq; ++i)
        {
            for(int j = 0; j < minSq; ++j)
            {
                matrix[i][j] = 1;
                --freeCells;
            }
        }

        int start = minSq;

        if(true == reduced)
        {
            --minSq;
        }

        if(r_R > r_C)
        {
            for(int i = start; (i < r_R) && (freeCells > 0); ++i)
            {
                for(int j = 0; (j < minSq) && (freeCells > 0); ++j)
                {
                    matrix[i][j] = 1;
                    --freeCells;
                }
            }

            if(freeCells > 0)
            {
                for(int j = start; (j < r_C) && (freeCells > 0); ++j)
                {
                    for(int i = 0; (i < minSq) && (freeCells > 0); ++i)
                    {
                        matrix[i][j] = 1;
                        --freeCells;
                    }
                }
            }
        }
        else
        {
            for(int j = start; (j < r_C) && (freeCells > 0); ++j)
            {
                for(int i = 0; (i < minSq) && (freeCells > 0); ++i)
                {
                    matrix[i][j] = 1;
                    --freeCells;
                }
            }

            if(freeCells > 0)
            {
                for(int i = start; (i < r_R) && (freeCells > 0); ++i)
                {
                    for(int j = 0; (j < minSq) && (freeCells > 0); ++j)
                    {
                        matrix[i][j] = 1;
                        --freeCells;
                    }
                }
            }
        }
    }


//create solution
//
    for(int i = 0; i < r_R; ++i)
    {
        for(int j = 0; j < r_C; ++j)
        {
            if(1 == matrix[i][j])
            {
                r_solution += ".";
            }
            else
            {
                r_solution += "*";
            }
        }

        r_solution += "\n";
    }
    r_solution[1] = 'c';

    for (int i = 0; i < r_R; ++i)
        delete [] matrix[i];
    delete [] matrix;
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
    ProblemSolver("C-small-attempt1.in");
    //ProblemSolver("C-large.in");
    getchar();
}
