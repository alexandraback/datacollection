/* 
 * File:   main_problem_c.cpp
 * Author: paulo
 *
 * Created on 13 de Abril de 2013, 16:06
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXKEYS     200
#define MAXCHESTS   200

typedef struct TagChest
{
    int ktype;
    bool isOpen;
    int nKeys;
    int keys[MAXKEYS];
}Chest;

bool isCasePossible(int keys[MAXKEYS], Chest *chests, int nchests){
    int requiredKeys[MAXKEYS];
    int possibleKeys[MAXKEYS];
    memset(requiredKeys, 0, sizeof(int)*MAXKEYS);
    memcpy(possibleKeys, keys, MAXKEYS*sizeof(int));
    for(int i=0;i<nchests;i++){
        requiredKeys[chests[i].ktype-1]+=1;
        for(int j=0;j<MAXKEYS;j++){
            if(chests[i].keys[j])
                possibleKeys[j]+=1;
        }
    }
    for(int i=0;i<MAXKEYS;i++)
        if(requiredKeys[i]>possibleKeys[i])
            return false;
    return true;
}

int solve(int keys[MAXKEYS], Chest *chests, int nchests, int level, int path[MAXCHESTS])
{
    int keyscopy[MAXKEYS];
    // For each chest, tries to find out if we open all other chests after opening it
    bool allopen=true;
    int openchests[MAXCHESTS], countopen=0;
    for(int i=0;i<nchests;i++)
        if(!chests[i].isOpen)
        {
            allopen=false;
            openchests[countopen++]=i;
        }
    if(allopen)
        return level;    
    // Bubble sort the chests (had issues with qsort, crap!)
    for(int i=0;i<countopen-1;i++)
        for(int j=i+1;j<countopen;j++)
            if(chests[openchests[j]].nKeys > chests[openchests[i]].nKeys && chests[openchests[i]].ktype == chests[openchests[j]].ktype)
            {
                int temp;
                temp= openchests[i];
                openchests[i] = openchests[j];
                openchests[j] = temp;
            }
    // if all chests are open, return the current solution, which is store in path
    for(int i=0;i<countopen;i++)
    {
        if(!chests[openchests[i]].isOpen)
        {
            // Copies the data forthe next iteration, if we can't find a solution
            memcpy(keyscopy, keys, sizeof(int)*MAXKEYS);
            // Not all chests are open (used only if we go through all chests and have no solution)
            allopen=false;
            // Do we have a key to open it??
            if(keys[chests[openchests[i]].ktype-1]>0)
                keys[chests[openchests[i]].ktype-1]-=1;
            else
                continue;
            chests[openchests[i]].isOpen = true;
            for(int j=0;j<MAXKEYS;j++)
                keys[j]+=chests[openchests[i]].keys[j];
            path[level]=openchests[i];
            // If we have a solution, the path size is bigger than 1
            int size = solve(keys, chests, nchests, level+1, path);
            if(size)
                return size;
            // Found no solution, restores data for next iteration
            chests[openchests[i]].isOpen=false;
            memcpy(keys, keyscopy, sizeof(int)*MAXKEYS);
        }
    }

/*    // if all chests are open, return the current solution, which is store in path
    for(int i=0;i<nchests;i++)
    {
        if(!chests[i].isOpen)
        {
            // Copies the data forthe next iteration, if we can't find a solution
            memcpy(keyscopy, keys, sizeof(int)*MAXKEYS);
            // Not all chests are open (used only if we go through all chests and have no solution)
            allopen=false;
            // Do we have a key to open it??
            if(keys[chests[i].ktype-1]>0)
                keys[chests[i].ktype-1]-=1;
            else
                continue;
            chests[i].isOpen = true;
            for(int j=0;j<MAXKEYS;j++)
                keys[j]+=chests[i].keys[j];
            path[level]=i;
            // If we have a solution, the path size is bigger than 1
            int size = solve(keys, chests, nchests, level+1, path);
            if(size)
                return size;
            // Found no solution, restores data for next iteration
            chests[i].isOpen=false;
            memcpy(keys, keyscopy, sizeof(int)*MAXKEYS);
        }
    }
    */
    
    if(allopen)
        return level;    
    return 0;
    
}

int main(int argc, char** argv) {
    Chest chests[MAXCHESTS];
    int keys[MAXKEYS];
    int cases;
    scanf("%d", &cases);
    
    for(int i=0;i<cases;i++){
        memset(keys, 0, sizeof(int)*MAXKEYS);
        int nkeys, nchests;
        scanf("%d %d", &nkeys, &nchests);
        for(int j=0;j<nkeys;j++){
            int key;
            scanf("%d", &key);
            keys[key-1]+=1;
        }
        for(int j=0;j<nchests;j++){
            scanf("%d", &chests[j].ktype);
            chests[j].isOpen = false;
            scanf("%d", &chests[j].nKeys);
            memset(chests[j].keys, 0, sizeof(int)*MAXKEYS);
            for(int k=0;k<chests[j].nKeys;k++){
                int key;
                scanf("%d", &key);
                chests[j].keys[key-1] += 1;
            }
        }
        if(!isCasePossible(keys, chests, nchests))
        {
            printf("Case #%d: IMPOSSIBLE\n", i+1);
            continue;
        }
        int path[MAXCHESTS];
        int size = solve(keys, chests, nchests, 0, path);
        if(size)
        {
            printf("Case #%d:", i+1);
            for(int j=0;j<size;j++)
                printf(" %d", path[j]+1);
            printf("\n");
        }
        else
            printf("Case #%d: IMPOSSIBLE\n", i+1);
    }
    
    
    
    return 0;
}

