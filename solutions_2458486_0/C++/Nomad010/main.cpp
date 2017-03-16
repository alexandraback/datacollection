#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cinttypes>
#include <string>
#include <vector>

using std::vector;

int K, N;

vector<int> Memoised;
vector<int> Solvable;
vector<int> NumKeys;

vector<int> ChestInput;
vector<vector<int>> ChestOutput;

bool Solve(int openChests)
{
//     printf("Testing %d\n", openChests); 
    if(openChests == 0)
    {
//         printf("\tGot base case\n");
        return true;
    }
    
    if(Memoised[openChests])
    {
//         printf("\tGot memoised case: %d\n", Solvable[openChests]);
        return Solvable[openChests];
    }
    
    Solvable[openChests] = false;
    Memoised[openChests] = true;
    
    int chestNumber = 0;
    int chestBit = 1;
    
    while(chestBit <= openChests)
    {
        
        if((chestBit & openChests) != 0)
        {
//             printf("\t\t%d does contain bit %d\n", openChests, chestBit);
            
            int keyRequired = ChestInput[chestNumber];
            if(NumKeys[keyRequired] > 0)
            {
                --NumKeys[keyRequired];
                for(int i = 0; i < int(ChestOutput[chestNumber].size()); ++i)
                        NumKeys[ChestOutput[chestNumber][i]]++;
                
                if(Solve(openChests & ~chestBit))
                {
                    Solvable[openChests] = true;
                    ++NumKeys[keyRequired];
                    for(int i = 0; i < int(ChestOutput[chestNumber].size()); ++i)
                        NumKeys[ChestOutput[chestNumber][i]]--;
                    
                    break;
                }
                else
                {
                    ++NumKeys[keyRequired];
                    for(int i = 0; i < int(ChestOutput[chestNumber].size()); ++i)
                        NumKeys[ChestOutput[chestNumber][i]]--;
                }
                
            }
            else
            {
//                 printf("\t\tRequired key %d, but have %d of them\n", keyRequired, NumKeys[keyRequired]);
            }
        }
        else
        {
//             printf("\t\t%d does not contain bit %d\n", openChests, chestBit);
        }
        ++chestNumber;
        chestBit <<= 1;
    }
    
//     printf("\tComputed result: %d\n", Solvable[openChests]);
    
    return Solvable[openChests];
}

int main(int argc, char** argv)
{   
    int T;
    scanf("%d", &T);
    
    for(int t = 1; t <= T; ++t)
    {
        printf("Case #%d:", t);
        
        scanf("%d %d", &K, &N);
        
        Memoised.clear();
        Memoised.resize(1 << N);
        
        Solvable.clear();
        Solvable.resize(1 << N);
        
        NumKeys.clear();
        NumKeys.resize(201);
        
        ChestInput.clear();
        ChestInput.resize(N);
        
        ChestOutput.clear();
        ChestOutput.resize(N);
        
        for(int i = 0; i < K; ++i)
        {
            int ki;
            scanf("%d", &ki);
            ++NumKeys[ki];
        }
        
        for(int i = 0; i < N; ++i)
        {
            int Ti, Ki;
            scanf("%d %d", &Ti, &Ki);
            ChestInput[i] = Ti;
            ChestOutput[i].resize(Ki);
            
            for(int j = 0; j < Ki; ++j)
                scanf("%d", &ChestOutput[i][j]);
        }
        
        /// Solve everything
//         for(int i = 0; i < (1<<N); ++i)
//             Solve(i);
        
        /// Start with all chests open
        int currentState = (1<<N) - 1;
        
        if(!Solve(currentState))
        {
            printf(" IMPOSSIBLE\n");
            continue;
        }
        
        while(currentState != 0)
        {
//             break;
            int chestNumber = 0;
            int chestBit = 1;
            
            while(chestBit <= currentState)
            {
                if((chestBit & currentState) != 0)
                {
                    /// This chest is unopened...
                    int keyRequired = ChestInput[chestNumber];
                    if(NumKeys[keyRequired] > 0)
                    {
                        /// We can open it...
                        --NumKeys[keyRequired];
                        for(int i = 0; i < int(ChestOutput[chestNumber].size()); ++i)
                            NumKeys[ChestOutput[chestNumber][i]]++;
                        
                        bool CanStillSolve = Solve(currentState & ~chestBit);
                        if(CanStillSolve)
                        {
                            /// Can solve it - take it.
                            currentState = currentState & ~chestBit;
                            printf(" %d", chestNumber + 1);
                            break;
                        }
                        else
                        {
                            /// Can't solve - rewind
                            ++NumKeys[keyRequired];
                            for(int i = 0; i < int(ChestOutput[chestNumber].size()); ++i)
                                NumKeys[ChestOutput[chestNumber][i]]--;
                        }
                    }
                }
                
                chestBit <<= 1;
                ++chestNumber;
            }
        }
        
        printf("\n");
//         break;
    }
}