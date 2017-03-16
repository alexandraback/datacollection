/*
 * Google Code Jam
 *
 * Created on: 05/05/2012
 * Author: MLK
 *
 * Round 1 B 2012
 * Problem A. Safety in Numbers
 * https://code.google.com/codejam/contest/1836486/dashboard
 *
 */

#include <cstdio>
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main(int argc, char **argv) {

    FILE * input = fopen("input.txt", "r");
    int nTestCases;
    fscanf(input, "%d\n", &nTestCases);
    char lixo[10];

    // For each test case
    for (int t = 1; t <= nTestCases; t++) {
        int N; // numero de contestants
        fscanf(input, "%d", &N);
        double p[N]; // pessoas

        double soma = 0;

        for (int j = 0; j < N; j++) {
            fscanf(input, "%lf", &p[j]);
            soma += p[j];
        }

        fgets(lixo, 10, input);

        double total_points = (2.0 * soma) / N;
        double soma2 = soma;

        int i_maiores = 0;
        double pontuacao[N];

        for (int k = 0; k < N; k++) {
            if (p[k] >= total_points) {
                pontuacao[k] = 0;
                i_maiores += 1;
                soma2 -= p[k];
                total_points = (soma2 + soma) / (N - i_maiores);
            } else {
                pontuacao[k] = -1;
            }
        }

        for (int k = 0; k < N; k++) {
            if (pontuacao[k] == -1) {
                pontuacao[k] = (total_points - p[k]) / soma;
            }
        }

        cout << "Case #" << t << ": ";
        for (int j = 0; j < N; j++) {
            printf("%f ", pontuacao[j] * 100);
        }
        cout << endl;
    }
    fclose(input);
    return 0;
}

