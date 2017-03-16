#include <fstream>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <deque>
#include <iomanip>
using namespace std;

class Node
{
public:
    vector<int> parents;
    int visitedBy;
    Node()
    {
        visitedBy = -1;
    }
};

bool DepthFirstIterate(Node* classes, int self, int sourceNode)
{
    if (classes[self].visitedBy == sourceNode)
    {
        return true;
    }
    else
    {
        classes[self].visitedBy = sourceNode;
        vector<int>::iterator iter;
        for (iter = classes[self].parents.begin(); iter != classes[self].parents.end(); iter++)
        {
            if (true == DepthFirstIterate(classes, *iter, sourceNode))
            {
                return true;
            }
        }
        return false;
    }
}


int main()
{
    ifstream in("A-large.in");
    ofstream out("A-large.out");
    int T;
    in >> T;
    for (int x = 0; x < T; x++)
    {
        int N;
        in >> N;
        Node* allClasses = new Node[N];
        for (int i = 0; i < N; i++)
        {
            int M;
            in >> M;
            for (int j = 0; j < M; j++)
            {
                int P;
                in >> P;
                allClasses[i].parents.push_back(P-1);
            }
        }

        bool hasDiamond = false;
        for (int i = 0; i < N; i++)
        {
            if (allClasses[i].parents.size() > 1)
            {
                if (true == DepthFirstIterate(allClasses, i, i))
                {
                    hasDiamond = true;
                    break;
                }
            }
        }

        out << "Case #" << (x+1) << ": ";
        if (hasDiamond)
        {
            out << "Yes";
        }
        else
        {
            out << "No";
        }
        out << endl;
        delete [] allClasses;
    }
    in.close();
    out.close();
    return 0;
}
