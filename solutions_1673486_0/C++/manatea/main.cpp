//
//  main.cpp
//  a
//

#include <iostream>
#include <vector>
using namespace std;

int main(int argc, const char * argv[])
{
    char inputbuf[128];
    gets(inputbuf);
    int nCases = atoi(inputbuf);
    
    for (int caseNo = 1; caseNo <= nCases; ++caseNo) {
        gets(inputbuf);
        char* ptr = strtok(inputbuf, " ");
        int nTyped = atoi(ptr);
        ptr = strtok(NULL, " ");
        int wordLen = atoi(ptr);
        
        gets(inputbuf);
        vector<double> probList(nTyped);
        ptr = strtok(inputbuf, " ");
        probList[0] = atof(ptr);
        
        for (int i = 1; i < nTyped; ++i) {
            ptr = strtok(NULL, " ");
            probList[i] = atof(ptr);
        }
        
        double minExpect = 1 + wordLen + 1;
        double probCorrect = 1.0;
        for (int nBS = nTyped; 0 <= nBS; --nBS) {
            int strokesSuccess = nBS * 2 + (wordLen - nTyped) + 1;
            int strokesFail = strokesSuccess + wordLen + 1;
            
            double expect = strokesSuccess * probCorrect + strokesFail * (1.0 - probCorrect);
            if (expect < minExpect) {
                minExpect = expect;
            }
            probCorrect *= probList[nTyped - nBS];
        }

        
        cout << "Case #" << caseNo << ": ";
        cout << minExpect << endl;
    }
    
    return 0;
}

