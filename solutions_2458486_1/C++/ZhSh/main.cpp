#include <iostream>
#include <fstream>
#include <vector>
#include <assert.h>
using namespace std;

//int chests[200];
int myKeys[201];
//int keyToOpenChest[200];
int T[201];
int K[201];
int keysInside[201][201];

int N;

//int numOpenChests;
int openChests[201];
int sequence[201];

int transitions[201][201];

void init()
{
    for (int i = 1; i <= N; ++i)
    {
        openChests[i] = 0;
    }
}

void initTransitions()
{
    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= N; ++j)
        {
            transitions[i][j] = 0;
        }
    }
    
    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= N; ++j)
        {
            int keyToOpenJ = T[j];
            if (keysInside[i][keyToOpenJ] > 0)
            {
                transitions[i][j] = 1;
            }
//            cout << transitions[i][j];
        }
//        cout << endl;
    }
}

bool isPossibleToFinish(int* myKeysTry, int* openChestsTry)
{
/*
    cout << endl << "isPossibleToFinish" << endl;
    for (int i = 1; i < 201; ++i)
    {
        if (myKeysTry[i] != 0) cout << "Keys[" << i << "]: " << myKeysTry[i] << endl;
    }
    for (int i = 1; i <= N; ++i)
    {
        cout << openChestsTry[i];
    }
    cout << endl;
*/    
    int reachable = 0;
    int openChestsTest[201];
    for (int i = 1; i <= N; ++i)
    {
        openChestsTest[i] = openChestsTry[i];
        if (openChestsTry[i] > 0)
        {
            reachable += 1;
        }
    }
    
    for (int i = 1; i < 201; ++i)
    {
        if (myKeysTry[i] > 0)
        {
            for (int j = 1; j <= N; ++j)
            {
                if (T[j] == i)
                {
                    openChestsTest[j] = 1;
                }
            }
        }
    }
    
    while (1)
    {
        int openChestsNext[201];
        for (int i = 1; i <= N; ++i)
        {
            openChestsNext[i] = openChestsTest[i];
        }
/*
        cout << "openChestsNext BEFORE: ";
        for (int i = 1; i <= N; ++i)
        {
            cout << openChestsNext[i];
        }
        cout << endl;
*/
        reachable = 0;
        for (int i = 1; i <= N; ++i)
        {
            if (openChestsTest[i] > 0)
            {
                reachable += 1;
            }
        }
        
        for (int i = 1; i <= N; ++i)
        {
            if (openChestsTest[i] == 0)
            {
                continue;
            }
            if (openChestsTry[i] == 1)
            {
                continue;
            }
            
            for (int j = 1; j <= N; ++j)
            {
                if (transitions[i][j] == 1)
                {
                    openChestsNext[j] = 1;
                }
            }
        }
/*
        cout << "openChestsNext AFTER : ";
        for (int i = 1; i <= N; ++i)
        {
            cout << openChestsNext[i];
        }
        cout << endl;
*/        
        int reachableNext = 0;
        for (int i = 1; i <= N; ++i)
        {
            if (openChestsNext[i] == 1)
            {
                reachableNext++;
            }
        }
        if (reachableNext == N)
        {
//            cout << "TRUE" << endl;
            return true;
        }
        if (reachable == reachableNext)
        {
//            cout << "FALSE" << endl;
            return false;
        }
        for (int i = 1; i <= N; ++i)
        {
            openChestsTest[i] = openChestsNext[i];
        }
        reachable = reachableNext;
    }
}

bool tryNew( int newChest )
{
//    cout << "tryNew: " << newChest << endl;
    int myKeysTry[201];
    for (int i = 1; i < 201; ++i)
    {
        myKeysTry[i] = myKeys[i];
    }
    
    myKeysTry[T[newChest]] -= 1;
    for (int i = 1; i < 201; ++i)
    {
        myKeysTry[i] += keysInside[newChest][i];
    }
    
    int openChestsTry[201];
    for (int i = 1; i <= N; ++i)
    {
        openChestsTry[i] = openChests[i];
    }
    openChestsTry[newChest] = 1;
    
    return isPossibleToFinish(myKeysTry, openChestsTry);
}

void printMyKeys()
{
    for (int i = 1; i < 201; ++i)
    {
        if (myKeys[i] != 0) cout << "Keys[" << i << "]: " << myKeys[i] << endl;
    }
}

