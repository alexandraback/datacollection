#include <fstream>
#include <iostream>
#include <set>
#include <memory>
#include <queue>
#include <vector>

using namespace std;

vector<vector<int>> allClasses;

int main()
{
    ifstream myStream("A-small-attempt1.in");
    ofstream outStream("A-small-attempt1.out");
    int T;
    int N;
    myStream >> T;
    for (int t = 0; t < T; ++t)
    {
        myStream >> N;
        allClasses.clear();
        allClasses.resize(N + 1);
        set<int> inherited;
        for (int i = 1; i <= N; ++i)
        {
            int M;
            myStream >> M;
            allClasses[i].resize(M);
            for (int j = 0; j < M; ++j)
            {
                myStream >> allClasses[i][j];
                inherited.insert(allClasses[i][j]);
            }
        }
        // find the ones at the bottom of the inheritance chain

        queue<int> startQ;
        for (int i = 1; i <= N; ++i)
        {
            if (inherited.count(i) <= 0)
                startQ.push(i);
        }

        bool diamond = false;
        if (startQ.empty())
            diamond = true;
        while (!startQ.empty())
        {
            set<int> seen;
            int start = startQ.front();
            startQ.pop();
            queue<int> myQ;
            myQ.push(start);
            while (!myQ.empty())
            {
                int top = myQ.front();
                myQ.pop();
                if (seen.count(top) > 0)
                {
                    diamond = true;
                    break;
                }
                seen.insert(top);
                for (int j = 0; j < allClasses[top].size(); ++j)
                    myQ.push(allClasses[top][j]);
            }
            if (diamond)
                break;
        }

        if (diamond)
            outStream << "Case #" << (t + 1) << ": " << "Yes" << endl;
        else
            outStream << "Case #" << (t + 1) << ": " << "No" << endl;
    }

    int a = 0;
}