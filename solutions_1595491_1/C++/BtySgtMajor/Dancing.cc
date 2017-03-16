#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <ctime>

int getNumDancers(std::vector<int> scores, int numSurprising, int minP);
int totalTriplet(int triplet[2]);

struct TestCase
{
    std::vector<int> scores;
    int numSurprising;
    int minP;
};

int main(int argc, char* argv[])
{
    // clock_t begin = clock();
   
    // read in data
    std::ifstream finput(argv[1]);

    std::string line = ""; // treating this as more of a delimited item, less a line

    int numCases = 0;
    int numDancers = 0;
    int numSurprising = 0;
    int minP = 0;

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
            numDancers = atoi(line.c_str());

            finput >> line;
            numSurprising = atoi(line.c_str());
            tc.numSurprising = numSurprising;

            finput >> line;
            minP = atoi(line.c_str());
            tc.minP = minP;

            for (int j = 0; j < numDancers; ++j)
            {
                finput >> line;
                tc.scores.push_back(atoi(line.c_str()));
            } // for

            testCases.push_back(tc);
        } // for
    }

    finput.close();

    int i = 1;

    // solve each test case
    for (std::vector<TestCase>::iterator it = testCases.begin(); it < testCases.end(); ++it)
    {
        std::cout << "Case #" << i++ << ": " << getNumDancers(it->scores, it->numSurprising, it->minP) << std::endl;
    } // for

    // clock_t end = clock();
    // std::cout << "Time elapsed: " << (end - begin) << std::endl;

    return 0;
}

int totalTriplet(int triplet[2])
{
    return triplet[0] + triplet[1] + triplet[2];
} 

int getNumDancers(std::vector<int> scores, int numSurprising, int minP)
{
    int numDancersWithP = 0;
    int numSurprisingLeft = numSurprising;

    for (std::vector<int>::iterator it = scores.begin(); it != scores.end(); ++it)
    {
        // make a best guess as to a starting triplet for this score without going over (use integer division to ensure this)
        int triplet[3] = {0, 0, 0};

        int initialVal = (*it) / 3;

        // check to see if we can just move on here, i.e. initialVal >= minP
        if (initialVal >= minP)
        {
            numDancersWithP++;
            continue;
        } // if

        if (*it == 0) 
            continue;

        triplet[0] = triplet[1] = triplet[2] = initialVal;

        // check to see if we can get a score to minP

        // this result will be within the range [0,2]
        int totalDiff = (*it) - totalTriplet(triplet);

        switch (totalDiff)
        {
            // if totalDiff == 0: if we want to see if we can get to minP, then we have to check increasing initialVal by 1 (assuming a corresponding decrease in another element by 1, as well)
            case 0:
                if (initialVal + 1 == minP && numSurprisingLeft > 0)
                {
                    // ...then this must be a surprising case
                    numSurprisingLeft--;
                    numDancersWithP++;
                } // if

                break;

            // if totalDiff == 1: if we want to see if we can get to minP, then we have to increase one of the elements by 1
            case 1:
                if (initialVal + 1 == minP)
                {
                    numDancersWithP++;
                } // if

                break;

            // if totalDiff == 2: if we want to see if we can get to minP, then we have to check the following:
            //     a) check increasing two elements by one
            //     b) check increasing one element by two and if there are any surprising scores left
            case 2:
                if (initialVal + 1 == minP)
                {
                    numDancersWithP++;
                } 
                else if (initialVal + 2 == minP && numSurprisingLeft > 0)
                {
                    // ...then this must be a surprising case
                    numSurprisingLeft--;
                    numDancersWithP++;
                } // if

                break;
        } // switch
    } // for

    return numDancersWithP;
}

