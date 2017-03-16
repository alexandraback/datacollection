#include <iostream>
#include <algorithm>
#include <string>
#include <set>

using namespace std;

int test_case = 0;

class Treasure
{
public:
    int Keys;
    multiset<int> KeyTypes;

    int NumChests;
    int *ChestKeyTypes;
    int *ChestInsideCount;
    int **ChestInside;

    Treasure(istream& is)
    {
        is >> Keys >> NumChests;
        //cout << Keys << " " << NumChests << endl;
        for (int i=0; i<Keys; ++i)
        {
            int t;
            is >> t;
            KeyTypes.insert(t);
        }
        
        ChestKeyTypes = new int[NumChests];
        ChestInsideCount = new int[NumChests];
        ChestInside = new int*[NumChests];
        for (int i=0; i<NumChests; ++i)
        {
            is >> ChestKeyTypes[i] >> ChestInsideCount[i];
            ChestInside[i] = new int[ChestInsideCount[i]];
            for (int j=0; j<ChestInsideCount[i]; ++j)
                is >> ChestInside[i][j];
        }
    }
    
    ~Treasure() {
        for (int i=0; i<NumChests; ++i) {
            delete[] ChestInside[i];
        }
        delete[] ChestInside;
        delete[] ChestInsideCount;
        delete[] ChestKeyTypes;
    }
    
    int check(int *sol) {
        multiset<int> curr = KeyTypes;
        multiset<int>::iterator it;
        for (int i=0; i<NumChests; ++i) {
            int chest = sol[i];
            it = curr.find(ChestKeyTypes[chest]);
            if ( it == curr.end() ) {
                return i;
            }
            curr.erase(it);
            for (int j=0; j<ChestInsideCount[chest]; ++j) {
                curr.insert(ChestInside[chest][j]);
            }
        }
        return -1;
    }

    bool result()
    {
        int *Solution = new int[NumChests];
        for (int i=0; i<NumChests; ++i)
            Solution[i] = i;
        
        do {
            int stopped = check(Solution);
            if (stopped == -1) {
                for (int i=0; i<NumChests; ++i)
                    cout << " " << (Solution[i]+1);
                delete[] Solution;
                return true;
            }
            if (false) {
                for (int i=0; i<NumChests; ++i)
                    cout << " " << Solution[i];
                cout << endl;
                cout << stopped << " " << Solution[stopped] << endl;
            }
            
            int minDiff = NumChests;
            int minDiffPos = -1;
            while (minDiffPos == -1) {
                for (int i=stopped+1; i<NumChests; ++i) {
                    if (Solution[i] > Solution[stopped] && Solution[i] - Solution[stopped] < minDiff) {
                        minDiff = Solution[i] - Solution[stopped];
                        minDiffPos = i;
                        break;
                    }
                }
                if (minDiffPos == -1) {
                    if (stopped <= 0) {
                        delete[] Solution;
                        return false;
                    }
                    stopped--;
                }
            }
            if (minDiffPos >= 0) {
                int tmp = Solution[minDiffPos];
                Solution[minDiffPos] = Solution[stopped];
                Solution[stopped] = tmp;
                sort(Solution+stopped+1, Solution+NumChests);
                continue;
            }
        } while (next_permutation(Solution, Solution+NumChests));
        delete[] Solution;
        return false;
    }
    
};

void readfile(istream& is)
{
    int num_tests;
    is >> num_tests;
    for (test_case=1; test_case<=num_tests; ++test_case)
    {
        Treasure t(is);
        cout << "Case #" << test_case << ":";
        if ( !t.result() )
            cout << " IMPOSSIBLE";
        cout << endl;
    }
}

int main()
{
    readfile(cin);
    return 0;
}
