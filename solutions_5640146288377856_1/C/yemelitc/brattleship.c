/*
    By Yemeli Tasse Cyrille
    http://yemelitc.org
    Date: 10 May 2015
*/
#include <stdio.h>

int main()
{
    int Case, T;
    int R, C, W;
    int result;

    FILE* input = stdin;
    FILE* output = stdout;

    fscanf(input, "%d", &T);
    for(Case=1; Case<=T; Case++)
    {
        fscanf(input, "%d %d %d", &R, &C, &W);

        result = W + R*(C/W) + ((C%W != 0) ? 0 : -1);
        fprintf(output, "Case #%d: %d\n", Case, result);
    }
    return 0;
}
