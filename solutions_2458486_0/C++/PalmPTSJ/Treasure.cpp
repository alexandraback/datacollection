#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <windows.h>

#define FORWARDCHECKLIMIT 12

using namespace std;

vector<int> solvePath;
int startKeyN,chestN;

struct chestS {
    int keyNeed;
    vector<int> keyHave;
    int index;
    bool can;
};

bool canGetKey(int *keyHave,vector< chestS > chest,chestS targChest)
{
    //printf("[Want To Open %d] ",targChest.index);
    if(keyHave[targChest.keyNeed] > 0) {
        //printf(" OK ");
        return true;
    }
    for(int i = 0;i < chest.size();i++) // All chest
    {
        // if this chest have targKey
        if(chest[i].index != targChest.index)
        for(int k = 0;k < chest[i].keyHave.size();k++) { // get all key
            if(chest[i].keyHave[k] == targChest.keyNeed)
            {
                vector< chestS > newChest(chest);
                newChest.erase(newChest.begin() + i);
                if(canGetKey(keyHave,newChest,chest[i])) return true;
                break;
            }
        }
    }
    //printf(" NOT ");
    return false;
}

bool solve(int *keyHave,vector< chestS > chest,bool forwardCheck)
{
    //O++;
    if(chest.size() == 0)
    {
        // print ans
        for(int i = 0;i < solvePath.size();i++)
        {
            printf("%d ",solvePath[i]+1);
        }
        return true;
    }

    // forward check here
    if(forwardCheck) {
        for(int i = 0;i < chest.size();i++)
        {
            if(chest[i].can == false){
                if(!canGetKey(keyHave,chest,chest[i]))
                    return false;
                else
                    chest[i].can = true;
            }
        }
    }

    // loop solve
    for(int i = 0;i < chest.size();i++) // All chest
    {
        if(keyHave[chest[i].keyNeed] > 0 )
        {
           //printf("<%2d> ",chest[i].index);
            keyHave[chest.at(i).keyNeed]--;

            vector< chestS > newChest(chest);
            solvePath.push_back(chest[i].index); // unlock this

            for(int k = 0;k < newChest[i].keyHave.size();k++) // get all key
                keyHave[chest[i].keyHave[k]]++;
            newChest.erase(newChest.begin() + i);

            if(forwardCheck) {
                if(keyHave[chest.at(i).keyNeed] == 0)
                {
                    for(int j = 0;j < chest.size();j++)
                    {
                        if(newChest[j].keyNeed == chest.at(i).keyNeed)
                        {
                            newChest[j].can = false;
                        }
                    }
                }
            }

            //printf("BEF SOLVE");
            if(solve(keyHave,newChest,forwardCheck) == true) return true;
            solvePath.pop_back();
            //printf("BEF SOLVE");

            for(int k = 0;k < chest[i].keyHave.size();k++) // get all key
                keyHave[chest[i].keyHave[k]]--;

            keyHave[chest.at(i).keyNeed]++;

            //printf("RET");
        }
    }
    return false;
}

int main()
{
    int t,tt;
    scanf("%d",&tt);
    for(t=0;t < tt;t++)
    {
        solvePath.clear();
        vector<int> chestKeyNeed;
        scanf("%d %d",&startKeyN,&chestN);
        vector<int> startKey;
        int* keyCount = (int*)calloc(sizeof(int),401);
        int* keyHave = (int*)calloc(sizeof(int),401);
        int* keyType = (int*)calloc(sizeof(int),401);
        for(int i = 0;i < startKeyN;i++)
        {
            int num;
            scanf("%d",&num);
            startKey.push_back(num);
            keyCount[num]++;
            keyHave[num]++;
        }

        vector< chestS > chest;
        for(int i = 0;i < chestN;i++)
        {
            chestS chestData;
            chestData.can = false;
            scanf("%d",&chestData.keyNeed);
            keyCount[chestData.keyNeed]--;
            int kCount;
            scanf("%d",&kCount);
            for(int j = 0;j < kCount;j++)
            {
                int k;
                scanf("%d",&k);
                chestData.keyHave.push_back(k);
                keyType[k]++;
                keyCount[k]++;
            }
            chestData.index = i;
            chest.push_back(chestData);
        }
        // Check for impossible case
        printf("Case #%d: ",t+1);
        bool pass = true;

        int max = 0;
        for(int i = 0;i < 401;i++)
        {
            if(keyCount[i] < 0) {
                printf("IMPOSSIBLE\n");
                pass = false;
                break;
            }
            max = keyType[i]>max?keyType[i]:max;
        }

        if(!pass) continue;



        if(solve(keyHave,chest,max<FORWARDCHECKLIMIT) == false) printf("IMPOSSIBLE\n");
        else printf("\n");
    }
}
