#include <cstdio>
#include <cstring>
using namespace std;

int t, n;
bool parity[2501];

int main(void) {
    FILE * input = fopen("input.txt", "r");
    FILE * output = fopen("output.txt", "w");
    fscanf(input, "%d", &t);
    
    for (int tIter = 1; tIter <= t; tIter++) {
        memset(parity, false, sizeof(parity));
        fscanf(input, "%d", &n);
        for (int i = 0; i < 2*n*n-n; i++) {
            int buf;
            fscanf(input, "%d", &buf);
            parity[buf] = !parity[buf];
        }
        
        fprintf(output, "Case #%d:", tIter);
        for (int i = 1; i <= 2500; i++)
            if (parity[i])
                fprintf(output, " %d", i);
        fprintf(output, "\n");
    }
    fclose(input);
    fclose(output);
    return 0;
}