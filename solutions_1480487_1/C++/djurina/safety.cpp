#include <cstdio>

using namespace std;

int main() {
    int brtest;
    FILE *fin = fopen("safety2.in", "r");
    FILE *fout = fopen("safety2.out", "w");

    fscanf (fin, "%d", &brtest);

    for (int i=0; i<brtest; ++i) {
        int brljud, bodovi[200], ukbod=0, brbitnih;
        fscanf (fin, "%d", &brljud);
        for (int j=0; j<brljud; ++j) {
            fscanf (fin, "%d", &bodovi[j]);
            ukbod += bodovi[j];
        }
        double potrebno = (double)(ukbod * 2) / (double)brljud;
        //printf ("%d\n", potrebno);
        double publika;
        fprintf (fout, "Case #%d: ", i+1);
        brbitnih = brljud;

        double potrebno2 = ukbod * 2;
        for (int j=0; j<brljud; ++j)
            if (bodovi[j] > potrebno) {
                brbitnih--;
                potrebno2 -= (double)bodovi[j];
            }

        potrebno = (ukbod * 2) / brbitnih;
        potrebno2 /= brbitnih;

        //printf ("%lf %lf\n", potrebno, potrebno2);

        for (int j=0; j<brljud; ++j) {
            if (bodovi[j] < potrebno2) {
                publika = (double)(potrebno2 - bodovi[j]) / (double) ukbod;
                fprintf (fout, "%lf", publika*100);
            }
            else
                fprintf (fout, "0");

            if (j<brljud-1)
                fprintf (fout, " ");
        }
        fprintf (fout, "\n");
    }


    return 0;
}