void addNew( int newChest, int pos )
{
    sequence[pos] = newChest;
    openChests[newChest] = 1;
    myKeys[T[newChest]] -= 1;
    for (int i = 1; i < 201; ++i)
    {
        myKeys[i] += keysInside[newChest][i];
    }
    
//    cout << "Added " << newChest << endl;
//    printMyKeys();
}

void zero()
{
    for (int i = 0; i < 201; ++i)
    {
        myKeys[i] = 0;
        T[i] = 0;
        K[i] = 0;
        openChests[i] = 0;
        sequence[i] = 0;
        for (int j = 0; j < 201; ++j)
        {
            keysInside[i][j] = 0;
            transitions[i][j] = 0;
        }
    }
}

/*
void init()
{
    numOpenChests = 0;
    for (int i = 0; i < N; ++i)
    {
        openChests[i] = 0;
    }
}

int findChestToOpen( int from )
{
    for (int i = from; i < N; ++i)
    {
//        cout << "keyToOpenChest[i]: " << keyToOpenChest[i] << endl;
        if (openChests[i] == 0 && myKeys[keyToOpenChest[i]] != 0)
        {
//            cout << "findChestToOpen: " << i << endl;
            return i;
        }
    }
//    cout << "findChestToOpen: -1" << endl;
    return -1;
}

void openChest( int chestIx )
{
    sequence[numOpenChests] = chestIx;
    numOpenChests++;
    
    myKeys[keyToOpenChest[chestIx]] -= 1;
    
    vector<int> newKeys = keysInside[chestIx];
    for (int i = 0; i < newKeys.size(); ++i)
    {
        myKeys[newKeys[i]] += 1;
    }
    
    openChests[chestIx] = 1;
}

int closeLastChest()
{
    if (numOpenChests == 0)
    {
        return -1;
    }

    int lastChest = sequence[numOpenChests - 1];
    
    numOpenChests--;
    
    myKeys[keyToOpenChest[lastChest]] += 1;
    
    vector<int> newKeys = keysInside[lastChest];
    for (int i = 0; i < newKeys.size(); ++i)
    {
        myKeys[newKeys[i]] -= 1;
    }
    
    openChests[lastChest] = 0;
    
    return lastChest;
}

void print()
{
    cout << "Sequence: ";
    for (int i = 0; i < numOpenChests; ++i)
    {
        cout << sequence[i] << " ";
    }
    cout << endl;
    
    cout << "My Keys: ";
    for (int i = 0; i < 200; ++i)
    {
        if (myKeys[i] != 0)
        {
            cout << "Key[" << i << "]: " << myKeys[i] << endl;
        }
    }
}
*/
int main()
{
    ifstream inFile( "D-large.in" );
    
    ofstream outFile( "D-large.out" );
    int caseCount;
    inFile >> caseCount;
  
    for (int caseIx = 1; caseIx <= caseCount; ++caseIx)
    {
        zero();
        int KNumber;
        inFile >> KNumber;
        inFile >> N;
        
        for (int i = 0; i < KNumber; ++i)
        {
            int key;
            inFile >> key;
            myKeys[key] += 1;
        }
        
        for (int i = 1; i <= N; ++i)
        {
            inFile >> T[i];
            inFile >> K[i];
            for (int j = 0; j < K[i]; ++j)
            {
                int key;
                inFile >> key;
                keysInside[i][key] += 1;
            }
        }

        init();
        initTransitions();
        bool success = true;
        for (int i = 0; i < N; ++i)
        {
            bool ok = false;
            for (int j = 1; j <= N; ++j)
            {
                if (openChests[j] != 0)
                {
                    continue;
                }
                if (myKeys[T[j]] == 0)
                {
                    continue;
                }
                if (tryNew(j))
                {
                    addNew(j, i);
                    ok = true;
                    break;
                }
            }
            if (!ok)
            {
                cout << "Case #" << caseIx << ": IMPOSSIBLE"  << endl;
                outFile << "Case #" << caseIx << ": IMPOSSIBLE"  << endl;
                success = false;
                break;
            }
        }
        
        
        if (success)
        {
            cout << "Case #" << caseIx << ": ";
            outFile << "Case #" << caseIx << ": ";
            for (int i = 0; i < N; ++i)
            {
                cout << sequence[i] << (i == N - 1 ? "" : " ");
                outFile << sequence[i] << (i == N - 1 ? "" : " ");
            }
            cout << endl;
            outFile << endl;
        }
    }

    
    inFile.close();
    outFile.close();
    return 0;
}
