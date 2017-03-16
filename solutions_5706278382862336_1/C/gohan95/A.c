#include <stdio.h>
#include <math.h>

long long int gcd (long long int a, long long int b )
{
  long long int c;
  while ( a != 0 ) {
     c = a; a = b%a;  b = c;
  }
  return b;
}

int main()
{
    FILE *fpi, *fpo;

    fpi = fopen("A-large.in", "r");
    fpo = fopen("op.txt", "w");

    long long int t, p, q, k, i, j, no, flag, l, g;

    double t1, t2, reqd;

    fscanf(fpi, "%lld", &t);

    for (k = 1; k <= t; k++) {
        fscanf(fpi, "%lld/%lld", &p, &q);

        g = gcd(p, q);

        p /= g;
        q /= g;

        no = 0;
        i = 0;
        while (no < q) {
            i++;
            no = pow(2, i);
        }



        if (no != q)
            fprintf(fpo, "Case #%lld: impossible\n", k);


        else {
            t1 = 1;
            l = 0;
            while (1) {
            reqd = (double)p / (double)q;
            l++;

            no = pow(2, i-1);

            for (j = 0; j < no; ) {
                t2 = (double)j / (double)no;

                if ((t1 + t2) / 2 == reqd) {
                    flag = 1;
                    break;
                }

                if ((t1 + t2) / 2 > reqd) {
                    flag = 2;
                    break;
                }

                if (j == 0)
                    j++;

                else
                    j += 2;
            }

            if (flag == 1) {
                fprintf(fpo, "Case #%lld: %lld\n", k, l);
                break;
            }

            if (flag == 2)
                t1 /= 2;

            }
        }
    }

    return 0;
}

