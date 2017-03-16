#include <iostream>
using namespace std;

int cmp(const void *a, const void *b) {
    if(*((const double *)a) < *((const double *)b)) return -1;
    if(*((const double *)a) > *((const double *)b)) return +1;
    return 0;
}

int main()
{
    int T, N;
    double Naomi[1000], Ken[1000];
    cin >> T;
    for(int t = 1; t <= T; t++) {
        cin >> N;
        for(int i = 0; i < N; i++) cin >> Naomi[i];
        for(int i = 0; i < N; i++) cin >> Ken[i];
        qsort(Naomi, N, sizeof(double), cmp);
        qsort(Ken, N, sizeof(double), cmp);
        int scoreWar = N, scoreDWar = 0;
        for(int i = 0, j = 0; j < N; j++) {
            if(Naomi[i] < Ken[j]) {
                scoreWar--;
                i++;
            }
        }
        for(int i = 0, j = 0; i < N; i++) {
            if(Naomi[i] > Ken[j]) {
                scoreDWar++;
                j++;
            }
        }
        cout << "Case #" << t << ": " << scoreDWar << ' ' << scoreWar << '\n';
    }
    cout << flush;
    return 0;
}