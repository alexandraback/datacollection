#include <stdio.h>
#define MAX(A, B) ((A) > (B) ? (A) : (B))
#define MIN(A, B) ((A) < (B) ? (A) : (B))
#define NEGINF -10000000

int value[10000];
int dp[50][50];

int main() {
    FILE *input = fopen("energy.in", "r");
    FILE *output = fopen("energy.out", "w");

    int num_tests;
    int max_energy, regain, num_events;
    long long answer;
    int max_event, max_val;
    int i, j, k; 
    int pos, energy, spend, new;
    fscanf(input, "%d ", &num_tests);

    for (i = 0; i < num_tests; i++) {
        fscanf(input, "%d %d %d ", &max_energy, &regain, &num_events);
        for (j = 0; j < num_events; j++) {
            fscanf(input, "%d ", value+j);
        }

        for (pos = 0; pos <= num_events; pos++) {
            for (energy = 0; energy <= max_energy; energy++) {
                dp[pos][energy] = NEGINF;
            }
        }
        dp[0][max_energy] = 0;

        for (pos = 0; pos < num_events; pos++) {
            for (energy = 0; energy <= max_energy; energy++) {
                for (spend = 0; spend <= energy; spend++) {
                    new = MIN(max_energy, energy-spend+regain);
                    dp[pos+1][new] = MAX(dp[pos+1][new], dp[pos][energy] + spend * value[pos]);
                }
            }
        }

        answer = 0;
        for (energy = 0; energy <= max_energy; energy++) {
            answer = MAX(answer, dp[num_events][energy]);
        }
        fprintf(output, "Case #%d: %d\n", i+1, answer);
    }

    fclose(input); fclose(output);
}