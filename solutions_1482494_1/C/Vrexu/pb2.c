#include <stdio.h>
#include <stdlib.h>

#define FILE_IN "data.in"
#define FILE_OUT "data.out"

#define DEBUG 0

/*
short int slice(short int *a, short int *aa, short int p, short int r) {
        short int i, j, x, aux;

        i = p - 1;
        j = r + 1;
        x = a[p];

        while(i < j) {
                do {
                        i++;
                }
                while (a[i] < x);

                do {
                        j--;
                }
                while (a[j] > x);

                if (i < j) {
                        aux = a[i];
                        a[i] = a[j];
                        a[j] = aux;

                        aux = aa[i];
                        aa[i] = aa[j];
                        aa[j] = aux;
                }
        }
        return j;
}

void qs(short int *a, short int *aa, short int p, short int r)
{
        short int q;

        if(p < r) {
                q = slice (a, aa, p, r);
                qs(a, aa, p, q);
                qs(a, aa, q+1, r);
        }
}
*/

int main(int argc, char **argv)
{
        FILE *file_in, *file_out;

        if(!(file_in = fopen(FILE_IN, "r")))
                return -1;

        if(!(file_out = fopen(FILE_OUT, "w")))
                return -1;

        short int t, a[1000], b[1000], aa[1000], c[1000], n;// , bb[1000];
        short int turn, index;
        int score;


        fscanf(file_in, "%hd", &t);
        for(turn = 1; turn <= t; turn++)
        {
                fscanf(file_in, "%hd", &n);
                for(index = 0; index < n; index++)
                        fscanf(file_in, "%hd%hd", a+index, b+index);

                short int i, j, k;

                for(i = 0; i < n; i++)
                {
                        aa[i] = i;
                        //bb[i] = i;
                        c[i] = 0;
                }

                short int ca[1000], caa[1000], cb[1000];//, cbb[1000];

                k = 0;
                for(i = 2001; i >= 0; i--)
                {
                        for(j = 0; j < n; j++)
                                if(a[j] == i)
                                {
                                        ca[k] = a[j];
                                        caa[k] = aa[j];
                                        cb[k] = b[j];
                //                        cbb[k] = cb[j];
                                        k++;
                                }
                }

                k = 0;
                for(i = 0; i < 2002; i++)
                {
                        for(j = 0; j < n; j++)
                                if(cb[j] == i)
                                {
                                        a[k] = ca[j];
                                        aa[k] = caa[j];
                                        b[k] = cb[j];
                //                        bb[k] = cbb[j];
                                        k++;
                                }
                }

                /*
                   qs(a, aa, 0, n - 1);
                   qs(b, bb, 0, n - 1);
                   */

#if DEBUG
                for(i = 0; i < n; i++)
                        fprintf(stdout, "%hd %hd\n", a[i], b[i]);

                fprintf(stdout, "\n");
#endif

                score = 0;
                j = 0;
                k = 0;

                while(j < n)
                {
                        if(score >= b[j])
                        {
                                //if(c[bb[j]])
                                if(c[aa[j]])
                                        score += 1;
                                else
                                        score += 2;
                                //c[bb[j]] = 1;
                                c[aa[j]] = 1;
                                j++;
                        }
                        else
                        {
                                for(i = n - 1; i >= 0; i--)
                                        if((!c[aa[i]]) && (score >= a[i]))
                                        {
                                                score += 1;
                                                c[aa[i]] = 1;
                                                break;
                                        }
                                if(i < 0)
                                        break;
                        }
                        k++;
                }

#if DEBUG
                fprintf(stdout, "j=%hd n=%hd\n", j, n);
#endif

                if(j == n)
                {
                        fprintf(file_out, "Case #%hd: %hd\n", turn, k);
#if DEBUG
                        fprintf(stdout, "Case #%hd: %hd\n", turn, k);
#endif
                }
                else
                {
                        fprintf(file_out, "Case #%hd: Too Bad\n", turn);
#if DEBUG
                        fprintf(stdout, "Case #%hd: Too Bad\n", turn);
#endif
                }
        }


        fclose(file_in);
        fclose(file_out);

        return 0;
}

