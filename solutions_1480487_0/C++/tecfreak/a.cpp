#include <cstdlib>
#include <iostream>

using namespace std;
int scores[101];
float aud[101];

int main(int argc, char *argv[])
{
    int t, tcs, n, i, j;
    int p, nn;
    float sum, nsum;
    float X;
    FILE* in = fopen("input.txt", "r");
    FILE* out = fopen("output.txt", "w");
    
    fscanf( in, "%d", &tcs );
    
    for (t=0; t<tcs; t++)
    {
        X = 0.0f;
        p = 0;
        nn = 0;
        nsum = 0.0f;
        fscanf(in, "%d", &n);    
        for (i=0; i<n; i++) {
            fscanf(in, "%d", &scores[i]);
            X += scores[i];
        }
        fprintf(out, "Case #%d: ", t+1);
        for (i=0; i<n; i++)
        {
            sum = 2 * X / n;
            float temp = ((sum-scores[i])/X)*100.0f;
            aud[i] = temp;
            if (temp > 0)
               p++;
            else if (temp < 0) {
               nn++;
               nsum += temp;
               aud[i] = 0.0f;
            }
        }
        
        float t2 = nsum / p;
        for (i=0; i<n; i++)
        {
            if (aud[i] > 0)
               aud[i] += t2;
            fprintf(out, "%f ", aud[i]);
        }
        
        fprintf(out, "\n");
    }
    
    fclose(in);
    fclose(out);
    return EXIT_SUCCESS;
}
