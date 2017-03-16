#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <vector>
#include <set>
#include <sstream>
#include <ctime>
#include <cmath>

long recycleNumber(long number, int digitToMove);
int getNumRecycledPairs(long min, long max);

struct TestCase
{
    long min;
    long max;
};

int main(int argc, char* argv[])
{
    // clock_t begin = clock();
   
    // read in data
    std::ifstream finput(argv[1]);

    std::string line = ""; // treating this as more of a delimited item, less a line

    int numCases = 0;

    std::vector<TestCase> testCases;

    if (finput.is_open())
    {
        // get number of test cases
        finput >> line;
        numCases = atoi(line.c_str());

        // read in test cases
        for (int i = 0; i < numCases; ++i)
        {
            TestCase tc = TestCase();
            
            finput >> line;
            tc.min = atol(line.c_str());

            finput >> line;
            tc.max = atol(line.c_str());

            testCases.push_back(tc);
        } // for
    }

    finput.close();

    int i = 1;

    // solve each test case
    for (std::vector<TestCase>::iterator it = testCases.begin(); it < testCases.end(); ++it)
    {
        std::cout << "Case #" << i++ << ": " << getNumRecycledPairs(it->min, it->max) << std::endl;
    } // for

    // clock_t end = clock();
    // std::cout << "Time elapsed: " << (end - begin) << std::endl;

    return 0;
}

long recycleNumber(long number, int digitToMove)
{
    long retNum = 0;

    std::string strNum = "";
    std::stringstream ss;

    ss << number;

    strNum = ss.str();

    int idx = (strNum.length() - 1) - (digitToMove - 1);

    strNum = strNum.substr(idx, digitToMove) + strNum.substr(0, idx);

    std::istringstream(strNum) >> retNum;

    return retNum;
}

int getNumRecycledPairs(long min, long max)
{
    std::set<std::pair<long, long> > recycledPairs;

    // we'll do this the naive way because it's late and while I know a better way, I don't have time to implement/think through entirely :)
    std::string strMax = "";
    std::stringstream ss;

    ss << max;

    strMax = ss.str();   

    int numLength = strMax.length();

    // determine pairs
    for (long i = min; i <= max; i++)
    {
        // skip numbers w/ digits all the same
        std::string strNum = "";
        std::stringstream ss1;

        ss1 << i;

        strNum = ss1.str();

        char d = strNum[0];
        int dCount = 1;

        for (int j = 1; j < strNum.length(); j++)
        {
            if (strNum[j] == d)
                dCount++;
        } // for

        if (dCount == strNum.length())
            continue;

        for (int j = 1; j <= numLength - 1; j++)
        {
            // recycle the number for this iteration
            
            // skip digits that are 0
            if (((long)(i / pow(10, j - 1)) % 10 == 0))
                continue;

            long rNum = recycleNumber(i, j);

            // check if all digits are the same (doesn't mean criteria) and make sure rNum <= max)
            if (rNum <= i || rNum > max || rNum < min)
            {
                continue;
            } // if

            // ASSERT: i < rNum and is valid
            recycledPairs.insert(std::pair<long, long>(i, rNum));
        } // for
    } // for

    return recycledPairs.size();
}

