#include <iostream>
#include <fstream>
using namespace std;

const int H_MAX = 101;

int main()
{
    ifstream inFile( "B-large.in" );
    int caseCount;
    inFile >> caseCount;
    ofstream outFile( "B-large.out" );
  
    for (int caseIx = 1; caseIx <= caseCount; ++caseIx)
    {
        int h[100][100];
        int N;
        inFile >> N;
        int M;
        inFile >> M;
        
        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < M; ++j)
            {
                inFile >> h[i][j];
            }
        }
        
        while (1)
        {
            int hMin = H_MAX;
            for (int i = 0; i < N; ++i)
            {
                for (int j = 0; j < M; ++j)
                {
                    if (h[i][j] < hMin) hMin = h[i][j];
                }
            }
            if (hMin == H_MAX)
            {
                cout << "Case #" << caseIx << ": YES" << endl;
                outFile << "Case #" << caseIx << ": YES" << endl;
                break;
            }
            
            bool good = false;
            for (int i = 0; i < N; ++i)
            {
                for (int j = 0; j < M; ++j)
                {
                    if (h[i][j] == hMin)
                    {
                        bool ok = true;
                        for (int t = 0; t < M; ++t)
                        {
                            if (h[i][t] != hMin && h[i][t] != H_MAX) ok = false;
                        }
                        if (ok)
                        {
                            good = true;
                            for (int t = 0; t < M; ++t)
                            {
                                h[i][t] = H_MAX;
                            }
                            
                        }

                        ok = true;
                        for (int t = 0; t < N; ++t)
                        {
                            if (h[t][j] != hMin && h[t][j] != H_MAX) ok = false;
                        }
                        if (ok)
                        {
                            good = true;
                            for (int t = 0; t < N; ++t)
                            {
                                h[t][j] = H_MAX;
                            }
                            
                        }
                    }
                }
            }
            if (!good)
            {
                cout << "Case #" << caseIx << ": NO" << endl;
                outFile << "Case #" << caseIx << ": NO" << endl;
                break;
            }
        }
    }

    
    inFile.close();
    outFile.close();
    return 0;
}
