//
//  main.c
//  Bullseye
//
//  Created by Conner Irwin on 4/26/13.
//  Copyright (c) 2013 Conner Irwin. All rights reserved.
//

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(int argc, const char * argv[])
{
    // Open input and output files
    FILE *input = fopen("A-small-attempt0.in.txt", "r");
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
        int paint, radius;
        int rings = 0;
        if (fscanf(input, "%d %d", &radius, &paint) != 2)
            return (EXIT_FAILURE);
                
        while (1)
        {
            int area = (radius + 1) * (radius + 1);
            area -= (radius) * (radius);
            if (paint >= area)
            {
                paint -= area;
                rings ++;
                radius += 2;
            } else
                break;
        }
        
        fprintf(output, "Case #%d: %d\n", testCase + 1, rings);
    }
    
    // Finish
    fclose(input);
    fclose(output);
    
    return (EXIT_SUCCESS);
}

