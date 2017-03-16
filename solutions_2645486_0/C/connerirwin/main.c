//
//  main.c
//  ManageYourEnergy
//
//  Created by Conner Irwin on 4/26/13.
//  Copyright (c) 2013 Conner Irwin. All rights reserved.
//

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

static int Value[10];
static int Energy, Initial, Regain, NumActivities, NetGain;
int MaxGain(int activity);

int main(int argc, const char * argv[])
{
    // Open input and output files
    FILE *input = fopen("B-small-attempt0.in.txt", "r");
    FILE *output = fopen("output.txt", "w");
    
    // If either failed, the program cannot continue
    if (!input || !output)
        return (EXIT_FAILURE);
    
    // Get the number of test cases
    int numTestCases;
    if (fscanf(input, "%d\n", &numTestCases) != 1)
        return (EXIT_FAILURE);
    
    // Iterate through each test case
    for (int testCase = 0; testCase < numTestCases; testCase++)
    {
        if (fscanf(input, "%d %d %d\n", &Initial, &Regain, &NumActivities) != 3)
            return (EXIT_FAILURE);
        
        Energy = Initial;
        NetGain = 0;
                
        for (int i = 0; i < NumActivities; i++)
        {
            if (fscanf(input, " %d", &Value[i]) != 1)
                return (EXIT_FAILURE);
        }
        
        fprintf(output, "Case #%d: %d\n", testCase+1, MaxGain(0));
    }
    
    // Finish
    fclose(input);
    fclose(output);
    
    return (EXIT_SUCCESS);
}

int MaxGain(int activity)
{
    int bestE = 0;
    int maxGain = 0;
    
    if (activity == NumActivities - 1)
        return Energy * Value[activity];
        
    for (int e = 0; e <= Energy; e++)
    {
        int oldEnergy = Energy;
        
        // Use up some energy, regain some
        Energy -= e;
        Energy += Regain;
        
        // Energy cannot exceed initial
        if (Energy > Initial)
            Energy = Initial;
        
        int pGain = Value[activity] * e;
        pGain += MaxGain(activity + 1);
                        
        if (pGain > maxGain)
        {
            maxGain = pGain;
        }
        //else
        {
            Energy = oldEnergy;
        }
    }
    
    return maxGain;
}





